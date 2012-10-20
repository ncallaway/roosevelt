set(MSVC_INCREMENTAL_DEFAULT OFF)

project (roosevelt)

set(INCLUDES
	include
	../core/include)

set(SOURCES
    src/MoverSystem.cpp
	src/PositionComponent.cpp
	src/PrinterSystem.cpp)

include_directories(${INCLUDES})
add_library(roosevelt ${SOURCES})