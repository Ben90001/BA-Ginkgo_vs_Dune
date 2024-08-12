#!/bin/bash
#
# This script can be used to download and install Dune with
# several external modules from source.
# Currently UG, HDF5 and FFTW3 are supported.
# If no argument is given it prints a list of software required for the build.

# here you may manually define command names
# comment out these definitions to overwrite the default from your system
#export F77=gfortran-14
#export CC=gcc-14
#export CXX=g++-14
#export CC=clang
#export CXX=clang++
export CXXFLAGS='-O3 -DNDEBUG'
export MPICC=mpicc
export MPICXX=mpicxx
#export CMAKE=/home/hd/hd_hd/hd_wi126/local/bin/cmake

# specify project details
project_name="evaluation"
module_dependencies="dune-common dune-istl"
dune_version="2.9"
maintainers_email="lu259@stud.uni-heidelberg.de"

# print requirements
print_requirements_message ()
{
    echo "Run this installer with "
    echo " "
    echo "   installer <directory>"
    echo " "
    echo "where <directory> is the name of a directory where to install to."
    echo "This directory is created if it does not exist."
    echo " "
    echo "In order to run this script you need the following software installed on your machine."
    echo "Use your package manager (or on the Mac macports or homebrew) to do this."
    echo " "
    echo "C++ Compiler. With pdelab gcc>=5.1 should be fine"
    echo "MPI-2 (including support for MPI IO)"
    echo "cmake>=3.0"
    echo "git"
    echo "wget"
    echo " "
    echo "Optionally you should consider to get:"
    echo "Paraview for visualization (http://www.paraview.org)"
    echo "Gmsh for mesh generation (http://gmsh.info)"
}

#
if [ $# -eq 0 ]
then
    print_requirements_message
    exit 1
fi

# usage: installer <directory>
#   directory: new directory in current directory where software is installed

# bash setup
set -x
set -e

# first we create a new directory, step into it and remember where we are
mkdir -p $1
cd $1
ROOT=$(pwd)

# make directory where to put external software
if [ ! "$EXTERNAL_HOME" ]; then
  EXTERNAL_HOME=$ROOT/external
  mkdir -p $EXTERNAL_HOME
fi

# extract default settings for the command names
if [ ! "$F77" ]; then
  F77=gfortran
fi
if [ ! "$CC" ]; then
CC=gcc
fi
if [ ! "$MPICC" ]; then
MPICC=mpicc
fi
if [ ! "$MPICXX" ]; then
MPICXX=mpicxx
fi
if [ ! "$CXX" ]; then
CXX=g++
fi
if [ ! "$CXXFLAGS" ]; then
CXXFLAGS="-O3 -DNDEBUG"
fi
CFLAGS="$CXXFLAGS"
if [ ! "$MAKE_FLAGS" ]; then
MAKE_FLAGS="-j2"
fi
if [ ! "$CMAKE" ]; then
CMAKE=cmake
fi


# check out all the required dune modules
checkout_dune_core ()
{
    # dune core modules
    for i in common istl; do
	git clone https://gitlab.dune-project.org/core/dune-$i.git
	cd dune-$i
	git checkout releases/2.9
	cd ..
    done

     # install whitespace hook
    ./dune-common/bin/dunecontrol vcsetup
}

# generate options file for Dune build system
generate_optsfile ()
{
    CC=$(which $CC)
    CXX=$(which $CXX)
    F77=$(which $F77)
echo "CMAKE_FLAGS=\"
-DCMAKE_C_COMPILER='$CC'
-DCMAKE_CXX_COMPILER='$CXX'
-DCMAKE_Fortran_COMPILER='$F77'
-DCMAKE_CXX_FLAGS_RELEASE='-O3 -DNDEBUG -g0 -funroll-loops -ftemplate-depth=5120 -march=native'
-DCMAKE_BUILD_TYPE=Release
-DDUNE_SYMLINK_TO_SOURCE_TREE=1
\"" > release.opts
}

# create project folder to use Dune in
generate_custom_project ()
{
./dune-common/bin/duneproject <<EOF
    dune-$project_name
    $module_dependencies
    $dune_version
    $maintainers_email
    y
EOF
}

# create build script
generate_buildscript ()
{
echo '#!/bin/bash
ROOT=$(pwd)
BUILDDIR=$ROOT/release-build
OPTSFILE=release.opts
MODULES="common istl evaluation "
for i in $MODULES; do
    echo build $i
    ./dune-common/bin/dunecontrol --builddir=$BUILDDIR  --opts=$OPTSFILE --only=dune-$i all
done
' > buildmodules.sh
chmod 755 buildmodules.sh
}

#select here what you want to install
checkout_dune_core
generate_optsfile
generate_custom_project
generate_buildscript
echo "END of dune_installer.sh"
