# No particular reason 2.6 was selected here.
cmake_minimum_required (VERSION 2.6)

# Workaround for gtest / VS2012 combination. VS2012 default was lowered to
# 5, which breaks gtest.
add_definitions(-D_VARIADIC_MAX=10)

add_subdirectory(gtest)
add_subdirectory(core)
add_subdirectory(win)