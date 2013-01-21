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

  project "roosevelt"
    kind "StaticLib"
    language "C++"

    links { "core" }

    includedirs { "core/include", "roosevelt/include" }
    files { "roosevelt/inclde/*.h", "roosevelt/src/*.cpp" }

    configuration "debug"
      targetdir "lib/debug"

    configuration "release"
      targetdir "lib/release"

  project "linroosevelt"
    kind "WindowedApp" -- Could be ConsoleApp too.
    language "C++"

    links { "roosevelt", "core", "sfml-graphics", "sfml-window", "sfml-system" }

    includedirs { "core/include", "roosevelt/include", "linux/include" }
    files { "linux/include/*.h", "linux/src/*.cpp" }

    configuration "debug"
      targetdir "bin/debug"

    configuration "release"
      targetdir "bin/release"
