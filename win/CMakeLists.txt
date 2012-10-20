set(MSVC_INCREMENTAL_DEFAULT OFF)

project (roosevelt)

set(INCLUDES
	include
	../core/include)

set(SOURCES
    src/roosevelt.cpp
	src/MoverSystem.cpp
    src/PositionComponent.cpp
    src/PrinterSystem.cpp)

set(LIBS
	core)

include_directories(${INCLUDES})
add_executable(roosevelt ${SOURCES})
target_link_libraries (roosevelt ${LIBS})