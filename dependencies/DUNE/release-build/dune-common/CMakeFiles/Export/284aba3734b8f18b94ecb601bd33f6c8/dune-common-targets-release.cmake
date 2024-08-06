#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "dunecommon" for configuration "Release"
set_property(TARGET dunecommon APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(dunecommon PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libdunecommon.a"
  )

list(APPEND _cmake_import_check_targets dunecommon )
list(APPEND _cmake_import_check_files_for_dunecommon "${_IMPORT_PREFIX}/lib/libdunecommon.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
