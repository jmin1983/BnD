# Sources
file(GLOB SRCS_G "*.cpp")
MACRO_SOURCES_AUTO(SRCS ${SRCS_G})

# Headers
file(GLOB HDRS_G "*.h")
MACRO_HEADERS_AUTO(SRCS ${HDRS_G})

if(MSVC)
	add_library(GeneralUI ${SRCS})

	target_compile_definitions(GeneralUI
		PRIVATE
		$<$<NOT:$<CONFIG:ReleaseMT>>:_AFXDLL>
	)

	target_precompile_headers(GeneralUI
		PRIVATE
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/pch.h>
	)
endif()

if(MSVC)
	set_target_properties (GeneralUI PROPERTIES FOLDER "_win32/base" )
endif()

set_target_properties(GeneralUI
	PROPERTIES
	OUTPUT_NAME GeneralUI
)

target_include_directories(GeneralUI
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
	PRIVATE
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../B1>
)

if(WIN32)
	target_compile_definitions(GeneralUI PRIVATE _CRT_SECURE_NO_WARNINGS)
endif()
