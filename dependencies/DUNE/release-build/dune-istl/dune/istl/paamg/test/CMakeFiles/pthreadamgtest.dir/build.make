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
include dune/istl/paamg/test/CMakeFiles/pthreadamgtest.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include dune/istl/paamg/test/CMakeFiles/pthreadamgtest.dir/compiler_depend.make

# Include the progress variables for this target.
include dune/istl/paamg/test/CMakeFiles/pthreadamgtest.dir/progress.make

# Include the compile flags for this target's objects.
include dune/istl/paamg/test/CMakeFiles/pthreadamgtest.dir/flags.make

dune/istl/paamg/test/CMakeFiles/pthreadamgtest.dir/pthreadamgtest.cc.o: dune/istl/paamg/test/CMakeFiles/pthreadamgtest.dir/flags.make
dune/istl/paamg/test/CMakeFiles/pthreadamgtest.dir/pthreadamgtest.cc.o: /Users/ben/Desktop/BA/src/DUNE/dune-istl/dune/istl/paamg/test/pthreadamgtest.cc
dune/istl/paamg/test/CMakeFiles/pthreadamgtest.dir/pthreadamgtest.cc.o: dune/istl/paamg/test/CMakeFiles/pthreadamgtest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/ben/Desktop/BA/src/DUNE/release-build/dune-istl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object dune/istl/paamg/test/CMakeFiles/pthreadamgtest.dir/pthreadamgtest.cc.o"
	cd /Users/ben/Desktop/BA/src/DUNE/release-build/dune-istl/dune/istl/paamg/test && /usr/local/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT dune/istl/paamg/test/CMakeFiles/pthreadamgtest.dir/pthreadamgtest.cc.o -MF CMakeFiles/pthreadamgtest.dir/pthreadamgtest.cc.o.d -o CMakeFiles/pthreadamgtest.dir/pthreadamgtest.cc.o -c /Users/ben/Desktop/BA/src/DUNE/dune-istl/dune/istl/paamg/test/pthreadamgtest.cc

dune/istl/paamg/test/CMakeFiles/pthreadamgtest.dir/pthreadamgtest.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/pthreadamgtest.dir/pthreadamgtest.cc.i"
	cd /Users/ben/Desktop/BA/src/DUNE/release-build/dune-istl/dune/istl/paamg/test && /usr/local/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ben/Desktop/BA/src/DUNE/dune-istl/dune/istl/paamg/test/pthreadamgtest.cc > CMakeFiles/pthreadamgtest.dir/pthreadamgtest.cc.i

dune/istl/paamg/test/CMakeFiles/pthreadamgtest.dir/pthreadamgtest.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/pthreadamgtest.dir/pthreadamgtest.cc.s"
	cd /Users/ben/Desktop/BA/src/DUNE/release-build/dune-istl/dune/istl/paamg/test && /usr/local/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ben/Desktop/BA/src/DUNE/dune-istl/dune/istl/paamg/test/pthreadamgtest.cc -o CMakeFiles/pthreadamgtest.dir/pthreadamgtest.cc.s

# Object files for target pthreadamgtest
pthreadamgtest_OBJECTS = \
"CMakeFiles/pthreadamgtest.dir/pthreadamgtest.cc.o"

# External object files for target pthreadamgtest
pthreadamgtest_EXTERNAL_OBJECTS =

dune/istl/paamg/test/pthreadamgtest: dune/istl/paamg/test/CMakeFiles/pthreadamgtest.dir/pthreadamgtest.cc.o
dune/istl/paamg/test/pthreadamgtest: dune/istl/paamg/test/CMakeFiles/pthreadamgtest.dir/build.make
dune/istl/paamg/test/pthreadamgtest: /Users/ben/Desktop/BA/src/DUNE/release-build/dune-common/lib/libdunecommon.a
dune/istl/paamg/test/pthreadamgtest: /usr/local/lib/libmetis.dylib
dune/istl/paamg/test/pthreadamgtest: /usr/local/lib/libtbb.12.13.dylib
dune/istl/paamg/test/pthreadamgtest: /usr/local/Cellar/gmp/6.3.0/lib/libgmpxx.dylib
dune/istl/paamg/test/pthreadamgtest: /usr/local/lib/libldl.dylib
dune/istl/paamg/test/pthreadamgtest: /usr/local/lib/libspqr.dylib
dune/istl/paamg/test/pthreadamgtest: /usr/local/lib/libumfpack.dylib
dune/istl/paamg/test/pthreadamgtest: /usr/local/lib/libcholmod.dylib
dune/istl/paamg/test/pthreadamgtest: /usr/local/lib/libamd.dylib
dune/istl/paamg/test/pthreadamgtest: /usr/local/lib/libcolamd.dylib
dune/istl/paamg/test/pthreadamgtest: /usr/local/lib/libcamd.dylib
dune/istl/paamg/test/pthreadamgtest: /usr/local/lib/libccolamd.dylib
dune/istl/paamg/test/pthreadamgtest: /usr/local/lib/libsuitesparseconfig.dylib
dune/istl/paamg/test/pthreadamgtest: /usr/local/Cellar/open-mpi/5.0.3_1/lib/libmpi.dylib
dune/istl/paamg/test/pthreadamgtest: /usr/local/Cellar/gmp/6.3.0/lib/libgmp.dylib
dune/istl/paamg/test/pthreadamgtest: dune/istl/paamg/test/CMakeFiles/pthreadamgtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/ben/Desktop/BA/src/DUNE/release-build/dune-istl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable pthreadamgtest"
	cd /Users/ben/Desktop/BA/src/DUNE/release-build/dune-istl/dune/istl/paamg/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pthreadamgtest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
dune/istl/paamg/test/CMakeFiles/pthreadamgtest.dir/build: dune/istl/paamg/test/pthreadamgtest
.PHONY : dune/istl/paamg/test/CMakeFiles/pthreadamgtest.dir/build

dune/istl/paamg/test/CMakeFiles/pthreadamgtest.dir/clean:
	cd /Users/ben/Desktop/BA/src/DUNE/release-build/dune-istl/dune/istl/paamg/test && $(CMAKE_COMMAND) -P CMakeFiles/pthreadamgtest.dir/cmake_clean.cmake
.PHONY : dune/istl/paamg/test/CMakeFiles/pthreadamgtest.dir/clean

dune/istl/paamg/test/CMakeFiles/pthreadamgtest.dir/depend:
	cd /Users/ben/Desktop/BA/src/DUNE/release-build/dune-istl && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ben/Desktop/BA/src/DUNE/dune-istl /Users/ben/Desktop/BA/src/DUNE/dune-istl/dune/istl/paamg/test /Users/ben/Desktop/BA/src/DUNE/release-build/dune-istl /Users/ben/Desktop/BA/src/DUNE/release-build/dune-istl/dune/istl/paamg/test /Users/ben/Desktop/BA/src/DUNE/release-build/dune-istl/dune/istl/paamg/test/CMakeFiles/pthreadamgtest.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : dune/istl/paamg/test/CMakeFiles/pthreadamgtest.dir/depend

