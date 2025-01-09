#include<ginkgo/ginkgo.hpp>

#include<iostream>
#include<chrono>
#include<map>
#include<fstream>
#include<filesystem> //requires cpp17
#include <cstdlib>

size_t getNNZ(int n, int dim){
  if(dim==2) return 5*n*n - 4*n;
  if(dim==3) return 7*n*n*n - 6*n*n;
  for(int i=0; i<10000; i++){
    std::cout<< "This should not have happend, no applicable n for getNNZ in dune-evaluation.cc"<<"\n";
  }
}

// implementation using matrix_data -> uses AoS
template <class MatrixType, typename CoefficientFunction, typename BoundaryTypeFunction, class ExecutorType>
std::unique_ptr<MatrixType> diffusion_matrix_optimizedCSR(const size_t n, const size_t d,
                                              CoefficientFunction diffusion_coefficient,
                                              BoundaryTypeFunction dirichlet_boundary,
                                              ExecutorType exec)
{
  // relevant types
  // using MatrixEntry = double;
  using mtx = MatrixType;

  // prepare grid information
  std::vector<std::size_t> sizes(d + 1, 1);
  for (int i = 1; i <= d; ++i)
    sizes[i] = sizes[i - 1] * n; /// sizes={1,n,n^2,n^3,...,n^d}
  double mesh_size = 1.0 / n;
  int N = sizes[d];

  // create matrix entries
  auto GKOdim = gko::dim<2>(N);
  gko::matrix_data<> mtx_data{GKOdim};
  for (std::size_t index = 0; index < sizes[d]; index++) /// each grid cell
  {
    // create multiindex from row number                    ///fancy way of doing 3(=d) for loops over n
    std::vector<std::size_t> multiindex(d, 0);
    auto copiedindex = index;
    for (int i = d - 1; i >= 0; i--)
    {
      multiindex[i] = copiedindex / sizes[i]; /// implicit size_t cast? Yes: returns only how ofter size fites into cindex
      copiedindex = copiedindex % sizes[i];   /// basically returns the (missing) rest of the checking above
    }

    // std::cout << "index=" << index;
    // for (int i=0; i<d; ++i) std::cout << " " << multiindex[i];
    // std::cout << std::endl;

    // the current cell
    std::vector<double> center_position(d); /// scaled up multigrid/cell-position
    for (int i = 0; i < d; ++i)
      center_position[i] = multiindex[i] * mesh_size;
    double center_coefficient = diffusion_coefficient(center_position);
    double center_matrix_entry = 0.0;

    // loop over all neighbors
    for (int i = 0; i < d; i++)
    {
      // down neighbor
      if (multiindex[i] > 0)
      {
        // we have a neighbor cell
        std::vector<double> neighbor_position(center_position);
        neighbor_position[i] -= mesh_size;
        double neighbor_coefficient = diffusion_coefficient(neighbor_position);
        double harmonic_average = 2.0 / ((1.0 / neighbor_coefficient) + (1.0 / center_coefficient));
        // pA->entry(index,index-sizes[i]) = -harmonic_average;
        mtx_data.nonzeros.emplace_back(index, index - sizes[i], -harmonic_average); ///@changed
        center_matrix_entry += harmonic_average;
      }
      else
      {
        // current cell is on the boundary in this direction
        std::vector<double> neighbor_position(center_position);
        neighbor_position[i] = 0.0;
        if (dirichlet_boundary(neighbor_position))
          center_matrix_entry += center_coefficient * 2.0;
      }

      // up neighbor
      if (multiindex[i] < n - 1)
      {
        // we have a neighbor cell
        std::vector<double> neighbor_position(center_position);
        neighbor_position[i] += mesh_size;
        double neighbor_coefficient = diffusion_coefficient(neighbor_position);
        double harmonic_average = 2.0 / ((1.0 / neighbor_coefficient) + (1.0 / center_coefficient));
        // pA->entry(index,index+sizes[i]) = -harmonic_average;
        mtx_data.nonzeros.emplace_back(index, index + sizes[i], -harmonic_average); ///@changed
        center_matrix_entry += harmonic_average;
      }
      else
      {
        // current cell is on the boundary in this direction
        std::vector<double> neighbor_position(center_position);
        neighbor_position[i] = 1.0;
        if (dirichlet_boundary(neighbor_position))
          center_matrix_entry += center_coefficient * 2.0;
      }
    }

    // finally the diagonal entry
    mtx_data.nonzeros.emplace_back(index, index, center_matrix_entry); ///@changed
  }
  // create matrix from data
  mtx_data.sort_row_major();
  auto pA = mtx::create(exec,GKOdim,getNNZ(n,d));
  pA->read(mtx_data);

  return pA;
}

// implementation using matrix_data -> uses AoS
template <class MatrixType, typename CoefficientFunction, typename BoundaryTypeFunction, class ExecutorType>
std::unique_ptr<MatrixType> diffusion_matrix_md(const size_t n, const size_t d,
                                              CoefficientFunction diffusion_coefficient,
                                              BoundaryTypeFunction dirichlet_boundary,
                                              ExecutorType exec)
{
  // relevant types
  // using MatrixEntry = double;
  using mtx = MatrixType;

  // prepare grid information
  std::vector<std::size_t> sizes(d + 1, 1);
  for (int i = 1; i <= d; ++i)
    sizes[i] = sizes[i - 1] * n; /// sizes={1,n,n^2,n^3,...,n^d}
  double mesh_size = 1.0 / n;
  int N = sizes[d];

  // create matrix entries
  // gko::matrix_data<double,size_t> mtx_data{gko::dim<2,size_t>(N,N)};     //temporary COO representation (!might be unefficient) @changed
  gko::matrix_data<> mtx_data{gko::dim<2>(N)};           ///@changed @perfomance->passing size_t as template parameter to dim significant slowdown (why??)
  //gko::matrix_data<> mtx_data{gko::dim<2>{N}}; //tested in 400-4 dataset
  for (std::size_t index = 0; index < sizes[d]; index++) /// each grid cell
  {
    // create multiindex from row number                    ///fancy way of doing 3(=d) for loops over n
    std::vector<std::size_t> multiindex(d, 0);
    auto copiedindex = index;
    for (int i = d - 1; i >= 0; i--)
    {                                         /// start from the back!
      multiindex[i] = copiedindex / sizes[i]; /// implicit size_t cast? Yes: returns only how ofter size fites into cindex
      copiedindex = copiedindex % sizes[i];   /// basically returns the (missing) rest of the checking above
    }

    // std::cout << "index=" << index;
    // for (int i=0; i<d; ++i) std::cout << " " << multiindex[i];
    // std::cout << std::endl;

    // the current cell
    std::vector<double> center_position(d); /// scaled up multigrid/cell-position
    for (int i = 0; i < d; ++i)
      center_position[i] = multiindex[i] * mesh_size;
    double center_coefficient = diffusion_coefficient(center_position);
    double center_matrix_entry = 0.0;

    // loop over all neighbors
    for (int i = 0; i < d; i++)
    {
      // down neighbor
      if (multiindex[i] > 0)
      {
        // we have a neighbor cell
        std::vector<double> neighbor_position(center_position);
        neighbor_position[i] -= mesh_size;
        double neighbor_coefficient = diffusion_coefficient(neighbor_position);
        double harmonic_average = 2.0 / ((1.0 / neighbor_coefficient) + (1.0 / center_coefficient));
        // pA->entry(index,index-sizes[i]) = -harmonic_average;
        mtx_data.nonzeros.emplace_back(index, index - sizes[i], -harmonic_average); ///@changed
        center_matrix_entry += harmonic_average;
      }
      else
      {
        // current cell is on the boundary in this direction
        std::vector<double> neighbor_position(center_position);
        neighbor_position[i] = 0.0;
        if (dirichlet_boundary(neighbor_position))
          center_matrix_entry += center_coefficient * 2.0;
      }

      // up neighbor
      if (multiindex[i] < n - 1)
      {
        // we have a neighbor cell
        std::vector<double> neighbor_position(center_position);
        neighbor_position[i] += mesh_size;
        double neighbor_coefficient = diffusion_coefficient(neighbor_position);
        double harmonic_average = 2.0 / ((1.0 / neighbor_coefficient) + (1.0 / center_coefficient));
        // pA->entry(index,index+sizes[i]) = -harmonic_average;
        mtx_data.nonzeros.emplace_back(index, index + sizes[i], -harmonic_average); ///@changed
        center_matrix_entry += harmonic_average;
      }
      else
      {
        // current cell is on the boundary in this direction
        std::vector<double> neighbor_position(center_position);
        neighbor_position[i] = 1.0;
        if (dirichlet_boundary(neighbor_position))
          center_matrix_entry += center_coefficient * 2.0;
      }
    }

    // finally the diagonal entry
    // pA->entry(index,index) = center_matrix_entry;     //# easyer if more positive, time would be added here
    mtx_data.nonzeros.emplace_back(index, index, center_matrix_entry); ///@changed
  }
  // create matrix from data
  // auto stats = pA->compress();
  auto pA = mtx::create(exec); ///@optimize (line below included)
  pA->read(mtx_data);

  return pA;
}

// implementation using matrix_assembly_data -> uses unordered_map
template <class MatrixType, typename CoefficientFunction, typename BoundaryTypeFunction, class ExecutorType>
std::unique_ptr<MatrixType> diffusion_matrix_mad(const size_t n, const size_t d,
                                             CoefficientFunction diffusion_coefficient,
                                             BoundaryTypeFunction dirichlet_boundary,
                                             ExecutorType exec)
{
  // relevant types
  // using MatrixEntry = double;
  using mtx = MatrixType;

  // prepare grid information
  std::vector<std::size_t> sizes(d + 1, 1);
  for (int i = 1; i <= d; ++i)
    sizes[i] = sizes[i - 1] * n;
  double mesh_size = 1.0 / n;
  int N = sizes[d];

  // create matrix entries
  // gko::matrix_assembly_data<> mtx_assembly_data{gko::dim<2>{N}};              ///@changed @perfomance->passing size_t as template parameter to dim significant slowdown (why??)
  auto mtx_assembly_data = gko::matrix_assembly_data<>{gko::dim<2>(N)};
  // auto mtx_assembly_data = gko::matrix_assembly_data<>{};
  for (std::size_t index = 0; index < sizes[d]; index++)
  {
    // create multiindex from row number
    std::vector<std::size_t> multiindex(d, 0);
    auto copiedindex = index;
    for (int i = d - 1; i >= 0; i--)
    {
      multiindex[i] = copiedindex / sizes[i];
      copiedindex = copiedindex % sizes[i];
    }

    // std::cout << "index=" << index;
    // for (int i=0; i<d; ++i) std::cout << " " << multiindex[i];
    // std::cout << std::endl;

    // the current cell
    std::vector<double> center_position(d);
    for (int i = 0; i < d; ++i)
      center_position[i] = multiindex[i] * mesh_size;
    double center_coefficient = diffusion_coefficient(center_position);
    double center_matrix_entry = 0.0;

    // loop over all neighbors
    for (int i = 0; i < d; i++)
    {
      // down neighbor
      if (multiindex[i] > 0)
      {
        // we have a neighbor cell
        std::vector<double> neighbor_position(center_position);
        neighbor_position[i] -= mesh_size;
        double neighbor_coefficient = diffusion_coefficient(neighbor_position);
        double harmonic_average = 2.0 / ((1.0 / neighbor_coefficient) + (1.0 / center_coefficient));
        // pA->entry(index,index-sizes[i]) = -harmonic_average;
        // mtx_data.nonzeros.emplace_back(index,index-sizes[i], -harmonic_average);                ///@changed
        mtx_assembly_data.set_value(index, index - sizes[i], -harmonic_average);
        center_matrix_entry += harmonic_average;
      }
      else
      {
        // current cell is on the boundary in this direction
        std::vector<double> neighbor_position(center_position);
        neighbor_position[i] = 0.0;
        if (dirichlet_boundary(neighbor_position))
          center_matrix_entry += center_coefficient * 2.0;
      }

      // up neighbor
      if (multiindex[i] < n - 1)
      {
        // we have a neighbor cell
        std::vector<double> neighbor_position(center_position);
        neighbor_position[i] += mesh_size;
        double neighbor_coefficient = diffusion_coefficient(neighbor_position);
        double harmonic_average = 2.0 / ((1.0 / neighbor_coefficient) + (1.0 / center_coefficient));
        // pA->entry(index,index+sizes[i]) = -harmonic_average;
        // mtx_data.nonzeros.emplace_back(index,index+sizes[i], -harmonic_average);                ///@changed
        mtx_assembly_data.set_value(index, index + sizes[i], -harmonic_average);

        center_matrix_entry += harmonic_average;
      }
      else
      {
        // current cell is on the boundary in this direction
        std::vector<double> neighbor_position(center_position);
        neighbor_position[i] = 1.0;
        if (dirichlet_boundary(neighbor_position))
          center_matrix_entry += center_coefficient * 2.0;
      }
    }

    // finally the diagonal entry
    // mtx_data.nonzeros.emplace_back(index,index, center_matrix_entry);                           ///@changed
    mtx_assembly_data.set_value(index, index, center_matrix_entry);
  }
  // create matrix from data
  // size_t nnz = (2*d+1)*N;
  auto pA = mtx::create(exec); ///@optimize (line below included)
  pA->read(mtx_assembly_data.get_ordered_data());

  return pA;
}


// returns time_to_generate and time_to_SpMV
template <class MatrixType, typename CoefficientFunction, typename BoundaryTypeFunction>
void executeRound(
                                             const size_t n, const size_t dim, const size_t max_iters, 
                                             const size_t min_reps, size_t min_time, std::string filename,
                                             CoefficientFunction diffusion_coefficient,
                                             BoundaryTypeFunction dirichlet_boundary,
                                             std::string exec_string,
                                             std::map<std::string, std::function<std::shared_ptr<gko::Executor>()>>& exec_map,
                                             std::string assebly_structure_string)
{
  // set up
  using vec = gko::matrix::Dense<double>;
  const auto exec = exec_map.at(exec_string)();
  size_t N = 1;
  for (int i = 0; i < dim; i++) N *= n;
  // set function to generate with
  using GeneratingFunction = std::unique_ptr<MatrixType>(*)(size_t, size_t, CoefficientFunction, BoundaryTypeFunction, decltype(exec));
  GeneratingFunction generate_matrix = nullptr;
  if(assebly_structure_string=="md") generate_matrix = diffusion_matrix_md<MatrixType>;
  else if (assebly_structure_string=="mad") generate_matrix = diffusion_matrix_mad<MatrixType>;
  else if (assebly_structure_string=="optimizedCSR") generate_matrix=diffusion_matrix_optimizedCSR<MatrixType>;
  else throw std::invalid_argument("Invalid argument for assebly_structure_string");


// assembl matrix A
  std::cout<< "Generating with "<<std::endl;
  std::shared_ptr<MatrixType> pA = nullptr;
  auto time_start = std::chrono::high_resolution_clock::now();
  auto time_stop = time_start;
  auto duration = time_stop - time_start;
  auto duration_cast = std::chrono::duration_cast<std::chrono::nanoseconds>(duration).count();
  auto duration_sum = duration_cast;
  long rep = min_reps;
  long finished_reps = 0;
  std::string foldername = "data/"+filename+"/";
  std::filesystem::create_directories(foldername);
  std::ofstream outfile_gen(foldername+"gen.txt", std::ios::app);
  while (duration_sum < min_time && rep < 1000000000)
  {
    for (long k = 0; k < rep; k++){
      // synchronize before timing
      exec->synchronize();
      time_start = std::chrono::high_resolution_clock::now();
      pA = generate_matrix(n, dim, diffusion_coefficient, dirichlet_boundary, exec);
      // synchronize before timing
      exec->synchronize();
      time_stop = std::chrono::high_resolution_clock::now();
      duration = time_stop - time_start;
      duration_cast = std::chrono::duration_cast<std::chrono::nanoseconds>(duration).count();
      outfile_gen 
        << n << " "
        << dim << " "
        << k+finished_reps << " "
        << duration_cast << "\n";
      duration_sum += duration_cast;
    }
    outfile_gen.flush();
    finished_reps +=rep;
    std::cout << "(Ginkgo) Gen: n="<<n<<" dim="<<dim<<" finished_reps=" << finished_reps << " duration_sum in ms=" << duration_sum/1000000 << std::endl;
    rep *= 2;
  }
  outfile_gen.close();
  
  // store matrix
  if(n<=30){
      std::string foldername = "result-verification/A/";
      std::filesystem::create_directories(foldername);
      std::string filename_A = foldername+std::to_string(n)+"_"+std::to_string(dim)+"_A_"+filename+".mtx";
      std::ofstream outfilestream(filename_A);
      gko::write(outfilestream,pA);
      std::cout<< "stored matrix to "+filename_A<<std::endl;
  }

// Calculate SpMV
  // initialize vectors
  auto x = vec::create(exec, gko::dim<2, size_t>(N, 1));
  auto y = vec::create(exec, gko::dim<2, size_t>(N, 1));

  gko::matrix_data<> vec_data{gko::dim<2>(N, 1)};
  for(size_t i=0; i<N;i++) vec_data.nonzeros.emplace_back(i,0,1.0);
  x->read(vec_data);

  std::cout<< "SpMV calculating ..."<<std::endl;
  time_start = std::chrono::high_resolution_clock::now();
  time_stop = time_start;
  duration = time_stop - time_start;
  duration_cast = std::chrono::duration_cast<std::chrono::nanoseconds>(duration).count();
  duration_sum = duration_cast;
  rep = min_reps;
  finished_reps = 0;
  foldername = "data/"+filename+"/";
  std::filesystem::create_directories(foldername);
  std::ofstream outfile_SpMV(foldername+"SpMV.txt", std::ios::app);
  while (duration_sum < min_time && rep < 1000000000)
  {
    for (long k = 0; k < rep; k++){
      // synchronize before timing
      exec->synchronize();
      time_start = std::chrono::high_resolution_clock::now();
      pA->apply(x, y);  
      // synchronize before timing
      exec->synchronize();
      time_stop = std::chrono::high_resolution_clock::now();
      duration = time_stop - time_start;
      duration_cast = std::chrono::duration_cast<std::chrono::nanoseconds>(duration).count();
      outfile_SpMV 
        << n << " "
        << dim << " "
        << k+finished_reps << " "
        << duration_cast << "\n";
      duration_sum += duration_cast;
    }
    outfile_SpMV.flush();
    finished_reps +=rep;
    std::cout << "(Ginkgo) SpMV: n="<<n<<" dim="<<dim<<" finished_reps=" << finished_reps << " duration_sum in ms=" << duration_sum/1000000 << std::endl;
    rep *= 2;
  }
    outfile_SpMV.close();
  //std::cout << "last y:  " << std::endl;
  //gko::write(std::cout, y);

  // store SpMV result y
  if(n<=30){
      std::string foldername = "result-verification/y/";
      std::filesystem::create_directories(foldername);
      std::string filename_y = foldername+std::to_string(n)+"_"+std::to_string(dim)+"_y_"+filename+".mtx";
      std::ofstream outfilestream(filename_y);
      gko::write(outfilestream,y);
      std::cout<< "stored SpMV result y to "+filename_y<<std::endl;
  }

  auto time_to_CG = std::chrono::duration_cast<std::chrono::nanoseconds>(time_stop - time_stop);

// build CG_jac
  using cg = gko::solver::Cg<>;
  using bj = gko::preconditioner::Jacobi<>;
  auto solver_factory_CG_jac = cg::build()
                             .with_criteria(gko::stop::Iteration::build()
                                                .with_max_iters(max_iters)
                                                .on(exec))
                             .with_preconditioner(bj::build()
                                                .with_max_block_size(1u)
                                                .on(exec))
                             .on(exec);
  // build Solver
  auto solver_CG_jac = solver_factory_CG_jac->generate(pA);

// apply CG solver
  // set both rhs and initial iterate x_k to 1
  auto rhs = gko::clone(x);
  auto x_k = gko::clone(x);
  
  //experiment
  std::cout<< "CG_jac calculating ..."<<std::endl;
  time_start = std::chrono::high_resolution_clock::now();
  time_stop = time_start;
  duration = time_stop - time_start;
  duration_cast = std::chrono::duration_cast<std::chrono::nanoseconds>(duration).count();
  duration_sum = duration_cast;
  rep = min_reps;
  finished_reps = 0;
  foldername = "data/"+filename+"/";
  std::filesystem::create_directories(foldername);
  std::ofstream outfile_CGjac(foldername+"CGjac.txt", std::ios::app);
  while (duration_sum < min_time && rep < 1000000000)
  {
    for (long k = 0; k < rep; k++){
      //auto rhs = gko::clone(x); //unlike with DUNE not necessary 
      x_k = gko::clone(x);
      exec->synchronize();
      time_start = std::chrono::high_resolution_clock::now();
      solver_CG_jac->apply(rhs, x_k);
      exec->synchronize();
      time_stop = std::chrono::high_resolution_clock::now();
      duration = time_stop - time_start;
      duration_cast = std::chrono::duration_cast<std::chrono::nanoseconds>(duration).count();
      outfile_CGjac 
        << n << " "
        << dim << " "
        << k+finished_reps << " "
        << duration_cast << "\n";
      duration_sum += duration_cast;
    }
    outfile_CGjac.flush();
    finished_reps +=rep;
    std::cout << "(Ginkgo) CG_jac: n="<<n<<" dim="<<dim<<" finished_reps=" << finished_reps <<" duration_sum in ms=" << duration_sum/1000000 << std::endl;
    rep *= 2;
  }
  outfile_CGjac.close();
  
  // store CG result after max_iters iterations
  if(n<=30){
      std::string foldername = "result-verification/x_k_jac/";
      std::filesystem::create_directories(foldername);
      std::string filename_x_k_jac = foldername+std::to_string(n)+"_"+std::to_string(dim)+"_x_k_jac_"+filename+".mtx";
      std::ofstream outfilestream(filename_x_k_jac);
      gko::write(outfilestream,x_k);
      std::cout<< "CG result x_k after "+std::to_string(max_iters)+" iterations to "+filename_x_k_jac<<std::endl;
  }

// build CG_ILU
  using ilu = gko::preconditioner::Ilu<>;
  auto solver_factory_CG_ILU = cg::build()
                             .with_criteria(gko::stop::Iteration::build()
                                                .with_max_iters(max_iters)
                                                .on(exec))
                             .with_preconditioner(ilu::build()
                                                .on(exec))
                             .on(exec);
  auto solver_CG_ILU = solver_factory_CG_ILU->generate(pA);

// apply CG-ILU
  // set both rhs and initial iterate x_k to 1
  rhs = gko::clone(x);
  x_k = gko::clone(x);
  
  //experiment
  std::cout<< "CG_ILU calculating ..."<<std::endl;
  time_start = std::chrono::high_resolution_clock::now();
  time_stop = time_start;
  duration = time_stop - time_start;
  duration_cast = std::chrono::duration_cast<std::chrono::nanoseconds>(duration).count();
  duration_sum = duration_cast;
  rep = min_reps;
  finished_reps = 0;
  foldername = "data/"+filename+"/";
  std::filesystem::create_directories(foldername);
  std::ofstream outfile_CG_ILU(foldername+"CGilu.txt", std::ios::app);
  while (duration_sum < min_time && rep < 1000000000)
  {
    for (long k = 0; k < rep; k++){
      //auto rhs = gko::clone(x); //unlike with DUNE not necessary 
      x_k = gko::clone(x);
      exec->synchronize();
      time_start = std::chrono::high_resolution_clock::now();
      solver_CG_ILU->apply(rhs, x_k);
      exec->synchronize();
      time_stop = std::chrono::high_resolution_clock::now();
      duration = time_stop - time_start;
      duration_cast = std::chrono::duration_cast<std::chrono::nanoseconds>(duration).count();
      outfile_CG_ILU 
        << n << " "
        << dim << " "
        << k+finished_reps << " "
        << duration_cast << "\n";
      duration_sum += duration_cast;
    }
    outfile_CG_ILU.flush();
    finished_reps +=rep;
    std::cout << "(Ginkgo) CG_ILU: n="<<n<<" dim="<<dim<<" finished_reps=" << finished_reps <<" duration_sum in ms=" << duration_sum/1000000 << std::endl;
    rep *= 2;
  }
  outfile_CG_ILU.close();

  // store CG result after max_iters iterations
  if(n<=30){
    std::string foldername = "result-verification/x_k_ilu/";
    std::filesystem::create_directories(foldername);
    std::string filename_x_k_ilu = foldername+std::to_string(n)+"_"+std::to_string(dim)+"_x_k_ilu_"+filename+".mtx";
    std::ofstream outfilestream(filename_x_k_ilu);
    gko::write(outfilestream,x_k);
    std::cout<< "CG result x_k after "+std::to_string(max_iters)+" iterations to "+filename_x_k_ilu<<std::endl;
  }

}


int main(int argc, char* argv[])
{
  std::cout << "-------------------------------STARTING:ginkgo-evaluation-------------------------------------------" << std::endl;
  // input handling
  if (argc!=10) {
    std::cout<<argv[0]<< ": Wrong number of Arguments: "<<argc<<std::endl;
    std::cout<<"please give arguements: n_lowerBound n_upperBound dim min_reps min_time max_iters assembly_datastructure executor format"<<std::endl;
    std::cout<<"\n n_lowerBound:            evaluate starting with this n "
              <<"\n n_upperBound:           evaluate up to this n "
              <<"\n dim:                    evaluate for this dimension "
              <<"\n min_reps:               minimum repitions per experiment "
              <<"\n min_time:               minimum time to run each experiment "
              <<"\n max_iters:              stoping criterion for CG - stopping after max_iters iterations "
              <<"\n assembly_datastrucure:  for usage of matrix_data or matrix_assembly_data (md,mad,optimizedCSR) "
              <<"\n executor:               what ginkgo executor to use (ref,omp,cuda,dpcpp,hip) "
              <<"\n format:                 what matrix format to use (csr,ell,coo,sellp,hybrid,sparsitycsr,dense) \n "<<std::endl;

    return 1;
  }

  // set up experiment
  const size_t        n_lowerBound = std::stoi(argv[1]);
  const size_t        n_upperBound = std::stoi(argv[2]);
  const size_t        dim = std::stoi(argv[3]);
  const size_t        min_reps = std::stoi(argv[4]);
  const size_t        min_time = std::stoi(argv[5]);
  const size_t        max_iters = std::stoi(argv[6]);
  const std::string   assebly_structure_string = argv[7];
  const std::string   exec_string = argv[8];
  const std::string   mtx_string = argv[9];
 
  std::string         output_filename = "gko_"+assebly_structure_string+"_"+exec_string+"_"+mtx_string+"_" \
                                        +std::to_string(n_lowerBound)+"-"+std::to_string(n_upperBound)+"n_CG"+std::to_string(max_iters)+"_" \
                                        +std::to_string(min_reps)+"r_"+std::to_string(dim)+"d";
 

  std::map<std::string, std::function<std::shared_ptr<gko::Executor>()>>
        exec_map{
            {"omp", [] { return gko::OmpExecutor::create(); }},
            {"1omp", [] { putenv((char*)"OMP_NUM_THREADS=1"); /*setenv((char*)"OMP_NUM_THREADS", (char*)"1",1);*/ return gko::OmpExecutor::create(); }},
            {"cuda",[] { return gko::CudaExecutor::create(0,gko::OmpExecutor::create()); }},
            {"hip",[] { return gko::HipExecutor::create(0, gko::OmpExecutor::create()); }},
            {"dpcpp",[] { return gko::DpcppExecutor::create(0,gko::OmpExecutor::create()); }},
            {"ref", [] { return gko::ReferenceExecutor::create(); }}};

  auto diffusion_coefficient = [](const std::vector<double> &x) { return 1.0; };
  auto dirichlet_boundary = [](const std::vector<double> &x) { return true; };
  std::map<
    std::string, 
    std::function<void(size_t, size_t, size_t, size_t, size_t, std::string)>>
    execute_round_map{
      {"csr", [&] (size_t n, size_t dim, size_t max_iters, size_t min_reps, size_t min_time, std::string filename)
        { return executeRound<gko::matrix::Csr<>>(n,dim,max_iters,min_reps,min_time,filename,diffusion_coefficient,dirichlet_boundary,exec_string,exec_map,assebly_structure_string); }},
      {"ell", [&] (size_t n, size_t dim, size_t max_iters, size_t min_reps, size_t min_time, std::string filename)
        { return executeRound<gko::matrix::Ell<>>(n,dim,max_iters,min_reps,min_time,filename,diffusion_coefficient,dirichlet_boundary,exec_string,exec_map,assebly_structure_string); }},
      {"sellp", [&] (size_t n, size_t dim, size_t max_iters, size_t min_reps, size_t min_time, std::string filename)
        { return executeRound<gko::matrix::Sellp<>>(n,dim,max_iters,min_reps,min_time,filename,diffusion_coefficient,dirichlet_boundary,exec_string,exec_map,assebly_structure_string); }},
      {"hybrid", [&] (size_t n, size_t dim, size_t max_iters, size_t min_reps, size_t min_time, std::string filename)
        { return executeRound<gko::matrix::Hybrid<>>(n,dim,max_iters,min_reps,min_time,filename,diffusion_coefficient,dirichlet_boundary,exec_string,exec_map,assebly_structure_string); }},
      {"coo", [&] (size_t n, size_t dim, size_t max_iters, size_t min_reps, size_t min_time, std::string filename)
        { return executeRound<gko::matrix::Coo<>>(n,dim,max_iters,min_reps,min_time,filename,diffusion_coefficient,dirichlet_boundary,exec_string,exec_map,assebly_structure_string); }}};



  std::cout<<argv[0]<< ": Computing all matrixes with d=2 and d=3, with n="<<n_lowerBound<<" to "<<n_upperBound<<std::endl;
  std::cout<<argv[0]<< ": Computing every variation at least "<<min_reps<<" times"<<std::endl;
  std::cout<<argv[0]<< ": Configuration: "<<assebly_structure_string<<" "<< exec_string<< " "<< mtx_string<<std::endl;
  std::cout<<argv[0]<< ": Outputting to: "<< output_filename<<std::endl;


  std::cout << "-------------------------------running Experiment---------------------------------------------------" << std::endl;

  for(size_t n=n_lowerBound; n<=n_upperBound; n++){
    // generate data
    execute_round_map.at(mtx_string)(n,dim,max_iters,min_reps,min_time,output_filename);
  }

  std::cout << "-------------------------------FINISHED:ginkgo-evaluation-------------------------------------------" << std::endl;
  return 0;
}

/*// Ginkgo Hello World
    using Mtx = gko::matrix::Csr<double, int>;
    using Vec = gko::matrix::Dense<double>;
    auto exec = gko::ReferenceExecutor::create();
    auto mtx = gko::initialize<Mtx>({{0.0, 1.0}, {1.0, 0.0}}, exec);
    auto vec = gko::initialize<Vec>({2.0, 3.0}, exec);
    auto result = vec->clone();
    mtx->apply(vec, result);
    gko::write(std::cout, result);
*/
/*
 Ginkgo Matrix assembly
    using Mtx = gko::matrix::Csr<double, int>;
    using Vec = gko::matrix::Dense<double>;
    using dim = gko::dim<2>;
    using matrix_data = gko::matrix_data<double, int>;
    auto exec = gko::ReferenceExecutor::create();
    matrix_data data{dim{10, 10}};
    auto mtx = Mtx::create(exec);
    auto x = Vec::create(exec, dim{10, 1});
    auto y = Vec::create(exec, dim{10, 1});
    for (int row = 0; row < 10; row++) {
        data.nonzeros.emplace_back(row, row, 2.0);
        data.nonzeros.emplace_back(row, (row + 1) % 10, -1.0);
        data.nonzeros.emplace_back(row, (row + 9) % 10, -1.0);
        x->at(row, 0) = 1.0; // only works on CPU executors
    }
    mtx->read(data);
    mtx->apply(x, y);
    gko::write(std::cout, y);
*/
