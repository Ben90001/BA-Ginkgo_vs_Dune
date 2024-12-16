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
# n_min n_max rounds interval max_iters assemblyStructure executor format
./ginkgo-evaluation 1 5 1 1 5 cpu ref csr