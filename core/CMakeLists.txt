set(MSVC_INCREMENTAL_DEFAULT OFF)

project (core)

set(INCLUDES
	include
	private_include)

set(SOURCES
    src/BaseComponent.cpp
    src/Entity.cpp
    src/EntityComponent.cpp
    src/EntityContainer.cpp
)

file(GLOB INCLUDE_FILES "include/*.h" "private_include/*.h")

include_directories(${INCLUDES})
add_library(core ${SOURCES} ${INCLUDE_FILES})

add_subdirectory(test)