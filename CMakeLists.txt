cmake_minimum_required(VERSION 3.22.3 FATAL_ERROR)

project(simple_enum_set VERSION 1.0.0)

# This library requires C++17
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(single_include/)
add_subdirectory(example/)