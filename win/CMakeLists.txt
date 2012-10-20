set(MSVC_INCREMENTAL_DEFAULT OFF)

project (winroosevelt)

set(INCLUDES
	../core/include
	../roosevelt/include)

set(SOURCES
    src/roosevelt.cpp)

set(LIBS
	core
	roosevelt)

include_directories(${INCLUDES})
add_executable(winroosevelt ${SOURCES})
target_link_libraries (winroosevelt ${LIBS})