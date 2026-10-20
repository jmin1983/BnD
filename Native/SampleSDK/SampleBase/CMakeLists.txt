# Sources
file(GLOB SRCS_G "*.cpp")
MACRO_SOURCES_AUTO(SRCS ${SRCS_G})

# Headers
file(GLOB HDRS_G "*.h")
MACRO_HEADERS_AUTO(SRCS ${HDRS_G})

add_library(SampleBase ${SRCS})
if(MSVC)
	target_precompile_headers(SampleBase
	PRIVATE
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/SampleBase.h>
	)
endif()

if(MSVC)
	set_target_properties (SampleBase PROPERTIES FOLDER "SingalSDK" )
endif()

set_target_properties(SampleBase
	PROPERTIES
	OUTPUT_NAME SampleBase
)

target_include_directories(SampleBase
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
	PRIVATE
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../B1>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../D1>
)

if(WIN32)
	target_compile_definitions(SampleBase PRIVATE _CRT_SECURE_NO_WARNINGS)
endif()
