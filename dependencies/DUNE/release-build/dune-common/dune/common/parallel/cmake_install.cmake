# Install script for directory: /Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/parallel

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/dune/common/parallel" TYPE FILE FILES
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/parallel/collectivecommunication.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/parallel/communication.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/parallel/communicator.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/parallel/indexset.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/parallel/indicessyncer.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/parallel/interface.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/parallel/localindex.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/parallel/mpicollectivecommunication.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/parallel/mpicommunication.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/parallel/mpiguard.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/parallel/future.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/parallel/mpifuture.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/parallel/mpidata.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/parallel/mpipack.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/parallel/mpihelper.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/parallel/mpitraits.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/parallel/plocalindex.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/parallel/remoteindices.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/parallel/selection.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/parallel/variablesizecommunicator.hh"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/Users/ben/Desktop/BA/src/DUNE/release-build/dune-common/dune/common/parallel/test/cmake_install.cmake")
  include("/Users/ben/Desktop/BA/src/DUNE/release-build/dune-common/dune/common/parallel/benchmark/cmake_install.cmake")

endif()

