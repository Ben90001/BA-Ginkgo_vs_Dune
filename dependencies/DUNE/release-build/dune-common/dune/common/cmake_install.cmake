# Install script for directory: /Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/dune/common" TYPE FILE FILES
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/alignedallocator.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/arraylist.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/assertandreturn.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/bartonnackmanifcheck.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/bigunsignedint.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/binaryfunctions.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/bitsetvector.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/boundschecking.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/classname.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/concept.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/conditional.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/debugalign.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/debugallocator.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/debugstream.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/deprecated.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/densematrix.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/densevector.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/diagonalmatrix.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/documentation.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/dotproduct.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/dynmatrix.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/dynmatrixev.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/dynvector.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/enumset.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/exceptions.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/filledarray.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/float_cmp.cc"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/float_cmp.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/fmatrix.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/fmatrixev.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/ftraits.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/function.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/fvector.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/genericiterator.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/gmpfield.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/hash.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/hybridutilities.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/indent.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/indices.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/interfaces.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/ios_state.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/iteratorfacades.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/iteratorrange.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/keywords.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/lru.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/mallocallocator.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/math.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/matrixconcepts.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/matvectraits.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/overloadset.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/parameterizedobject.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/parametertree.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/parametertreeparser.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/path.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/poolallocator.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/power.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/precision.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/propertymap.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/promotiontraits.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/proxymemberaccess.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/quadmath.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/rangeutilities.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/referencehelper.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/reservedvector.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/scalarvectorview.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/scalarmatrixview.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/shared_ptr.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/simd.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/singleton.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/sllist.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/stdstreams.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/stdthread.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/streamoperators.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/stringutility.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/to_unique_ptr.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/timer.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/transpose.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/tupleutility.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/tuplevector.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/typelist.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/typetraits.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/typeutilities.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/unused.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/vc.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/version.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/visibility.hh"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/dune/common/test" TYPE FILE FILES
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/test/iteratortest.hh"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/test/checkmatrixinterface.hh"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/Users/ben/Desktop/BA/src/DUNE/release-build/dune-common/dune/common/parallel/cmake_install.cmake")
  include("/Users/ben/Desktop/BA/src/DUNE/release-build/dune-common/dune/common/simd/cmake_install.cmake")
  include("/Users/ben/Desktop/BA/src/DUNE/release-build/dune-common/dune/common/std/cmake_install.cmake")
  include("/Users/ben/Desktop/BA/src/DUNE/release-build/dune-common/dune/common/test/cmake_install.cmake")

endif()

