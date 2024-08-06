# Install script for directory: /Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/modules

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/dune/cmake/modules" TYPE FILE FILES
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/modules/AddBLASLapackFlags.cmake"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/modules/AddGMPFlags.cmake"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/modules/AddMETISFlags.cmake"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/modules/AddMPIFlags.cmake"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/modules/AddParMETISFlags.cmake"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/modules/AddPTScotchFlags.cmake"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/modules/AddQuadMathFlags.cmake"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/modules/AddTBBFlags.cmake"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/modules/AddThreadsFlags.cmake"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/modules/AddSuiteSparseFlags.cmake"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/modules/AddVcFlags.cmake"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/modules/CheckCXXFeatures.cmake"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/modules/CMakeBuiltinFunctionsDocumentation.cmake"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/modules/DuneAddLibrary.cmake"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/modules/DuneAddPybind11Module.cmake"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/modules/DuneCMakeCompat.cmake"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/modules/DuneCommonMacros.cmake"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/modules/DuneDoc.cmake"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/modules/DuneDoxygen.cmake"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/modules/DuneEnableAllPackages.cmake"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/modules/DuneExecuteProcess.cmake"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/modules/DuneInstance.cmake"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/modules/DuneMacros.cmake"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/modules/DuneModuleDependencies.cmake"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/modules/DuneModuleInformation.cmake"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/modules/DunePathHelper.cmake"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/modules/DunePkgConfig.cmake"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/modules/DuneProject.cmake"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/modules/DunePythonCommonMacros.cmake"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/modules/DunePythonDeprecations.cmake"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/modules/DunePythonFindPackage.cmake"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/modules/DunePythonInstallPackage.cmake"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/modules/DunePythonTestCommand.cmake"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/modules/DunePythonVirtualenv.cmake"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/modules/DuneReplaceProperties.cmake"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/modules/DuneSphinxDoc.cmake"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/modules/DuneSphinxCMakeDoc.cmake"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/modules/DuneStreams.cmake"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/modules/DuneSymlinkOrCopy.cmake"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/modules/DuneTestMacros.cmake"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/modules/DuneUtilities.cmake"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/modules/FindGMP.cmake"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/modules/FindInkscape.cmake"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/modules/FindLatexMk.cmake"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/modules/FindMETIS.cmake"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/modules/FindParMETIS.cmake"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/modules/FindPTScotch.cmake"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/modules/FindQuadMath.cmake"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/modules/FindSphinx.cmake"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/modules/FindSuiteSparse.cmake"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/modules/FindTBB.cmake"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/modules/Headercheck.cmake"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/modules/latexmkrc.cmake"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/modules/OverloadCompilerFlags.cmake"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/modules/UseInkscape.cmake"
    "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/modules/UseLatexMk.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/Users/ben/Desktop/BA/src/DUNE/release-build/dune-common/cmake/modules/FindPkgConfig/cmake_install.cmake")
  include("/Users/ben/Desktop/BA/src/DUNE/release-build/dune-common/cmake/modules/FindPython3/cmake_install.cmake")

endif()

