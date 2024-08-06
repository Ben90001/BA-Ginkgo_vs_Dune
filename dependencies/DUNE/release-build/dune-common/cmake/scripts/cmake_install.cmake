# Install script for directory: /Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/scripts

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/dune/cmake/scripts" TYPE FILE FILES
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/scripts/conf.py.in"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/scripts/CreateDoxyFile.cmake"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/scripts/venvpath.py"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/scripts/checkvenvconf.py"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/scripts/FinalizeHeadercheck.cmake"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/scripts/index.rst.in"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/scripts/InstallFile.cmake"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/scripts/main77.cc.in"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/scripts/module_library.cc.in"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/scripts/pyversion.py"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/scripts/RunDoxygen.cmake"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/scripts/setup.py.in"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/scripts/sphinx_cmake_dune.py"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/scripts/WritePythonCMakeMetadata.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/dune/cmake/scripts" TYPE PROGRAM FILES
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/scripts/extract_cmake_data.py"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/scripts/run-in-dune-env.sh.in"
    )
endif()

