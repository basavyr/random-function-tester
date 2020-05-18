cmake_minimum_required(VERSION 3.0)

# set(CMAKE_CXX_STANDARD 14) # use version 17 for bool operations
set(CMAKE_CXX_STANDARD 17) # use version 17 for bool operations
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(Geometry-Math-Ops)

add_subdirectory(src)
add_subdirectory(test)