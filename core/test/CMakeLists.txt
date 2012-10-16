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
    src/testUnitTest.cpp)
	
add_definitions(-D_VARIADIC_MAX=10)

if (MSVC)
    foreach(flag_var
        CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
        CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO)
        
        if(${flag_var} MATCHES "/MD")
            string(REGEX REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}")
        endif(${flag_var} MATCHES "/MD")
    endforeach(flag_var)
endif()

include_directories(${INCLUDES})
add_executable(coreTests ${SOURCES})
target_link_libraries(coreTests ${LIBS})
set_target_properties(coreTests PROPERTIES LINK_FLAGS /NODEFAULTLIB:"msvcrtd.lib")

add_test(NAME coreTests
		 COMMAND coreTests)