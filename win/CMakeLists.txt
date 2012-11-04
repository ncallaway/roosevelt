set(MSVC_INCREMENTAL_DEFAULT OFF)

project (winroosevelt)

set(INCLUDES
	include
	../core/include
	../roosevelt/include
	../sdl/include)

set(SOURCES
    src/roosevelt.cpp
	src/SDLRendererAdapter.cpp)

set(LIBS
	core
	roosevelt
	${PROJECT_SOURCE_DIR}/../sdl/lib/SDL.lib
	${PROJECT_SOURCE_DIR}/../sdl/lib/SDLmain.lib)
	
file(GLOB INCLUDE_FILES "include/*.h" "private_include/*.h")

include_directories(${INCLUDES})
add_executable(winroosevelt ${SOURCES} ${INCLUDE_FILES})
target_link_libraries (winroosevelt ${LIBS})

# Post-build copy DLLs
add_custom_command(TARGET winroosevelt POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different "${PROJECT_SOURCE_DIR}/../sdl/lib/SDL.dll"
        $<TARGET_FILE_DIR:winroosevelt>)
