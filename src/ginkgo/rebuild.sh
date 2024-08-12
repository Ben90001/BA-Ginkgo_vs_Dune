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
