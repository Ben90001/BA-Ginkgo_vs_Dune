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

# Include any dependencies generated for this target.
include dune/common/parallel/test/CMakeFiles/syncertest.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include dune/common/parallel/test/CMakeFiles/syncertest.dir/compiler_depend.make

# Include the progress variables for this target.
include dune/common/parallel/test/CMakeFiles/syncertest.dir/progress.make

# Include the compile flags for this target's objects.
include dune/common/parallel/test/CMakeFiles/syncertest.dir/flags.make

dune/common/parallel/test/CMakeFiles/syncertest.dir/syncertest.cc.o: dune/common/parallel/test/CMakeFiles/syncertest.dir/flags.make
dune/common/parallel/test/CMakeFiles/syncertest.dir/syncertest.cc.o: /Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/parallel/test/syncertest.cc
dune/common/parallel/test/CMakeFiles/syncertest.dir/syncertest.cc.o: dune/common/parallel/test/CMakeFiles/syncertest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/ben/Desktop/BA/src/DUNE/release-build/dune-common/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object dune/common/parallel/test/CMakeFiles/syncertest.dir/syncertest.cc.o"
	cd /Users/ben/Desktop/BA/src/DUNE/release-build/dune-common/dune/common/parallel/test && /usr/local/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT dune/common/parallel/test/CMakeFiles/syncertest.dir/syncertest.cc.o -MF CMakeFiles/syncertest.dir/syncertest.cc.o.d -o CMakeFiles/syncertest.dir/syncertest.cc.o -c /Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/parallel/test/syncertest.cc

dune/common/parallel/test/CMakeFiles/syncertest.dir/syncertest.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/syncertest.dir/syncertest.cc.i"
	cd /Users/ben/Desktop/BA/src/DUNE/release-build/dune-common/dune/common/parallel/test && /usr/local/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/parallel/test/syncertest.cc > CMakeFiles/syncertest.dir/syncertest.cc.i

dune/common/parallel/test/CMakeFiles/syncertest.dir/syncertest.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/syncertest.dir/syncertest.cc.s"
	cd /Users/ben/Desktop/BA/src/DUNE/release-build/dune-common/dune/common/parallel/test && /usr/local/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/parallel/test/syncertest.cc -o CMakeFiles/syncertest.dir/syncertest.cc.s

# Object files for target syncertest
syncertest_OBJECTS = \
"CMakeFiles/syncertest.dir/syncertest.cc.o"

# External object files for target syncertest
syncertest_EXTERNAL_OBJECTS =

dune/common/parallel/test/syncertest: dune/common/parallel/test/CMakeFiles/syncertest.dir/syncertest.cc.o
dune/common/parallel/test/syncertest: dune/common/parallel/test/CMakeFiles/syncertest.dir/build.make
dune/common/parallel/test/syncertest: /usr/local/lib/libmetis.dylib
dune/common/parallel/test/syncertest: /usr/local/Cellar/gmp/6.3.0/lib/libgmpxx.dylib
dune/common/parallel/test/syncertest: lib/libdunecommon.a
dune/common/parallel/test/syncertest: /usr/local/Cellar/open-mpi/5.0.3_1/lib/libmpi.dylib
dune/common/parallel/test/syncertest: /usr/local/Cellar/gmp/6.3.0/lib/libgmp.dylib
dune/common/parallel/test/syncertest: /usr/local/lib/libtbb.12.13.dylib
dune/common/parallel/test/syncertest: dune/common/parallel/test/CMakeFiles/syncertest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/ben/Desktop/BA/src/DUNE/release-build/dune-common/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable syncertest"
	cd /Users/ben/Desktop/BA/src/DUNE/release-build/dune-common/dune/common/parallel/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/syncertest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
dune/common/parallel/test/CMakeFiles/syncertest.dir/build: dune/common/parallel/test/syncertest
.PHONY : dune/common/parallel/test/CMakeFiles/syncertest.dir/build

dune/common/parallel/test/CMakeFiles/syncertest.dir/clean:
	cd /Users/ben/Desktop/BA/src/DUNE/release-build/dune-common/dune/common/parallel/test && $(CMAKE_COMMAND) -P CMakeFiles/syncertest.dir/cmake_clean.cmake
.PHONY : dune/common/parallel/test/CMakeFiles/syncertest.dir/clean

dune/common/parallel/test/CMakeFiles/syncertest.dir/depend:
	cd /Users/ben/Desktop/BA/src/DUNE/release-build/dune-common && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ben/Desktop/BA/src/DUNE/dune-common /Users/ben/Desktop/BA/src/DUNE/dune-common/dune/common/parallel/test /Users/ben/Desktop/BA/src/DUNE/release-build/dune-common /Users/ben/Desktop/BA/src/DUNE/release-build/dune-common/dune/common/parallel/test /Users/ben/Desktop/BA/src/DUNE/release-build/dune-common/dune/common/parallel/test/CMakeFiles/syncertest.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : dune/common/parallel/test/CMakeFiles/syncertest.dir/depend

