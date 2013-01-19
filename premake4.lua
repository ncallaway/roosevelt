solution "roosevelt"
  configurations { "debug", "release" }
  location "build"

  project "core"
    kind "StaticLib"
    language "C++"
    includedirs { "core/include" }
    files { "core/include/*.h", "core/src/*.cpp" }

    configuration "debug"
      targetdir "lib/debug"

    configuration "release"
      targetdir "lib/release"
