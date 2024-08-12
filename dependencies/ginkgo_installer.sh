#!/bin/bash
ginkgo_version="1.8.0"
ginkgo_download_name="v$ginkgo_version.tar.gz"

# bash setup
set -x
set -e

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
cmake -DCMAKE_INSTALL_PREFIX=/Users/ben/Desktop/BA/dependencies/GINKGO/install_dir ..
make -j8
