#!/bin/bash

cd ginkgo
mkdir build
cd build


        #-DCMAKE_C_COMPILER=/usr/local/opt/gcc/bin/gcc-14 \
        #-DCMAKE_CXX_COMPILER=/usr/local/opt/gcc/bin/g++-14 \
cmake   -DCMAKE_INSTALL_PREFIX=/Users/ben/Desktop/BA/dependencies/GINKGO \
        -DCMAKE_C_COMPILER=/Users/ben/Desktop/BA/dependencies/CLANG/clang+llvm-18.1.8-x86_64-linux-gnu-ubuntu-18.04/bin/clang \
        -DCMAKE_CXX_COMPILER=/Users/ben/Desktop/BA/dependencies/CLANG/clang+llvm-18.1.8-x86_64-linux-gnu-ubuntu-18.04/bin/clang++ \
        ..
        #-DCMAKE_EXE_LINKER_FLAGS="-L/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/lib" \
        #-DCMAKE_C_FLAGS="-isysroot $(xcrun -show-sdk-path)" \
        #-DCMAKE_CXX_FLAGS="-isysroot $(xcrun -show-sdk-path)" \

cmake --build .
cmake --install .
#make

