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
	add_executable(SampleWebServiceMFC WIN32 ${SRCS})
	target_sources(SampleWebServiceMFC PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/SWSMFCMain.rc)
	set_target_properties (SampleWebServiceMFC PROPERTIES FOLDER "_win32" )
	target_precompile_headers(SampleWebServiceMFC
	PRIVATE
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/pch.h>
	)
endif()

target_link_libraries(SampleWebServiceMFC PRIVATE BaseMFC GeneralUI SWSIntegrated)
