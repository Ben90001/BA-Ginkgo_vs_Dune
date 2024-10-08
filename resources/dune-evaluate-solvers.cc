// -*- tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 2 -*-
// vi: set et ts=4 sw=2 sts=2:

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif
#include <iostream>
#include <memory>

#include <dune/common/parallel/mpihelper.hh> // An initializer of MPI   
#include <dune/common/exceptions.hh> // We use exceptions 
#include <dune/common/fmatrix.hh>
#include <dune/common/fvector.hh>
#include <dune/common/timer.hh>

#include <dune/istl/bvector.hh> 
#include <dune/istl/bcrsmatrix.hh>

/*
* A function that produces a sparse matrix discretizing the
* diffusion operator -\nabla \cdot (c(x) \nabla ... )
* with cell centered finite volumes in any dimension d on a structured grid with n
* cells per direction.
*/
template <typename CoefficientFunction, typename BoundaryTypeFunction>
std::shared_ptr<Dune::BCRSMatrix<Dune::FieldMatrix<double,1,1>>> diffusion_matrix (int n, int d, 
   CoefficientFunction diffusion_coefficient, BoundaryTypeFunction dirichlet_boundary)
{
  // relevant types
  using MatrixEntry = Dune::FieldMatrix<double,1,1>;
  using Matrix = Dune::BCRSMatrix<MatrixEntry>;

  // prepare grid information
  std::vector<std::size_t> sizes(d+1,1);
  for (int i=1; i<=d; ++i) sizes[i] = sizes[i-1]*n;     /// sizes={1,n,n^2,n^3,...,n^d} => time needed for total concentration equilibirum distance^d
  double mesh_size = 1.0/n;
  int N = sizes[d];

  // create sparse matrix
  std::shared_ptr<Matrix> pA = std::make_shared<Matrix>(N,N,2*d+1,0.02,Matrix::implicit); /// n,m,average#nonzeros per row,compressionBufferSize,buildmode (bcrsmatrix.hh line784) //?-> 2% of n(=N here) memory as buffer
  for (std::size_t index=0; index<sizes[d]; index++)  ///each grid cell
  {
    // create multiindex from row number          ///fancy way of doing 3 for loops over n -> more general, works for all d
    std::vector<std::size_t> multiindex(d,0);
    auto copiedindex=index;
    for (int i=d-1; i>=0; i--)
    {                                             ///start from the back!
      multiindex[i] = copiedindex/sizes[i];       ///implicit size_t cast? Yes: returns only how ofter size fites into cindex
      copiedindex = copiedindex%sizes[i];         ///basically returns the (missing) rest of the checking above 
    }
    
    //std::cout << "index=" << index;
    //for (int i=0; i<d; ++i) std::cout << " " << multiindex[i];
    //std::cout << std::endl;

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
        //! This is a different(much bigger) Matrix, than the imagined multiindex matrix (=actual grid)
        pA->entry(index,index-sizes[i]) = -harmonic_average;          /// row is same as center, but column in grid -1 on i-axis //? -size is index shift??
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
    pA->entry(index,index) = center_matrix_entry;     //# easyer if more positive, time would be added here <-????? wtf did I mean by that?
  }
  auto stats = pA->compress();
  return pA;
}

int main(int argc, char** argv)
{
  try{
    // gridsize in each dimension
    int n = 20;
    // #dimensions
    int d = 3;



    // initialize MPI if present
    Dune::MPIHelper& helper = Dune::MPIHelper::instance(argc, argv);

    // create a sparse matrix
    auto diffusion_coefficient = [](const std::vector<double>& x) { return 1.0; };
    auto dirichlet_boundary = [](const std::vector<double>& x) { return true; };
    Dune::Timer watch;
    watch.reset();
    auto pA = diffusion_matrix(n,d,diffusion_coefficient,dirichlet_boundary);
    auto duration = watch.elapsed();
    std::cout << "created matrix of size " << pA->N() << " times " << pA->M() << " duration " << duration*1000 << " ms" << std::endl;
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
    watch.reset();
    pA->mv(x, y);
    duration = watch.elapsed();
    std::cout << "duration of matrix vector product was " << duration*1000 << " ms" << std::endl;
  }
  catch (Dune::Exception &e){
    std::cerr << "Dune reported error: " << e << std::endl;
  }
  catch (...){                                                      // is this overloading the other catch, or is it just taking in the rest of the thrown errors?
    std::cerr << "Unknown exception thrown!" << std::endl;
  }
  return 0;
}
