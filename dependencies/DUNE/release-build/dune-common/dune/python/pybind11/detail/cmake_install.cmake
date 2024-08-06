# Install script for directory: /Users/ben/Desktop/BA/src/DUNE/dune-common/dune/python/pybind11/detail

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/dune/python/pybind11/detail" TYPE FILE FILES
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/python/pybind11/detail/class.h"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/python/pybind11/detail/common.h"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/python/pybind11/detail/descr.h"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/python/pybind11/detail/init.h"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/python/pybind11/detail/internals.h"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/python/pybind11/detail/type_caster_base.h"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/python/pybind11/detail/typeid.h"
    )
endif()

