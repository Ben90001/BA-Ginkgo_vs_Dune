# Install script for directory: /Users/ben/Desktop/BA/src/DUNE/dune-istl/dune/istl

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/dune/istl" TYPE FILE FILES
    "/Users/ben/Desktop/BA/src/DUNE/dune-istl/dune/istl/allocator.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-istl/dune/istl/basearray.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-istl/dune/istl/bccsmatrix.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-istl/dune/istl/bccsmatrixinitializer.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-istl/dune/istl/bcrsmatrix.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-istl/dune/istl/bdmatrix.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-istl/dune/istl/blocklevel.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-istl/dune/istl/btdmatrix.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-istl/dune/istl/bvector.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-istl/dune/istl/cholmod.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-istl/dune/istl/foreach.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-istl/dune/istl/gsetc.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-istl/dune/istl/ildl.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-istl/dune/istl/ilu.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-istl/dune/istl/ilusubdomainsolver.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-istl/dune/istl/io.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-istl/dune/istl/istlexception.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-istl/dune/istl/ldl.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-istl/dune/istl/matrix.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-istl/dune/istl/matrixindexset.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-istl/dune/istl/matrixmarket.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-istl/dune/istl/matrixmatrix.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-istl/dune/istl/matrixredistribute.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-istl/dune/istl/matrixutils.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-istl/dune/istl/multitypeblockmatrix.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-istl/dune/istl/multitypeblockvector.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-istl/dune/istl/novlpschwarz.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-istl/dune/istl/operators.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-istl/dune/istl/overlappingschwarz.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-istl/dune/istl/owneroverlapcopy.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-istl/dune/istl/preconditioner.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-istl/dune/istl/preconditioners.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-istl/dune/istl/repartition.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-istl/dune/istl/scalarproducts.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-istl/dune/istl/scaledidmatrix.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-istl/dune/istl/schwarz.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-istl/dune/istl/solvercategory.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-istl/dune/istl/solver.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-istl/dune/istl/solverfactory.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-istl/dune/istl/solverregistry.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-istl/dune/istl/solvers.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-istl/dune/istl/solvertype.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-istl/dune/istl/spqr.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-istl/dune/istl/superlu.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-istl/dune/istl/superlufunctions.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-istl/dune/istl/supermatrix.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-istl/dune/istl/umfpack.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-istl/dune/istl/vbvector.hh"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/Users/ben/Desktop/BA/src/DUNE/release-build/dune-istl/dune/istl/common/cmake_install.cmake")
  include("/Users/ben/Desktop/BA/src/DUNE/release-build/dune-istl/dune/istl/eigenvalue/cmake_install.cmake")
  include("/Users/ben/Desktop/BA/src/DUNE/release-build/dune-istl/dune/istl/paamg/cmake_install.cmake")
  include("/Users/ben/Desktop/BA/src/DUNE/release-build/dune-istl/dune/istl/test/cmake_install.cmake")

endif()

