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
CMAKE_SOURCE_DIR = /Users/ben/Desktop/BA/src/DUNE/dune-istl

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ben/Desktop/BA/src/DUNE/release-build/dune-istl

# Include any dependencies generated for this target.
include dune/istl/test/CMakeFiles/solverfactorytest_DuneFieldVectorfloat2_direct.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include dune/istl/test/CMakeFiles/solverfactorytest_DuneFieldVectorfloat2_direct.dir/compiler_depend.make

# Include the progress variables for this target.
include dune/istl/test/CMakeFiles/solverfactorytest_DuneFieldVectorfloat2_direct.dir/progress.make

# Include the compile flags for this target's objects.
include dune/istl/test/CMakeFiles/solverfactorytest_DuneFieldVectorfloat2_direct.dir/flags.make

dune/istl/test/CMakeFiles/solverfactorytest_DuneFieldVectorfloat2_direct.dir/main77_solverfactorytest_DuneFieldVectorfloat2_direct.cc.o: dune/istl/test/CMakeFiles/solverfactorytest_DuneFieldVectorfloat2_direct.dir/flags.make
dune/istl/test/CMakeFiles/solverfactorytest_DuneFieldVectorfloat2_direct.dir/main77_solverfactorytest_DuneFieldVectorfloat2_direct.cc.o: dune/istl/test/main77_solverfactorytest_DuneFieldVectorfloat2_direct.cc
dune/istl/test/CMakeFiles/solverfactorytest_DuneFieldVectorfloat2_direct.dir/main77_solverfactorytest_DuneFieldVectorfloat2_direct.cc.o: dune/istl/test/CMakeFiles/solverfactorytest_DuneFieldVectorfloat2_direct.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/ben/Desktop/BA/src/DUNE/release-build/dune-istl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object dune/istl/test/CMakeFiles/solverfactorytest_DuneFieldVectorfloat2_direct.dir/main77_solverfactorytest_DuneFieldVectorfloat2_direct.cc.o"
	cd /Users/ben/Desktop/BA/src/DUNE/release-build/dune-istl/dune/istl/test && /usr/local/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT dune/istl/test/CMakeFiles/solverfactorytest_DuneFieldVectorfloat2_direct.dir/main77_solverfactorytest_DuneFieldVectorfloat2_direct.cc.o -MF CMakeFiles/solverfactorytest_DuneFieldVectorfloat2_direct.dir/main77_solverfactorytest_DuneFieldVectorfloat2_direct.cc.o.d -o CMakeFiles/solverfactorytest_DuneFieldVectorfloat2_direct.dir/main77_solverfactorytest_DuneFieldVectorfloat2_direct.cc.o -c /Users/ben/Desktop/BA/src/DUNE/release-build/dune-istl/dune/istl/test/main77_solverfactorytest_DuneFieldVectorfloat2_direct.cc

dune/istl/test/CMakeFiles/solverfactorytest_DuneFieldVectorfloat2_direct.dir/main77_solverfactorytest_DuneFieldVectorfloat2_direct.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/solverfactorytest_DuneFieldVectorfloat2_direct.dir/main77_solverfactorytest_DuneFieldVectorfloat2_direct.cc.i"
	cd /Users/ben/Desktop/BA/src/DUNE/release-build/dune-istl/dune/istl/test && /usr/local/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ben/Desktop/BA/src/DUNE/release-build/dune-istl/dune/istl/test/main77_solverfactorytest_DuneFieldVectorfloat2_direct.cc > CMakeFiles/solverfactorytest_DuneFieldVectorfloat2_direct.dir/main77_solverfactorytest_DuneFieldVectorfloat2_direct.cc.i

dune/istl/test/CMakeFiles/solverfactorytest_DuneFieldVectorfloat2_direct.dir/main77_solverfactorytest_DuneFieldVectorfloat2_direct.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/solverfactorytest_DuneFieldVectorfloat2_direct.dir/main77_solverfactorytest_DuneFieldVectorfloat2_direct.cc.s"
	cd /Users/ben/Desktop/BA/src/DUNE/release-build/dune-istl/dune/istl/test && /usr/local/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ben/Desktop/BA/src/DUNE/release-build/dune-istl/dune/istl/test/main77_solverfactorytest_DuneFieldVectorfloat2_direct.cc -o CMakeFiles/solverfactorytest_DuneFieldVectorfloat2_direct.dir/main77_solverfactorytest_DuneFieldVectorfloat2_direct.cc.s

# Object files for target solverfactorytest_DuneFieldVectorfloat2_direct
solverfactorytest_DuneFieldVectorfloat2_direct_OBJECTS = \
"CMakeFiles/solverfactorytest_DuneFieldVectorfloat2_direct.dir/main77_solverfactorytest_DuneFieldVectorfloat2_direct.cc.o"

# External object files for target solverfactorytest_DuneFieldVectorfloat2_direct
solverfactorytest_DuneFieldVectorfloat2_direct_EXTERNAL_OBJECTS =

dune/istl/test/solverfactorytest_DuneFieldVectorfloat2_direct: dune/istl/test/CMakeFiles/solverfactorytest_DuneFieldVectorfloat2_direct.dir/main77_solverfactorytest_DuneFieldVectorfloat2_direct.cc.o
dune/istl/test/solverfactorytest_DuneFieldVectorfloat2_direct: dune/istl/test/CMakeFiles/solverfactorytest_DuneFieldVectorfloat2_direct.dir/build.make
dune/istl/test/solverfactorytest_DuneFieldVectorfloat2_direct: /Users/ben/Desktop/BA/src/DUNE/release-build/dune-common/lib/libdunecommon.a
dune/istl/test/solverfactorytest_DuneFieldVectorfloat2_direct: /usr/local/lib/libmetis.dylib
dune/istl/test/solverfactorytest_DuneFieldVectorfloat2_direct: /usr/local/lib/libtbb.12.13.dylib
dune/istl/test/solverfactorytest_DuneFieldVectorfloat2_direct: /usr/local/Cellar/gmp/6.3.0/lib/libgmpxx.dylib
dune/istl/test/solverfactorytest_DuneFieldVectorfloat2_direct: /usr/local/lib/libldl.dylib
dune/istl/test/solverfactorytest_DuneFieldVectorfloat2_direct: /usr/local/lib/libspqr.dylib
dune/istl/test/solverfactorytest_DuneFieldVectorfloat2_direct: /usr/local/lib/libumfpack.dylib
dune/istl/test/solverfactorytest_DuneFieldVectorfloat2_direct: /usr/local/lib/libcholmod.dylib
dune/istl/test/solverfactorytest_DuneFieldVectorfloat2_direct: /usr/local/lib/libamd.dylib
dune/istl/test/solverfactorytest_DuneFieldVectorfloat2_direct: /usr/local/lib/libcolamd.dylib
dune/istl/test/solverfactorytest_DuneFieldVectorfloat2_direct: /usr/local/lib/libcamd.dylib
dune/istl/test/solverfactorytest_DuneFieldVectorfloat2_direct: /usr/local/lib/libccolamd.dylib
dune/istl/test/solverfactorytest_DuneFieldVectorfloat2_direct: /usr/local/lib/libsuitesparseconfig.dylib
dune/istl/test/solverfactorytest_DuneFieldVectorfloat2_direct: /usr/local/Cellar/open-mpi/5.0.3_1/lib/libmpi.dylib
dune/istl/test/solverfactorytest_DuneFieldVectorfloat2_direct: /usr/local/Cellar/gmp/6.3.0/lib/libgmp.dylib
dune/istl/test/solverfactorytest_DuneFieldVectorfloat2_direct: dune/istl/test/CMakeFiles/solverfactorytest_DuneFieldVectorfloat2_direct.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/ben/Desktop/BA/src/DUNE/release-build/dune-istl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable solverfactorytest_DuneFieldVectorfloat2_direct"
	cd /Users/ben/Desktop/BA/src/DUNE/release-build/dune-istl/dune/istl/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/solverfactorytest_DuneFieldVectorfloat2_direct.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
dune/istl/test/CMakeFiles/solverfactorytest_DuneFieldVectorfloat2_direct.dir/build: dune/istl/test/solverfactorytest_DuneFieldVectorfloat2_direct
.PHONY : dune/istl/test/CMakeFiles/solverfactorytest_DuneFieldVectorfloat2_direct.dir/build

dune/istl/test/CMakeFiles/solverfactorytest_DuneFieldVectorfloat2_direct.dir/clean:
	cd /Users/ben/Desktop/BA/src/DUNE/release-build/dune-istl/dune/istl/test && $(CMAKE_COMMAND) -P CMakeFiles/solverfactorytest_DuneFieldVectorfloat2_direct.dir/cmake_clean.cmake
.PHONY : dune/istl/test/CMakeFiles/solverfactorytest_DuneFieldVectorfloat2_direct.dir/clean

dune/istl/test/CMakeFiles/solverfactorytest_DuneFieldVectorfloat2_direct.dir/depend:
	cd /Users/ben/Desktop/BA/src/DUNE/release-build/dune-istl && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ben/Desktop/BA/src/DUNE/dune-istl /Users/ben/Desktop/BA/src/DUNE/dune-istl/dune/istl/test /Users/ben/Desktop/BA/src/DUNE/release-build/dune-istl /Users/ben/Desktop/BA/src/DUNE/release-build/dune-istl/dune/istl/test /Users/ben/Desktop/BA/src/DUNE/release-build/dune-istl/dune/istl/test/CMakeFiles/solverfactorytest_DuneFieldVectorfloat2_direct.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : dune/istl/test/CMakeFiles/solverfactorytest_DuneFieldVectorfloat2_direct.dir/depend

