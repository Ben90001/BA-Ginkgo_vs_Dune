#include<ginkgo/ginkgo.hpp>

#include<iostream>
#include<chrono>
#include<map>
#include<fstream>
#include<filesystem> //requires cpp17

// implementation using matrix_data -> uses AoS
template <class MatrixType, typename CoefficientFunction, typename BoundaryTypeFunction, class ExecutorType>
std::unique_ptr<MatrixType> diffusion_matrix_cpu(const size_t n, const size_t d,
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
    sizes[i] = sizes[i - 1] * n; /// sizes={1,n,n^2,n^3,...,n^d} => time needed for total concentration equilibirum distance^d
  double mesh_size = 1.0 / n;
  int N = sizes[d];

  // create matrix entries
  // gko::matrix_data<double,size_t> mtx_data{gko::dim<2,size_t>(N,N)};     //temporary COO representation (!might be unefficient) @changed
  gko::matrix_data<> mtx_data{gko::dim<2>(N)};           ///@changed @perfomance->passing size_t as template parameter to dim significant slowdown (why??)
  //gko::matrix_data<> mtx_data{gko::dim<2>{N}}; //tested in 400-4 dataset
  for (std::size_t index = 0; index < sizes[d]; index++) /// each grid cell
  {
    // create multiindex from row number                    ///fancy way of doing 3 for loops over n -> more powerful: works for all d
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
std::unique_ptr<MatrixType> diffusion_matrix_gpu(const size_t n, const size_t d,
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
std::pair<std::chrono::nanoseconds,std::chrono::nanoseconds> executeRound(const size_t n, const size_t d, size_t round, std::string filename,
                                             CoefficientFunction diffusion_coefficient,
                                             BoundaryTypeFunction dirichlet_boundary,
                                             std::string exec_string,
                                             std::map<std::string, std::function<std::shared_ptr<gko::Executor>()>>& exec_map,
                                             std::string device_string)
{
  // set up
  using vec = gko::matrix::Dense<double>;
  const auto exec = exec_map.at(exec_string)();
  size_t N = 1;
  for (int i = 0; i < d; i++) N *= n;
  // set function to generate with
  using GeneratingFunction = std::unique_ptr<MatrixType>(*)(size_t, size_t, CoefficientFunction, BoundaryTypeFunction, decltype(exec));
  GeneratingFunction generate_matrix = nullptr;
  if(device_string=="cpu") generate_matrix = diffusion_matrix_cpu<MatrixType>;
  else if (device_string=="gpu") generate_matrix = diffusion_matrix_gpu<MatrixType>;
  else throw std::invalid_argument("Invalid argument for device_string");

// assembl matrix
  // synchronize before timing
  exec->synchronize();
  auto time_start = std::chrono::steady_clock::now();
  auto pA = gko::share(generate_matrix(n, d, diffusion_coefficient, dirichlet_boundary, exec));
  // synchronize before timing
  exec->synchronize();
  auto time_stop = std::chrono::steady_clock::now();
  auto time_to_generate = std::chrono::duration_cast<std::chrono::nanoseconds>(time_stop - time_start);
  std::cout << "(Ginkgo-"+exec_string+")Generation Time n="<<n<<",d="<<d<<" : " << time_to_generate.count() / 1000000 << "." << time_to_generate.count() % 1000000 << "ms" << std::endl;
  
  // store matrix
  if(round == 1){
      std::string foldername = "result-verification/A/";
      std::filesystem::create_directories(foldername);
      std::string filename_A = foldername+std::to_string(n)+"_"+std::to_string(d)+"_A_"+filename+".mtx";
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
  //std::cout<<"x upon reading its non defined but declared input data:"<<std::endl;
  //gko::write(std::cout,x);

  // synchronize before timing
  exec->synchronize();
  time_start = std::chrono::steady_clock::now();
  pA->apply(x, y);
  // synchronize before timing
  exec->synchronize();
  time_stop = std::chrono::steady_clock::now();
  auto time_to_SpMV = std::chrono::duration_cast<std::chrono::nanoseconds>(time_stop - time_start);
  std::cout << "Time it took to apply A on x:  " << time_to_SpMV.count() / 1000000 << "." << time_to_SpMV.count() % 1000000 << "ms" << std::endl;
  //std::cout << "y:  " << std::endl;
  //gko::write(std::cout, y);

  // store SpMV result y
  if(round == 1){
      std::string foldername = "result-verification/y/";
      std::filesystem::create_directories(foldername);
      std::string filename_y = foldername+std::to_string(n)+"_"+std::to_string(d)+"_y_"+filename+".mtx";
      std::ofstream outfilestream(filename_y);
      gko::write(outfilestream,y);
      std::cout<< "stored SpMV result y to "+filename_y<<std::endl;
  }

  return std::pair<std::chrono::nanoseconds,std::chrono::nanoseconds>(time_to_generate,time_to_SpMV);
}



int main(int argc, char* argv[])
{
  std::cout << "-------------------------------STARTING:ginkgo-evaluation-------------------------------------------" << std::endl;
  // input handling
  if (argc!=8) {
    std::cout<<argv[0]<< ": Wrong number of Arguments: "<<argc<<std::endl;
    std::cout<<"please give arguements: n_lowerBound n_upperBound rounds interval device executor format"<<std::endl;
    std::cout<<"\n n_lowerBound:    evaluate starting with this n "
              <<"\n n_upperBound:   evaluate up to this n "
              <<"\n rounds:         repeat every variation this often "
              <<"\n interval:       =i only evaluate every i-th value for n "
              <<"\n device:         for usage of matrix_data or matrix_assembly_data (cpu,gpu) "
              <<"\n executor:       what ginkgo executor to use (ref,omp,cuda,dpcpp,hip) "
              <<"\n format:         what matrix format to use (csr,ell,coo,sellp,hybrid,sparsitycsr,dense) \n "<<std::endl;

    return 1;
  }

  // set up experiment
  const size_t        n_lowerBound = std::stoi(argv[1]);
  const size_t        n_upperBound = std::stoi(argv[2]);
  const size_t        rounds = std::stoi(argv[3]);
  const size_t        evaluation_interval = std::stoi(argv[4]);
  const std::string   device_string = argv[5];
  const std::string   exec_string = argv[6];
  const std::string   mtx_string = argv[7];
  std::string         output_filename = "gko_"+device_string+"_"+exec_string+"_"+mtx_string+"_" \
                                        +std::to_string(n_lowerBound)+"-"+std::to_string(n_upperBound)+"n_" \
                                        +std::to_string(evaluation_interval)+"i_"+std::to_string(rounds)+"r.txt";

  std::map<std::string, std::function<std::shared_ptr<gko::Executor>()>>
        exec_map{
            {"omp", [] { return gko::OmpExecutor::create(); }},
            {"cuda",[] { return gko::CudaExecutor::create(0,gko::OmpExecutor::create()); }},
            {"hip",[] { return gko::HipExecutor::create(0, gko::OmpExecutor::create()); }},
            {"dpcpp",[] { return gko::DpcppExecutor::create(0,gko::OmpExecutor::create()); }},
            {"ref", [] { return gko::ReferenceExecutor::create(); }}};

  auto diffusion_coefficient = [](const std::vector<double> &x) { return 1.0; };
  auto dirichlet_boundary = [](const std::vector<double> &x) { return true; };
  std::map<std::string, std::function<std::pair<std::chrono::nanoseconds, std::chrono::nanoseconds>(size_t, size_t, size_t, std::string)>>
    execute_round_map{
      {"csr", [&] (size_t n, size_t d, size_t round,std::string filename){ return executeRound<gko::matrix::Csr<>>(n,d,round,filename,diffusion_coefficient,dirichlet_boundary,exec_string,exec_map,device_string); }},
      {"ell", [&] (size_t n, size_t d, size_t round,std::string filename){ return executeRound<gko::matrix::Ell<>>(n,d,round,filename,diffusion_coefficient,dirichlet_boundary,exec_string,exec_map,device_string); }},
      {"sellp", [&] (size_t n, size_t d, size_t round,std::string filename){ return executeRound<gko::matrix::Sellp<>>(n,d,round,filename,diffusion_coefficient,dirichlet_boundary,exec_string,exec_map,device_string); }},
      {"coo", [&] (size_t n, size_t d, size_t round,std::string filename){ return executeRound<gko::matrix::Coo<>>(n,d,round,filename,diffusion_coefficient,dirichlet_boundary,exec_string,exec_map,device_string); }}};



  std::cout<<argv[0]<< ": Computing all matrixes with d=2 and d=3, with n="<<n_lowerBound<<" to "<<n_upperBound<<std::endl;
  std::cout<<argv[0]<< ": Computing every variation  "<<rounds<<" times"<<std::endl;
  std::cout<<argv[0]<< ": Interval of evaluated values is "<<evaluation_interval<<" (1 equals evaluating every value of n in bounds)"<<std::endl;
  std::cout<<argv[0]<< ": Configuration: "<<device_string<<" "<< exec_string<< " "<< mtx_string<<std::endl;
  std::cout<<argv[0]<< ": Outputting to: "<< output_filename<<std::endl;


  std::cout << "-------------------------------running Experiment---------------------------------------------------" << std::endl;

  std::ofstream outfile(output_filename);
  for (size_t d=2; d<=3; d++){
    for(size_t n=n_lowerBound; n<=n_upperBound; n++){
      if(n%evaluation_interval!=0) continue;    //skip condition
      for(size_t round_id =1; round_id<=rounds; round_id++){
        // generate data
        auto gen_and_SpMV_times = execute_round_map.at(mtx_string)(n,d,round_id,output_filename);
        //export results to file
        outfile << n << " " << d << " " << round_id<< " " << gen_and_SpMV_times.first.count() << " " << gen_and_SpMV_times.second.count() << "\n";
      }
      outfile.flush();
    }
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
