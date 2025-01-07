// -*- tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 2 -*-
// vi: set et ts=4 sw=2 sts=2:

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif
#include <iostream>
#include <memory>
#include <fstream>
#include <filesystem>
#include <cmath>

#include <dune/common/parallel/mpihelper.hh> // An initializer of MPI   
#include <dune/common/exceptions.hh> // We use exceptions 
#include <dune/common/fmatrix.hh>
#include <dune/common/fvector.hh>
#include <dune/common/timer.hh>

#include <dune/istl/bvector.hh> 
#include <dune/istl/bcrsmatrix.hh>
#include <dune/istl/matrixmarket.hh>
#include <dune/istl/preconditioners.hh>
#include <dune/istl/solvers.hh>
#include <dune/istl/operators.hh>

size_t getNNZ(int n, int dim){
  if(dim==2) return 5*n*n - 4*n;
  if(dim==3) return 7*n*n*n - 6*n*n;
  for(int i=0; i<10000; i++){
    std::cout<< "This should not have happend, no applicable n for getNNZ in dune-evaluation.cc"<<"\n";
  }
}

/*
* A function that produces a sparse matrix discretizing the
* diffusion operator -\nabla \cdot (c(x) \nabla ... )
* with cell centered finite volumes in any dimension d on a structured grid with n
* cells per direction.
*/
template <typename CoefficientFunction, typename BoundaryTypeFunction>
std::shared_ptr<Dune::BCRSMatrix<Dune::FieldMatrix<double,1,1>>> diffusion_matrix_implicit (int n, int d,
   CoefficientFunction diffusion_coefficient, BoundaryTypeFunction dirichlet_boundary)
{
  // relevant types
  using MatrixEntry = Dune::FieldMatrix<double,1,1>;
  using Matrix = Dune::BCRSMatrix<MatrixEntry>;

  // prepare grid information
  std::vector<std::size_t> sizes(d+1,1);
  for (int i=1; i<=d; ++i) sizes[i] = sizes[i-1]*n;
  double mesh_size = 1.0/n;
  int N = sizes[d];

  // create sparse matrix
  std::shared_ptr<Matrix> pA = nullptr;
  pA= std::make_shared<Matrix>(N,N,2*d+1,0.02,Matrix::implicit); /// n,m,average#nonzeros per row,compressionBufferSize,buildmode (bcrsmatrix.hh line784) //?-> 2% of n(=N here) memory as buffer

  for (std::size_t index=0; index<sizes[d]; index++)  ///each grid cell
  {
    // create multiindex from row number          ///fancy way of doing 3 for loops over n -> more general, works for all d
    std::vector<std::size_t> multiindex(d,0);
    auto copiedindex=index;
    for (int i=d-1; i>=0; i--)
    {
      multiindex[i] = copiedindex/sizes[i];
      copiedindex = copiedindex%sizes[i];
    }

    // the current cell
    std::vector<double> center_position(d);       ///scaled up multigrid/cell-position
    for (int i=0; i<d; ++i) 
      center_position[i] = multiindex[i]*mesh_size;
    double center_coefficient = diffusion_coefficient(center_position);
    double center_matrix_entry = 0.0;

    // loop over all neighbors
    for (int i=0; i<d; i++)
    {
      // down neighbor
      if (multiindex[i]>0)
      {
        // we have a neighbor cell
        std::vector<double> neighbor_position(center_position);
        neighbor_position[i] -= mesh_size;
        double neighbor_coefficient = diffusion_coefficient(neighbor_position);
        double harmonic_average = 2.0/( (1.0/neighbor_coefficient) + (1.0/center_coefficient) );
        pA->entry(index,index-sizes[i]) = -harmonic_average;          /// row is same as center, but column in grid -1 on i-axis
        center_matrix_entry += harmonic_average;
      }
      else
      {
        // current cell is on the boundary in this direction
        std::vector<double> neighbor_position(center_position);
        neighbor_position[i] = 0.0;
        if (dirichlet_boundary(neighbor_position))
          center_matrix_entry += center_coefficient*2.0;
      }

      // up neighbor
      if (multiindex[i]<n-1)
      {
        // we have a neighbor cell
        std::vector<double> neighbor_position(center_position);
        neighbor_position[i] += mesh_size;
        double neighbor_coefficient = diffusion_coefficient(neighbor_position);
        double harmonic_average = 2.0/( (1.0/neighbor_coefficient) + (1.0/center_coefficient) );
        pA->entry(index,index+sizes[i]) = -harmonic_average;
        center_matrix_entry += harmonic_average;
      }
      else
      {
        // current cell is on the boundary in this direction
        std::vector<double> neighbor_position(center_position);
        neighbor_position[i] = 1.0;
        if (dirichlet_boundary(neighbor_position))
          center_matrix_entry += center_coefficient*2.0;
      }
    }

    // finally the diagonal entry
    pA->entry(index,index) = center_matrix_entry;
  }
  auto stats = pA->compress();

  return pA;
}

template <typename CoefficientFunction, typename BoundaryTypeFunction>
std::shared_ptr<Dune::BCRSMatrix<Dune::FieldMatrix<double,1,1>>> diffusion_matrix_row_wise (int n, int d,
   CoefficientFunction diffusion_coefficient, BoundaryTypeFunction dirichlet_boundary)
{
  // relevant types
  using MatrixEntry = Dune::FieldMatrix<double,1,1>;
  using Matrix = Dune::BCRSMatrix<MatrixEntry>;

  // prepare grid information
  std::vector<std::size_t> sizes(d+1,1);
  for (int i=1; i<=d; ++i) sizes[i] = sizes[i-1]*n;
  double mesh_size = 1.0/n;
  int N = sizes[d];

  // create sparse matrix
  std::shared_ptr<Matrix> pA = nullptr;
    // third parameter is an optional upper bound for the number
    // of nonzeros. If given the matrix will use one array for all values
    // as opposed to one for each row.
  pA= std::make_shared<Matrix>(N,N,getNNZ(n,d),Matrix::row_wise);

  // create sparsity pattern
  typedef Matrix::CreateIterator Iter;
  for(Iter row=(*pA).createbegin(); row!=(*pA).createend(); ++row)  ///each grid cell (=row)
  {
    //std::cout<<"Sparsity Pattern generation: row.index()" << row.index()<< std::endl;             //debug
    // create multiindex from row number
    std::vector<std::size_t> multiindex(d,0);
    auto copiedindex=row.index();
    for (int i=d-1; i>=0; i--)
    {
      multiindex[i] = copiedindex/sizes[i];
      copiedindex = copiedindex%sizes[i];
    }

    // loop over all neighbors
    for (int i=0; i<d; i++)
    {
      // down neighbor
      if (multiindex[i]>0)
      {
        // we have a neighbor cell
        row.insert(row.index()-sizes[i]);
      }// else: cell is on boundary

      // up neighbor
      if (multiindex[i]<n-1)
      {
        // we have a neighbor cell
        row.insert(row.index()+sizes[i]);
      }// else: cell is on boundary
    }
    // finally the diagonal entry
    row.insert(row.index());
  }

  // fill in nnz values
  for (std::size_t index=0; index<sizes[d]; index++)  ///each grid cell
  {
    // create multiindex from row number          ///fancy way of doing 3 for loops over n -> more general, works for all d
    std::vector<std::size_t> multiindex(d,0);
    auto copiedindex=index;
    for (int i=d-1; i>=0; i--)
    {
      multiindex[i] = copiedindex/sizes[i];
      copiedindex = copiedindex%sizes[i];
    }
    //std::cout<<"Fill in iteration: index=" << index<< std::endl;            //debug
    // the current cell
    std::vector<double> center_position(d);       ///scaled up multigrid/cell-position
    for (int i=0; i<d; ++i) 
      center_position[i] = multiindex[i]*mesh_size;
    double center_coefficient = diffusion_coefficient(center_position);
    double center_matrix_entry = 0.0;

    // loop over all neighbors
    for (int i=0; i<d; i++)
    {
      // down neighbor
      if (multiindex[i]>0)
      {
        // we have a neighbor cell
        std::vector<double> neighbor_position(center_position);
        neighbor_position[i] -= mesh_size;
        double neighbor_coefficient = diffusion_coefficient(neighbor_position);
        double harmonic_average = 2.0/( (1.0/neighbor_coefficient) + (1.0/center_coefficient) );
        (*pA)[index][index-sizes[i]] = -harmonic_average;          /// row is same as center, but column in grid -1 on i-axis
        center_matrix_entry += harmonic_average;
      }
      else
      {
        // current cell is on the boundary in this direction
        std::vector<double> neighbor_position(center_position);
        neighbor_position[i] = 0.0;
        if (dirichlet_boundary(neighbor_position))
          center_matrix_entry += center_coefficient*2.0;
      }

      // up neighbor
      if (multiindex[i]<n-1)
      {
        // we have a neighbor cell
        std::vector<double> neighbor_position(center_position);
        neighbor_position[i] += mesh_size;
        double neighbor_coefficient = diffusion_coefficient(neighbor_position);
        double harmonic_average = 2.0/( (1.0/neighbor_coefficient) + (1.0/center_coefficient) );
        (*pA)[index][index+sizes[i]] = -harmonic_average;
        center_matrix_entry += harmonic_average;
      }
      else
      {
        // current cell is on the boundary in this direction
        std::vector<double> neighbor_position(center_position);
        neighbor_position[i] = 1.0;
        if (dirichlet_boundary(neighbor_position))
          center_matrix_entry += center_coefficient*2.0;
      }
    }

    // finally the diagonal entry
    (*pA)[index][index] = center_matrix_entry;
  }

  return pA;
}

void executeRound (int n, int dim, int max_iters, size_t min_reps, size_t min_time,\
                                                    std::string filename, std::string buildMode)
{
  try{
    // n = gridsize in each dimension
    // dim = #dimensions
    std::cout<< "---------------------"<<"(DUNE) n="<<n<<" dim="<<dim<<"---------------------"<<std::endl;

  // create a sparse matrix
    auto diffusion_coefficient = [](const std::vector<double>& x) { return 1.0; };
    auto dirichlet_boundary = [](const std::vector<double>& x) { return true; };
    using MatrixEntry = Dune::FieldMatrix<double,1,1>;
    using Matrix = Dune::BCRSMatrix<MatrixEntry>;
    std::shared_ptr<Matrix> pA = nullptr;

    auto time_start = std::chrono::high_resolution_clock::now();
    auto time_stop = std::chrono::high_resolution_clock::now();

    if(buildMode == "implicit"){
      std::cout<< "Generating with BuildMode implicit"<<std::endl;
      time_start = std::chrono::high_resolution_clock::now();
      time_stop = time_start;
      auto duration = time_stop - time_start;
      auto duration_cast = std::chrono::duration_cast<std::chrono::nanoseconds>(duration).count();
      auto duration_sum = duration_cast;
      long rep = min_reps;
      long finished_reps = 0;
      std::string foldername = "data/gen/";
      std::filesystem::create_directories(foldername);
      std::ofstream outfile_gen(foldername+"gen_"+filename+"_d"+std::to_string(dim)+".txt", std::ios::app);
      while (duration_sum < min_time && rep < 1000000000)
      {
        for (long k = 0; k < rep; k++){
          time_start = std::chrono::high_resolution_clock::now();
          pA = diffusion_matrix_implicit(n,dim,diffusion_coefficient,dirichlet_boundary);
          time_stop = std::chrono::high_resolution_clock::now();
          duration = time_stop - time_start;
          duration_cast = std::chrono::duration_cast<std::chrono::nanoseconds>(duration).count();
          outfile_gen 
            << n << " "
            << dim << " "
            << finished_reps + k << " "
            << duration_cast << "\n";
          duration_sum += duration_cast;
        }
        outfile_gen.flush();
        std::cout << "(DUNE) Gen: n="<<n<<" dim="<<dim<<" finished_reps=" << finished_reps << " duration_sum in ms=" << duration_sum/1000000 << std::endl;
        finished_reps +=rep;
        rep *= 2;
      }
      outfile_gen.close();
    }
    else if(buildMode == "row_wise"){
      std::cout<< "Generating with BuildMode row_wise"<<std::endl;
      time_start = std::chrono::high_resolution_clock::now();
      time_stop = time_start;
      auto duration = time_stop - time_start;
      auto duration_cast = std::chrono::duration_cast<std::chrono::nanoseconds>(duration).count();
      auto duration_sum = duration_cast;
      long rep = min_reps;
      long finished_reps = 0;
      std::string foldername = "data/gen/";
      std::filesystem::create_directories(foldername);
      std::ofstream outfile_gen(foldername+"gen_"+filename+"_d"+std::to_string(dim)+".txt", std::ios::app);
      while (duration_sum < min_time && rep < 1000000000)
      {
        for (long k = 0; k < rep; k++){
          time_start = std::chrono::high_resolution_clock::now();
          pA = diffusion_matrix_row_wise(n,dim,diffusion_coefficient,dirichlet_boundary);
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
        std::cout << "(DUNE) Gen: n="<<n<<" dim="<<dim<<" finished_reps=" << finished_reps << " duration_sum in ms=" << duration_sum/1000000 << std::endl;
        finished_reps +=rep;
        rep *= 2;
      }
        outfile_gen.close();
    }
    else{ std::cout<< "Oh no, unknown BuildMode"<<std::endl;}

    if(n<=30){
      // store matrix
      std::string foldername = "result-verification/A/";
      std::filesystem::create_directories(foldername);
      std::string filename_A = foldername+std::to_string(n)+"_"+std::to_string(dim)+"_A_"+filename+".mtx";
      Dune::storeMatrixMarket(*pA,filename_A);
      std::cout<< "stored matrix to "+filename_A<<std::endl;
    }


  //calculate SpMV
    // vector type
    using VectorEntry = Dune::FieldVector<double,1>;
    using Vector = Dune::BlockVector<VectorEntry>;
    // create two vectors of appropriate length
    Vector x(pA->N()), y(pA->N());
    // matrix vector product
    x = 1.0;                                        /// sets all elements to 1

    std::cout<< "SpMV calculating ..."<<std::endl;
    time_start = std::chrono::high_resolution_clock::now();
    time_stop = time_start;
    auto duration = time_stop - time_start;
    auto duration_cast = std::chrono::duration_cast<std::chrono::nanoseconds>(duration).count();
    auto duration_sum = duration_cast;
    long rep = min_reps;
    long finished_reps = 0;
    std::string foldername = "data/SpMV/";
    std::filesystem::create_directories(foldername);
    std::ofstream outfile_SpMV(foldername+"SpMV_"+filename+"_d"+std::to_string(dim)+".txt", std::ios::app);
    while (duration_sum < min_time && rep < 1000000000)
    {
      for (long k = 0; k < rep; k++){
        time_start = std::chrono::high_resolution_clock::now();
        pA->mv(x, y);
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
        std::cout << "(DUNE) SpMV: n="<<n<<" dim="<<dim<<" finished_reps=" << finished_reps << " duration_sum in ms=" << duration_sum/1000000 << std::endl;
      finished_reps +=rep;
      rep *= 2;
    }
    outfile_SpMV.close();
    if(n<=30){
      // store SpMV result y
      std::string foldername = "result-verification/y/";
      std::filesystem::create_directories(foldername);
      std::string filename_y = foldername+std::to_string(n)+"_"+std::to_string(dim)+"_y_"+filename+".mtx";
      Dune::storeMatrixMarket(y,filename_y);
      std::cout<< "stored result y to "+filename_y<<std::endl;
    }

  // Create CG_jac
    MatrixEntry w = 1.0; // scales inverse D 
    //A, "The number of iterations to perform.", The relaxation factor.
    Dune::SeqJac<Matrix,Vector,Vector> preconditioner_jac(*pA,1, w); 
    //make pA into Linear Operator
    Dune::MatrixAdapter<Matrix,Vector,Vector> linOp_A{pA};

    //linOp, precond, reduction, maxIt, verbose, condition_estimate(missing? (bool))
    Dune::CGSolver<Vector> solver_jac(linOp_A, preconditioner_jac, 0.0, max_iters,1);

  // apply CG_jac
    Vector x_k(pA->N()),b(pA->N());
    Dune::InverseOperatorResult results;
    
    //experiment
    std::cout<< "CG_jac calculating ..."<<std::endl;
    time_start = std::chrono::high_resolution_clock::now();
    time_stop = time_start;
    duration = time_stop - time_start;
    duration_cast = std::chrono::duration_cast<std::chrono::nanoseconds>(duration).count();
    duration_sum = duration_cast;
    rep = min_reps;
    finished_reps = 0;
    foldername = "data/CGjac/";
    std::filesystem::create_directories(foldername);
    std::ofstream outfile_CGjac(foldername+"CGjac_"+filename+"_d"+std::to_string(dim)+".txt", std::ios::app);
    while (duration_sum < min_time && rep < 1000000000)
    {
      for (long k = 0; k < rep; k++){
        // different from ginkgo, dune modifies rhs(b) during solving, needs resetting
        x_k,b = 1.0;
        time_start = std::chrono::high_resolution_clock::now();
        solver_jac.apply(x_k,b,results);
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
        std::cout << "(DUNE) CG_jac: n="<<n<<" dim="<<dim<<" finished_reps=" << finished_reps << " duration_sum in ms=" << duration_sum/1000000 << std::endl;
      finished_reps +=rep;
      rep *= 2;
    }
    outfile_CGjac.close();

    if(n<=30){
      // store CG solution x_k after max_iters iterations
      std::string foldername = "result-verification/x_k_jac/";
      std::filesystem::create_directories(foldername);
      std::string filename_x_k_jac = foldername+std::to_string(n)+"_"+std::to_string(dim)+"_x_k_jac_"+filename+".mtx";
      Dune::storeMatrixMarket(x_k,filename_x_k_jac);
      std::cout<< "stored result x_k to "+filename_x_k_jac<<std::endl;
    }
  
  //create CG_ILU (ILU0)
    w = 1.0;
    //A, "The order of the ILU decomposition.", "The relaxation factor."
    Dune::SeqILU<Matrix,Vector,Vector> preconditioner_ILU(*pA,0, w); 

    //linOp, precond, reduction, maxIt, verbose, condition_estimate(missing? (bool))
    Dune::CGSolver<Vector> solver_ILU(linOp_A, preconditioner_ILU, 0.0, max_iters,1);

  // apply CG_ILU
    //experiment
    std::cout<< "CG_ILU calculating ..."<<std::endl;
    time_start = std::chrono::high_resolution_clock::now();
    time_stop = time_start;
    duration = time_stop - time_start;
    duration_cast = std::chrono::duration_cast<std::chrono::nanoseconds>(duration).count();
    duration_sum = duration_cast;
    rep = min_reps;
    finished_reps = 0;
    foldername = "data/CGilu/";
    std::filesystem::create_directories(foldername);
    std::ofstream outfile_CG_ILU(foldername+"CGilu_"+filename+"_d"+std::to_string(dim)+".txt", std::ios::app);
    while (duration_sum < min_time && rep < 1000000000)
    {
      for (long k = 0; k < rep; k++){
        // different from ginkgo, dune modifies rhs(b) during solving, needs resetting
        x_k,b = 1.0;
        time_start = std::chrono::high_resolution_clock::now();
        solver_ILU.apply(x_k,b,results);
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
        std::cout << "(DUNE) CG_ILU: n="<<n<<" dim="<<dim<<" finished_reps=" << finished_reps << " duration_sum in ms=" << duration_sum/1000000 << std::endl;
      finished_reps +=rep;
      rep *= 2;
    }
    outfile_CG_ILU.close();

    if(n<=30){
    // store CG solution x_k after max_iters iterations
    std::string foldername = "result-verification/x_k_ilu/";
    std::filesystem::create_directories(foldername);
    std::string filename_x_k_ilu = foldername+std::to_string(n)+"_"+std::to_string(dim)+"_x_k_ilu_"+filename+".mtx";
    Dune::storeMatrixMarket(x_k,filename_x_k_ilu);
    std::cout<< "stored result x_k to "+filename_x_k_ilu<<std::endl;
  }


  }
  catch (Dune::Exception &e){
    std::cerr << "Dune reported error: " << e << std::endl;
  }
  catch (...){                                                      // is this overloading the other catch, or is it just taking in the rest of the thrown errors?
    std::cerr << "Unknown exception thrown!" << std::endl;
  }
}


int main(int argc, char** argv)
{
  std::cout << "-------------------------------STARTING:dune-evaluation--------------------------------------------" << std::endl;
  // handle input
  if (argc!=7) {
    std::cout<<argv[0]<< ": Wrong number of Arguments."<<std::endl;
    std::cout<<"please give arguements: n_max dim max_iters min_reps min_time buildMode"<<std::endl;
    return 1;
  }
  const size_t n_max = std::stoi(argv[1]);
  std::cout<<argv[0]<< ": Computing all matrices from n=1 to n="<<n_max<<std::endl;
  const int dim = std::stoi(argv[2]);
  std::cout<<argv[0]<< ": Computing all matrices with dim= "<<dim<<std::endl;
  const size_t max_iters = std::stoi(argv[3]);
  std::cout<<argv[0]<< ": Computing CG with  "<<max_iters<<" iterations"<<std::endl;
  // minimum number of repititions per n
  const size_t min_reps = std::stoi(argv[4]);
  // minimum number of nanoseconds per experiment(gen,spmv,cg_jac) 
  const size_t min_time = std::stoi(argv[5]);
  std::cout<<argv[0]<< ": Computing every variation  "<<min_reps<<" times"<<std::endl;
  const std::string buildMode = argv[6];
  std::cout<<argv[0]<< ": Computing with BuildMode:  "<<buildMode<<" "<<std::endl;

  // initialize MPI if present
    Dune::MPIHelper& helper = Dune::MPIHelper::instance(argc, argv);
 
  std::cout << "-------------------------------running Experiment--------------------------------------------------" << std::endl;
  
  std::string filename = "ISTL_"+buildMode;
  for(size_t n=1; n<=n_max; n++)
      executeRound(n,dim,max_iters,min_reps,min_time,filename,buildMode);

  std::cout << "-------------------------------FINISHED:dune-evaluation---------------------------------------" << std::endl;
  
  return 0;
}



    // print Non Zeros
    /*
    for (std::size_t i = 0; i < pA->N(); ++i) { // Loop over all rows
        for (auto it = (*pA)[i].begin(); it != (*pA)[i].end(); ++it) { // Loop over non-zero entries in the row
            std::cout << "Entry (" << i << ", " << it.index() << ") = " << *it << std::endl;
        }
    }
    */