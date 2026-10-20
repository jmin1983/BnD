# Sources
file(GLOB SRCS_G "*.cpp")
MACRO_SOURCES_AUTO(SRCS ${SRCS_G})

# Headers
file(GLOB HDRS_G "*.h")
MACRO_HEADERS_AUTO(SRCS ${HDRS_G})

add_executable(SampleWebService ${SRCS})
if(MSVC)
	set_target_properties (SampleWebService PROPERTIES FOLDER "app" )
	set_target_properties (SampleWebService PROPERTIES LINK_FLAGS "/ignore:4099")
endif()

target_link_libraries(SampleWebService PRIVATE SWSIntegrated)
