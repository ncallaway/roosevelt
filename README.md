roosevelt
=========

# Deprecated

This project has been abandoned.

## Prerequisites
To build and run the unit tests, you will need the [Google C++ Testing Framework](http://code.google.com/p/googletest/).

Download and extract to a folder named `gmock` and placed within this test directory. From the project root, you should have a folder like:

    gtest/include
	
## Building

    cd build
    cmake .. -G "Your Generator" (ex: cmake .. -G "Visual Studio 11")
    [build generated files!]

## Styling
To style code for submission you will need [Artistic Style](http://astyle.sourceforge.net/). Ensure the binary for astyle is on your path.

Then simply run:

    astyle --recursive --options=astyle "*.cpp" "*.h"

