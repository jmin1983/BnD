# Sources
file(GLOB SRCS_G "*.cpp")
MACRO_SOURCES_AUTO(SRCS ${SRCS_G})

# Headers
file(GLOB HDRS_G "*.h")
MACRO_HEADERS_AUTO(SRCS ${HDRS_G})

add_library(SWSStandard ${SRCS})
if(MSVC)
	target_precompile_headers(SWSStandard
	PRIVATE
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/SWSStandard.h>
	)
endif()

if(MSVC)
	set_target_properties (SWSStandard PROPERTIES FOLDER "appLib/SWS" )
endif()

set_target_properties(SWSStandard
	PROPERTIES
	OUTPUT_NAME SWSStandard
)

target_include_directories(SWSStandard
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
	PRIVATE
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../B1>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../D1>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../SampleSDK>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../SWSBase>
)

if(WIN32)
	target_compile_definitions(SWSStandard PRIVATE _CRT_SECURE_NO_WARNINGS)
endif()
