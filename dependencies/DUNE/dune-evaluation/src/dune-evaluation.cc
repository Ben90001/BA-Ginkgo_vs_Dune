// -*- tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 2 -*-
// vi: set et ts=4 sw=2 sts=2:

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif
#include <iostream>
#include <memory>
#include<fstream>
#include <filesystem>
#include<cmath>

#include <dune/common/parallel/mpihelper.hh> // An initializer of MPI   
#include <dune/common/exceptions.hh> // We use exceptions 
#include <dune/common/fmatrix.hh>
#include <dune/common/fvector.hh>
#include <dune/common/timer.hh>

#include <dune/istl/bvector.hh> 
#include <dune/istl/bcrsmatrix.hh>
#include <dune/istl/matrixmarket.hh>

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
//pA= std::make_shared<Matrix>(N,N,getNNZ(n,d),Matrix::row_wise);

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
std::cout<<"Sparsity Pattern generation: row.index()" << row.index()<< std::endl;
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
std::cout<<"Fill in iteration: index=" << index<< std::endl;
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

std::pair<std::chrono::nanoseconds,std::chrono::nanoseconds> executeRound (int n, int d, size_t round,std::string filename, std::string buildMode)
{
  try{
    // n= gridsize in each dimension
    // d= #dimensions

    // create a sparse matrix
    auto diffusion_coefficient = [](const std::vector<double>& x) { return 1.0; };
    auto dirichlet_boundary = [](const std::vector<double>& x) { return true; };
    using MatrixEntry = Dune::FieldMatrix<double,1,1>;
    using Matrix = Dune::BCRSMatrix<MatrixEntry>;
    std::shared_ptr<Matrix> pA = nullptr;
    // Dune::Timer watch;
    // watch.reset();
    auto time_start = std::chrono::steady_clock::now();
    auto time_stop = std::chrono::steady_clock::now();
    if(buildMode == "implicit"){
      std::cout<< "Generating with BuildMode implicit"<<std::endl;
      auto time_start = std::chrono::steady_clock::now();
      pA = diffusion_matrix_implicit(n,d,diffusion_coefficient,dirichlet_boundary);
      auto time_stop = std::chrono::steady_clock::now();
    }
    else if(buildMode == "row_wise"){
      std::cout<< "Generating with BuildMode row_wise"<<std::endl;
      auto time_start = std::chrono::steady_clock::now();
      pA = diffusion_matrix_row_wise(n,d,diffusion_coefficient,dirichlet_boundary);
      auto time_stop = std::chrono::steady_clock::now();
    }
    else{ std::cout<< "Oh no, unknown BuildMode"<<std::endl;}
 
    auto time_to_generate = std::chrono::duration_cast<std::chrono::nanoseconds>(time_stop - time_start);
    std::cout << "(DUNE) Generation Time n="<<n<<",d="<<d<<" : " << time_to_generate.count() / 1000000 << "." << time_to_generate.count() % 1000000 << "ms" << std::endl;
    std::cout << "created matrix of size " << pA->N() << " times " << pA->M() << std::endl;
    if(round == 1){
      // store matrix
      std::string foldername = "result-verification/A/";
      std::filesystem::create_directories(foldername);
      std::string filename_A = foldername+std::to_string(n)+"_"+std::to_string(d)+"_A_"+filename+".mtx";
      Dune::storeMatrixMarket(*pA,filename_A);
      std::cout<< "stored matrix to "+filename_A<<std::endl;
    }

    // auto duration = watch.elapsed();
    // std::cout << "created matrix of size " << pA->N() << " times " << pA->M() << " duration " << duration*1000 << " ms" << std::endl;
    //print Matrix
    //size_t N = 1;
    //for(int i=0; i<d; i++) N*=n;
    



    // vector type
    using VectorEntry = Dune::FieldVector<double,1>;
    using Vector = Dune::BlockVector<VectorEntry>;

    // create two vectors of appropriate length
    Vector x(pA->N()), y(pA->N());

    // matrix vector product
    x = 1.0;                                        /// sets all elements to 1

    // time matrix vector product
    // watch.reset();
    time_start = std::chrono::steady_clock::now();
    pA->mv(x, y);
    time_stop = std::chrono::steady_clock::now();
    auto time_to_SpMV = std::chrono::duration_cast<std::chrono::nanoseconds>(time_stop - time_start);
    std::cout << "Time it took to apply A on x:  " << time_to_SpMV.count() / 1000000 << "." << time_to_SpMV.count() % 1000000 << "ms" << std::endl;
    if(round == 1){
      // store SpMV result y
      std::string foldername = "result-verification/y/";
      std::filesystem::create_directories(foldername);
      std::string filename_y = foldername+std::to_string(n)+"_"+std::to_string(d)+"_y_"+filename+".mtx";
      Dune::storeMatrixMarket(y,filename_y);
      std::cout<< "stored result y to "+filename_y<<std::endl;
    }
    // duration = watch.elapsed();
    // std::cout << "duration of matrix vector product was " << duration*1000 << " ms" << std::endl;

    return std::pair<std::chrono::nanoseconds,std::chrono::nanoseconds>(time_to_generate,time_to_SpMV);
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
  if (argc!=4) {
    std::cout<<argv[0]<< ": Wrong number of Arguments."<<std::endl;
    std::cout<<"please give arguements: n_max numberOfRounds buildMode"<<std::endl;
    return 1;
  }
  const size_t n_max = std::stoi(argv[1]);
  std::cout<<argv[0]<< ": Computing all matrices with d=2 and d=3, with n=1 to "<<n_max<<std::endl;
  // number of repititions per n,d variation
  const size_t rounds = std::stoi(argv[2]);
  std::cout<<argv[0]<< ": Computing every variation  "<<rounds<<" times"<<std::endl;
  const std::string buildMode = argv[3];
  std::cout<<argv[0]<< ": Computing with BuildMode:  "<<buildMode<<" "<<std::endl;

  // initialize MPI if present
    Dune::MPIHelper& helper = Dune::MPIHelper::instance(argc, argv);
 
  std::cout << "-------------------------------running Experiment--------------------------------------------------" << std::endl;
  std::string filename = "ISTL_"+buildMode;
  std::ofstream outfile(filename +".txt");
  for (size_t d=2; d<=3; d++){
    for(size_t n=1; n<=n_max; n++){
      for(size_t round_id =1; round_id<=rounds; round_id++){
        auto gen_and_SpMV_times = executeRound(n,d,round_id,filename,buildMode);
        //export results to file
        outfile << n << " "
                << d << " "
                << round_id<< " "
                << gen_and_SpMV_times.first.count() << " "
                << gen_and_SpMV_times.second.count() << "\n";
      }
      outfile.flush();
    }
  }
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