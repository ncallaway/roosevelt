set(MSVC_INCREMENTAL_DEFAULT OFF)

project (core)

set(INCLUDES
	include
	private_include)

set(SOURCES
    src/doprint.cpp
)

include_directories(${INCLUDES})
add_library(core ${SOURCES})

add_subdirectory(test)