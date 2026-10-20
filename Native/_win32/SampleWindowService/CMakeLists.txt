# Sources
file(GLOB SRCS_G "*.cpp")
MACRO_SOURCES_AUTO(SRCS ${SRCS_G})

# Headers
file(GLOB HDRS_G "*.h")
MACRO_HEADERS_AUTO(SRCS ${HDRS_G})

add_executable(SampleWindowService ${SRCS})
if(MSVC)
	set_target_properties (SampleWindowService PROPERTIES FOLDER "_win32/service" )
endif()

target_link_libraries(SampleWindowService PRIVATE SWSIntegrated)
