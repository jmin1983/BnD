cmake_minimum_required(VERSION 3.29.0)

if(POLICY CMP0091)
    cmake_policy(SET CMP0091 NEW)
endif()

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

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/external/include)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)
if(MSVC)
	if(CMAKE_SIZEOF_VOID_P EQUAL 8)
		set(EXTERNAL_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external/lib/win_x64 CACHE STRING "Set External Library Path")
	else()
		set(EXTERNAL_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external/lib/win_x32 CACHE STRING "Set External Library Path")
	endif()
else()
	if(BUILD_EMBEDDED)
		set(EXTERNAL_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external/lib/aarch64 CACHE STRING "Set External Library Path")
	elseif(BUILD_EMBEDDED_32)
		set(EXTERNAL_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external/lib/arm CACHE STRING "Set External Library Path")
	else()
		set(EXTERNAL_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external/lib/linux_x64 CACHE STRING "Set External Library Path")
	endif()
endif()
link_directories(${EXTERNAL_LIB_DIR})

if(MSVC)
	add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
	add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
	set_property(GLOBAL PROPERTY USE_FOLDERS TRUE)
	set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "zzCMakePredefinedTargets")
endif()

# add directories to build.
set(BUILD_COMPONENTS "")
add_subdirectory(B1)
add_subdirectory(D1)
add_subdirectory(SampleSDK)
if(NOT BUILD_CONTROLLER_ONLY)
	add_subdirectory(SampleWebService)
	if(MSVC)
		add_subdirectory(_win32)
	endif()
endif()

foreach(component ${BUILD_COMPONENTS})
	message(STATUS "Building: ${component}")
endforeach()
