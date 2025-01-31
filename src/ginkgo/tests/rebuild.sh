#!/bin/bash

# bash setup
set -x
set -e


rm -rf build
mkdir build
cd build
cmake \
	-DCMAKE_C_COMPILER=mpicc \
	-DCMAKE_CXX_COMPILER=mpicxx \
	-DGinkgo_DIR=/home/benh/BA-Ginkgo_vs_Dune/dependencies/GINKGO/ginkgo-1.8.0/build \
	..
make

# test immediately
# n_lowerBound n_upperBound dim min_reps min_time max_iters assembly_structure executor format
#./ginkgo-evaluation 1 5 3 1 250 10 md ref csr
