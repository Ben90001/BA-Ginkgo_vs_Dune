# CMake generated Testfile for 
# Source directory: /Users/ben/Desktop/BA/src/DUNE/dune-istl/dune/python/test
# Build directory: /Users/ben/Desktop/BA/src/DUNE/release-build/dune-istl/dune/python/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(pybcrsmatrix "/Users/ben/Desktop/BA/src/DUNE/release-build/dune-istl/run-in-dune-env" "python" "bcrsmatrix.py")
set_tests_properties(pybcrsmatrix PROPERTIES  LABELS "quick;python" PROCESSORS "1" SKIP_RETURN_CODE "77" TIMEOUT "3600" WORKING_DIRECTORY "/Users/ben/Desktop/BA/src/DUNE/dune-istl/dune/python/test" _BACKTRACE_TRIPLES "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/modules/DuneTestMacros.cmake;414;_add_test;/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/modules/DunePythonTestCommand.cmake;102;dune_add_test;/Users/ben/Desktop/BA/src/DUNE/dune-istl/dune/python/test/CMakeLists.txt;4;dune_python_add_test;/Users/ben/Desktop/BA/src/DUNE/dune-istl/dune/python/test/CMakeLists.txt;0;")
