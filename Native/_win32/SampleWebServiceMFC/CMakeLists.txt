# Sources
file(GLOB SRCS_G "*.cpp")
MACRO_SOURCES_AUTO(SRCS ${SRCS_G})

# Headers
file(GLOB HDRS_G "*.h")
MACRO_HEADERS_AUTO(SRCS ${HDRS_G})

if(MSVC)
	add_executable(SampleWebServiceMFC WIN32 ${SRCS})

	target_compile_definitions(SampleWebServiceMFC
		PRIVATE
		$<$<NOT:$<CONFIG:ReleaseMT>>:_AFXDLL>
	)

	target_sources(SampleWebServiceMFC PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/SWSMFCMain.rc)
	set_target_properties (SampleWebServiceMFC PROPERTIES FOLDER "_win32/service" )
	set_target_properties (SampleWebServiceMFC PROPERTIES LINK_FLAGS "/ignore:4099")
	target_precompile_headers(SampleWebServiceMFC
		PRIVATE
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/pch.h>
	)
endif()

target_link_libraries(SampleWebServiceMFC PRIVATE BaseMFC GeneralUI SWSIntegrated)
