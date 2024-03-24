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

add_library(SWSIntegrated ${SRCS})
if(MSVC)
	target_precompile_headers(SWSIntegrated
	PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/SWSIntegrated.h>
	)
endif()

if(MSVC)
	set_target_properties (SWSIntegrated PROPERTIES FOLDER "appLib" )
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
if(MSVC)
	target_link_directories(SWSIntegrated PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../external/lib/win32)
else()
	target_link_libraries(SWSIntegrated PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../external/lib/linux/libcrypto_x64.a)
	target_link_libraries(SWSIntegrated PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../external/lib/linux/libssl_x64.a)
endif()
target_link_libraries(SWSIntegrated PUBLIC B1Base)
