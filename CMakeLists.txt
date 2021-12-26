# CMakeList.txt : CMake project for hz, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("hz")

# Add source to this project's executable.
add_executable (hz "source/hz.cpp" "source/hz.h")

# TODO: Add tests and install targets if needed.
