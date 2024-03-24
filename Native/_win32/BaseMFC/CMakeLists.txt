# Sources
file(GLOB SRCS_G "*.cpp")
MACRO_SOURCES_AUTO(SRCS ${SRCS_G})

# Headers
file(GLOB HDRS_G "*.h")
MACRO_HEADERS_AUTO(SRCS ${HDRS_G})

set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost ${REQUIRED_BOOST_VERSION})

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS}) 
endif()

if(MSVC)
	add_definitions(-D_AFXDLL)
	set(CMAKE_MFC_FLAG 2)
	add_library(BaseMFC ${SRCS})
	target_precompile_headers(BaseMFC
	PRIVATE
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/pch.h>
	)
endif()

if(MSVC)
	set_target_properties (BaseMFC PROPERTIES FOLDER "_win32" )
endif()

set_target_properties(BaseMFC
	PROPERTIES
	OUTPUT_NAME BaseMFC
)

target_include_directories(BaseMFC
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
	PRIVATE
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../GeneralUI>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../D1>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../B1>
)

if(WIN32)
	target_compile_definitions(BaseMFC PRIVATE _CRT_SECURE_NO_WARNINGS)
endif()
