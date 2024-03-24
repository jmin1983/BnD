# http://www.cmake.org/Wiki/CMake_Useful_Variables

if(MSVC)
	set(STATIC_POSTFIX "md" CACHE STRING "Set static library postfix" FORCE)
else(MSVC)
    # Other compilers then MSVC don't have a static STATIC_POSTFIX at the moment
    set(STATIC_POSTFIX "" CACHE STRING "Set static library postfix" FORCE)
endif(MSVC)

if(MSVC)
set(CMAKE_CONFIGURATION_TYPES "Debug;Release;ReleaseMT" CACHE STRING "Set Configuration Types" FORCE)
set(CMAKE_RELEASEMT_POSTFIX "mt" CACHE STRING "Set ReleaseMT library postfix" FORCE)
add_compile_options($<$<CONFIG:ReleaseMT>:/MT>)
set(CMAKE_CXX_FLAGS_RELEASEMT "${CMAKE_CXX_FLAGS_RELEASE}")
set(CMAKE_EXE_LINKER_FLAGS_RELEASEMT "${CMAKE_EXE_LINKER_FLAGS_RELEASE}")
set(CMAKE_MODULE_LINKER_FLAGS_RELEASEMT "${CMAKE_MODULE_LINKER_FLAGS_RELEASE}")
set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/install CACHE STRING "Set Install Directory" FORCE)
endif(MSVC)

# Add a d postfix to the debug libraries
set(CMAKE_DEBUG_POSTFIX "${STATIC_POSTFIX}d" CACHE STRING "Set Debug library postfix" FORCE)
set(CMAKE_RELEASE_POSTFIX "${STATIC_POSTFIX}" CACHE STRING "Set Release library postfix" FORCE)
#set(STATIC_POSTFIX "a" CACHE STRING "Set Static library postfix" FORCE)

# OS Detection
include(CheckTypeSize)
find_package(Cygwin)
