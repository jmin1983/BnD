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

add_library(SWSBase ${SRCS})
if(MSVC)
	target_precompile_headers(SWSBase
	PRIVATE
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/SWSBase.h>
	)
endif()

if(MSVC)
	set_target_properties (SWSBase PROPERTIES FOLDER "appLib" )
endif()

set_target_properties(SWSBase
	PROPERTIES
	OUTPUT_NAME SWSBase
)

target_include_directories(SWSBase
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
	PRIVATE
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../B1>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../D1>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../SampleSDK>
)

if(WIN32)
	target_compile_definitions(SWSBase PRIVATE _CRT_SECURE_NO_WARNINGS)
endif()
