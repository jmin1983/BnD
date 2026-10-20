# Sources
file(GLOB SRCS_G "*.cpp")
MACRO_SOURCES_AUTO(SRCS ${SRCS_G})

# Headers
file(GLOB HDRS_G "*.h")
MACRO_HEADERS_AUTO(SRCS ${HDRS_G})

add_library(SWSIntegrated ${SRCS})
if(MSVC)
	target_precompile_headers(SWSIntegrated
	PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/SWSIntegrated.h>
	)
endif()

if(MSVC)
	set_target_properties (SWSIntegrated PROPERTIES FOLDER "appLib/SWS" )
endif()

set_target_properties(SWSIntegrated
	PROPERTIES
	OUTPUT_NAME SWSIntegrated
)

target_include_directories(SWSIntegrated
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

target_link_libraries(SWSIntegrated PUBLIC SWSStandard SWSBase)
target_link_libraries(SWSIntegrated PUBLIC SampleDBClient SampleMessage SampleData SampleBase)
target_link_libraries(SWSIntegrated PUBLIC D1DBClient D1Message D1Data D1Base)
target_link_libraries(SWSIntegrated PUBLIC B1Http B1DBClient B1Crypto B1Redic B1Util B1Network)
if(NOT MSVC)
	target_link_libraries(SWSIntegrated PUBLIC z)
	target_link_libraries(SWSIntegrated PUBLIC ssl crypto)
	if(BUILD_EMBEDDED OR BUILD_EMBEDDED_32)
		target_link_libraries(SWSIntegrated PUBLIC boost_charconv)
	else()
		target_link_libraries(SWSIntegrated PUBLIC boost_charconv quadmath)
	endif()
endif()
target_link_libraries(SWSIntegrated PUBLIC B1Base)
