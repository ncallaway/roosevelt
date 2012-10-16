set(MSVC_INCREMENTAL_DEFAULT OFF)

project (roosevelt)

set(INCLUDES
	../core/include)

set(SOURCES
    src/roosevelt.cpp)

set(LIBS
	core)


include_directories(${INCLUDES})
add_executable(roosevelt ${SOURCES})
target_link_libraries (roosevelt ${LIBS})