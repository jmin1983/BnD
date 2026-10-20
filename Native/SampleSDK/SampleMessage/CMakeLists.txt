# Sources
file(GLOB SRCS_G "*.cpp")
MACRO_SOURCES_AUTO(SRCS ${SRCS_G})

# Headers
file(GLOB HDRS_G "*.h")
MACRO_HEADERS_AUTO(SRCS ${HDRS_G})

add_library(SampleMessage ${SRCS})
if(MSVC)
	target_precompile_headers(SampleMessage
	PRIVATE
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/SampleMessage.h>
	)
endif()

if(MSVC)
	set_target_properties (SampleMessage PROPERTIES FOLDER "SingalSDK" )
endif()

set_target_properties(SampleMessage
	PROPERTIES
	OUTPUT_NAME SampleMessage
)

target_include_directories(SampleMessage
	PRIVATE
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../B1>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../D1>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
)

if(WIN32)
	target_compile_definitions(SampleMessage PRIVATE _CRT_SECURE_NO_WARNINGS)
endif()
