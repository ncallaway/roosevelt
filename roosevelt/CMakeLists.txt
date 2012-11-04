set(MSVC_INCREMENTAL_DEFAULT OFF)

project (roosevelt)

set(INCLUDES
	include
	../core/include)

set(SOURCES
    src/MoverSystem.cpp
	  src/PositionComponent.cpp
	  src/PrinterSystem.cpp
	  src/RenderComponent.cpp
	  src/RenderSystem.cpp)
	  
file(GLOB INCLUDE_FILES "include/*.h" "private_include/*.h")

include_directories(${INCLUDES})
add_library(roosevelt ${SOURCES} ${INCLUDE_FILES})