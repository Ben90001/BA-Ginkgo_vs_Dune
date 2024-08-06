# Install script for directory: /Users/ben/Desktop/BA/src/DUNE/dune-common/dune/python/pybind11

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/dune/python/pybind11" TYPE FILE FILES
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/python/pybind11/attr.h"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/python/pybind11/common.h"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/python/pybind11/eval.h"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/python/pybind11/iostream.h"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/python/pybind11/pybind11.h"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/python/pybind11/buffer_info.h"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/python/pybind11/complex.h"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/python/pybind11/extensions.h"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/python/pybind11/numpy.h"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/python/pybind11/pytypes.h"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/python/pybind11/cast.h"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/python/pybind11/eigen.h"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/python/pybind11/functional.h"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/python/pybind11/operators.h"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/python/pybind11/stl_bind.h"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/python/pybind11/chrono.h"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/python/pybind11/embed.h"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/python/pybind11/gil.h"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/python/pybind11/options.h"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/python/pybind11/stl.h"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/Users/ben/Desktop/BA/src/DUNE/release-build/dune-common/dune/python/pybind11/detail/cmake_install.cmake")
  include("/Users/ben/Desktop/BA/src/DUNE/release-build/dune-common/dune/python/pybind11/eigen/cmake_install.cmake")
  include("/Users/ben/Desktop/BA/src/DUNE/release-build/dune-common/dune/python/pybind11/stl/cmake_install.cmake")

endif()

