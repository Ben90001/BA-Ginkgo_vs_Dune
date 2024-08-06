# Install script for directory: /Users/ben/Desktop/BA/src/DUNE/dune-common/dune/python/common

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/dune/python/common" TYPE FILE FILES
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/python/common/densematrix.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/python/common/densevector.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/python/common/dimrange.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/python/common/dynmatrix.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/python/common/dynvector.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/python/common/fmatrix.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/python/common/fvecmatregistry.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/python/common/fvector.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/python/common/getdimension.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/python/common/logger.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/python/common/mpihelper.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/python/common/numpycommdatahandle.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/python/common/numpyvector.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/python/common/pythonvector.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/python/common/string.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/python/common/typeregistry.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/python/common/vector.hh"
    )
endif()

