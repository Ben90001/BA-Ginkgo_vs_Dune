# SPDX-FileCopyrightInfo: Copyright (C) DUNE Project contributors, see file LICENSE.md in module root
# SPDX-License-Identifier: LicenseRef-GPL-2.0-only-with-DUNE-exception

if(NOT dune-common_FOUND)
# Set prefix to source dir
set(PACKAGE_PREFIX_DIR /Users/ben/Desktop/BA/src/DUNE/dune-common)
macro(set_and_check _var _file)
  set(${_var} "${_file}")
  if(NOT EXISTS "${_file}")
    message(FATAL_ERROR "File or directory ${_file} referenced by variable ${_var} does not exist !")
  endif()
endmacro()

#import the target
get_filename_component(_dir "${CMAKE_CURRENT_LIST_FILE}" PATH)
include("${_dir}/dune-common-targets.cmake")

#report other information
set_and_check(dune-common_PREFIX "${PACKAGE_PREFIX_DIR}")
set_and_check(dune-common_INCLUDE_DIRS "/Users/ben/Desktop/BA/src/DUNE/dune-common")
set(dune-common_CXX_FLAGS "-std=c++17 ")
set(dune-common_CXX_FLAGS_DEBUG "-g")
set(dune-common_CXX_FLAGS_MINSIZEREL "-Os -DNDEBUG")
set(dune-common_CXX_FLAGS_RELEASE "-O3 -DNDEBUG -g0 -funroll-loops -ftemplate-depth=5120 -march=native")
set(dune-common_CXX_FLAGS_RELWITHDEBINFO "-O2 -g -DNDEBUG")
set(dune-common_LIBRARIES "dunecommon")
set_and_check(dune-common_SCRIPT_DIR "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/scripts")
set_and_check(DOXYSTYLE_FILE "/Users/ben/Desktop/BA/src/DUNE/dune-common/doc/doxygen/Doxystyle")
set_and_check(DOXYGENMACROS_FILE "/Users/ben/Desktop/BA/src/DUNE/dune-common/doc/doxygen/doxygen-macros")
set(dune-common_DEPENDS "")
set(dune-common_SUGGESTS "")
set(dune-common_HASPYTHON 1)
set(dune-common_PYTHONREQUIRES "pip>=21.a portalocker numpy wheel setuptools>=41 jinja2")
set_and_check(dune-common_MODULE_PATH "/Users/ben/Desktop/BA/src/DUNE/dune-common/cmake/modules")
endif(NOT dune-common_FOUND)
