# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.29.3/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.29.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ben/Desktop/BA/src/DUNE/dune-common

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ben/Desktop/BA/src/DUNE/release-build/dune-common

# Utility rule file for build_tests.

# Include any custom commands dependencies for this target.
include CMakeFiles/build_tests.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/build_tests.dir/progress.make

build_tests: CMakeFiles/build_tests.dir/build.make
.PHONY : build_tests

# Rule to build all files generated by this target.
CMakeFiles/build_tests.dir/build: build_tests
.PHONY : CMakeFiles/build_tests.dir/build

CMakeFiles/build_tests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/build_tests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/build_tests.dir/clean

CMakeFiles/build_tests.dir/depend:
	cd /Users/ben/Desktop/BA/src/DUNE/release-build/dune-common && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ben/Desktop/BA/src/DUNE/dune-common /Users/ben/Desktop/BA/src/DUNE/dune-common /Users/ben/Desktop/BA/src/DUNE/release-build/dune-common /Users/ben/Desktop/BA/src/DUNE/release-build/dune-common /Users/ben/Desktop/BA/src/DUNE/release-build/dune-common/CMakeFiles/build_tests.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/build_tests.dir/depend

