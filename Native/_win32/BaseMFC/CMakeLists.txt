# Sources
file(GLOB SRCS_G "*.cpp")
MACRO_SOURCES_AUTO(SRCS ${SRCS_G})

# Headers
file(GLOB HDRS_G "*.h")
MACRO_HEADERS_AUTO(SRCS ${HDRS_G})

if(MSVC)
	add_library(BaseMFC ${SRCS})

	target_compile_definitions(BaseMFC
		PRIVATE
		$<$<NOT:$<CONFIG:ReleaseMT>>:_AFXDLL>
	)

	target_precompile_headers(BaseMFC
		PRIVATE
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/pch.h>
	)
endif()

if(MSVC)
	set_target_properties (BaseMFC PROPERTIES FOLDER "_win32/base" )
endif()

set_target_properties(BaseMFC
	PROPERTIES
	OUTPUT_NAME BaseMFC
)

target_include_directories(BaseMFC
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
	PRIVATE
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../GeneralUI>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../D1>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../B1>
)

if(WIN32)
	target_compile_definitions(BaseMFC PRIVATE _CRT_SECURE_NO_WARNINGS)
endif()
