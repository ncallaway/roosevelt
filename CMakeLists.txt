# No particular reason 2.6 was selected here.
cmake_minimum_required (VERSION 2.6)

# Workaround for gtest / VS2012 combination. VS2012 default was lowered to
# 5, which breaks gtest.
add_definitions(-D_VARIADIC_MAX=10)

# Force gtest to use shared crt libraries instead of static ones.
# From http://comments.gmane.org/gmane.comp.programming.tools.cmake.user/39115
set(gtest_force_shared_crt ON CACHE BOOL "Use shared (DLL) run-time lib even when Google Test is built as static lib.")

add_subdirectory(gtest)
add_subdirectory(core)
add_subdirectory(roosevelt)
add_subdirectory(win)