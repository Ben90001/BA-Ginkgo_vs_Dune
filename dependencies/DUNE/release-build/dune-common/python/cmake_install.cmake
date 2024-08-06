# Install script for directory: /Users/ben/Desktop/BA/src/DUNE/dune-common/python

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
  set(CMAKE_MODULE_PATH /Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/modules)
                  set(DUNE_PYTHON_WHEELHOUSE /usr/local/share/dune/wheelhouse)
                  include(DuneExecuteProcess)
                  message("Installing python package")
                  dune_execute_process(COMMAND "/usr/local/Cellar/cmake/3.29.3/bin/cmake" --build .  --target install_python --config Release
                                       WARNING_MESSAGE "python package installation failed - ignored")
                  message("Installing wheel for python package at /Users/ben/Desktop/BA/src/DUNE/release-build/dune-common/python/. into /usr/local/share/dune/wheelhouse...")
                  dune_execute_process(COMMAND /Users/ben/Desktop/BA/src/DUNE/release-build/dune-python-env/bin/python;-m;pip;wheel;-w;/usr/local/share/dune/wheelhouse;--no-deps;;--find-links=file:///usr/local/share/dune/wheelhouse;/Users/ben/Desktop/BA/src/DUNE/release-build/dune-common/python/.
                                       WARNING_MESSAGE "wheel installation failed - ignored")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/Users/ben/Desktop/BA/src/DUNE/release-build/dune-common/python/dune/cmake_install.cmake")

endif()

