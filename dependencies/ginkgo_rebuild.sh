#!/bin/bash
ginkgo_version="1.8.0"
ginkgo_download_name="v$ginkgo_version.tar.gz"

# bash setup
set -x
set -e

spack env activate gcc-13

# rebuild
cd GINKGO
cd ginkgo-$ginkgo_version
cd build
#cmake -DGINKGO_CUDA_ARCHITECTURES=Turing\;75 ..
cmake -DGINKGO_BUILD_CUDA=OFF ..
make -j16
