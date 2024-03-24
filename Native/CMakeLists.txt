cmake_minimum_required(VERSION 3.29.0)

project(BnD)

# Read the version information from the VERSION file
file(STRINGS "${PROJECT_SOURCE_DIR}/VERSION" PACKAGE_VERSION)
string(REGEX REPLACE "([0-9]+)\\.[0-9]+\\.[0-9]+.*" "\\1" CPACK_PACKAGE_VERSION_MAJOR ${PACKAGE_VERSION})
string(REGEX REPLACE "[0-9]+\\.([0-9]+)\\.[0-9]+.*" "\\1" CPACK_PACKAGE_VERSION_MINOR ${PACKAGE_VERSION})
string(REGEX REPLACE "[0-9]+\\.[0-9]+\\.([0-9]+).*" "\\1" CPACK_PACKAGE_VERSION_PATCH ${PACKAGE_VERSION})
set(PROJECT_VERSION ${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}.${CPACK_PACKAGE_VERSION_PATCH})

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Append our module directory to CMake
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
include(ConvMacros)
include(DefinePlatformSpecifc)

# Setup C/C++ compiler options
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
if(MSVC)
	set(CMAKE_CXX_SCAN_FOR_MODULES OFF)
endif()

option(BUILD_SHARED_LIBS "Build shared libraries" OFF)
if(MSVC)
	set(Boost_INCLUDE_DIR "C:/Program Files/boost/boost_1_84_0" CACHE STRING "Set Boost Library Path" FORCE)
endif()
set(REQUIRED_BOOST_VERSION, "1.84.0")

if(MSVC)
	add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
	add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
	set_property(GLOBAL PROPERTY USE_FOLDERS TRUE)
	set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "zzCMakePredefinedTargets")
endif()

# Collect the built libraries and include dirs.
set(BnD_COMPONENTS "")
add_subdirectory(B1)
add_subdirectory(D1)
add_subdirectory(SampleSDK)
add_subdirectory(SampleWebService)
if(MSVC)
	add_subdirectory(_win32)
endif()

foreach(component ${BnD_COMPONENTS})
	message(STATUS "Building: ${component}")
endforeach()
