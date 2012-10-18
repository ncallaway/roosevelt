enable_testing()

project(coreTests)

set(LIBS
    core
    gtest
    gtest_main)

set(INCLUDES
	#../include
	#../private_include
	../../gtest/include)

set(SOURCES
    src/EntityTest.cpp
    src/EntityContainerTest.cpp)

include_directories(${INCLUDES})
add_executable(coreTests ${SOURCES})
target_link_libraries(coreTests ${LIBS})

add_test(NAME coreTests
		 COMMAND coreTests)