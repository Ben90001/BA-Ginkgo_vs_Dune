#!/bin/bash
ginkgo_version="1.8.0"
ginkgo_download_name="v$ginkgo_version.tar.gz"

# bash setup
set -x
set -e

spack env activate gcc-13

# install
mkdir GINKGO
cd GINKGO
# download
wget https://github.com/ginkgo-project/ginkgo/archive/refs/tags/v1.8.0.tar.gz
tar -xvf $ginkgo_download_name
rm $ginkgo_download_name
# build
cd ginkgo-$ginkgo_version
mkdir build
cd build
#cmake -DGINKGO_CUDA_ARCHITECTURES=Turing\;75 ..
cmake -DGINKGO_BUILD_CUDA=OFF ..
make -j16
