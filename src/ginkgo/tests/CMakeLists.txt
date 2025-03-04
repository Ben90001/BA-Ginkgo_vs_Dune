cmake_minimum_required(VERSION 3.16)

#NOTE: apple clang 15 is tested according to GINKGO Github, so this should not be necessary
#NOTE: GINKGO is compiled using apple clang, using gcc would require reinstalling it
#set(CMAKE_C_COMPILER "/usr/local/bin/gcc-14")
#set(CMAKE_CXX_COMPILER "/usr/local/bin/gcc-14")

project(gko_testing)

find_package(Ginkgo REQUIRED)
find_package(OpenMP 3.0 REQUIRED)
find_package(CUDAToolkit REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#include(FetchContent)
#FetchContent_Declare(
#	ginkgo
#	URL https://github.com/ginkgo-project/ginkgo/releases/tag/v1.7.0
#)
#set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
#FetchContent_MakeAvailable(googletest)


enable_testing()

add_executable(
	ginkgo-testing
	ginkgo-testing.cc
)

target_link_libraries(
	ginkgo-testing
	Ginkgo::ginkgo
)

#include_directories(
#	/home/benh/BA-Ginkgo_vs_Dune/dependencies/GINKGO/ginkgo-1.8.0/include
#	/home/benh/BA-Ginkgo_vs_Dune/dependencies/GINKGO/ginkgo-1.8.0/build/include
#)
#target_link_libraries(gko-evaluate-solvers 
#	/home/benh/BA-Ginkgo_vs_Dune/dependencies/GINKGO/ginkgo-1.8.0/build/lib/libginkgo.so
#	/home/benh/BA-Ginkgo_vs_Dune/dependencies/GINKGO/ginkgo-1.8.0/build/lib/libginkgo.so.1.8.0
#)


#include(Ginkgo)
#gtest_discover_tests(main)
