if(NOT dune-istl_FOUND)
# Whether this module is installed or not
set(dune-istl_INSTALLED OFF)

# Settings specific to the module

# Package initialization
# Set prefix to source dir
set(PACKAGE_PREFIX_DIR /Users/ben/Desktop/BA/src/DUNE/dune-istl)
macro(set_and_check _var _file)
  set(${_var} "${_file}")
  if(NOT EXISTS "${_file}")
    message(FATAL_ERROR "File or directory ${_file} referenced by variable ${_var} does not exist !")
  endif()
endmacro()

#report other information
set_and_check(dune-istl_PREFIX "${PACKAGE_PREFIX_DIR}")
set_and_check(dune-istl_INCLUDE_DIRS "/Users/ben/Desktop/BA/src/DUNE/dune-istl")
set(dune-istl_CXX_FLAGS "-std=c++17 ")
set(dune-istl_CXX_FLAGS_DEBUG "-g")
set(dune-istl_CXX_FLAGS_MINSIZEREL "-Os -DNDEBUG")
set(dune-istl_CXX_FLAGS_RELEASE "-O3 -DNDEBUG -g0 -funroll-loops -ftemplate-depth=5120 -march=native")
set(dune-istl_CXX_FLAGS_RELWITHDEBINFO "-O2 -g -DNDEBUG")
set(dune-istl_DEPENDS "dune-common (>= 2.9)")
set(dune-istl_SUGGESTS "")
set(dune-istl_MODULE_PATH "/Users/ben/Desktop/BA/src/DUNE/dune-istl/cmake/modules")
set(dune-istl_LIBRARIES "")
set(dune-istl_HASPYTHON 1)
set(dune-istl_PYTHONREQUIRES "")

# Lines that are set by the CMake build system via the variable DUNE_CUSTOM_PKG_CONFIG_SECTION


#import the target
if(dune-istl_LIBRARIES)
  get_filename_component(_dir "${CMAKE_CURRENT_LIST_FILE}" PATH)
  include("${_dir}/dune-istl-targets.cmake")
endif()

endif()
