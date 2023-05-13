cmake_minimum_required(VERSION 3.16.3 FATAL_ERROR)

project(simple_enum_set VERSION 1.0.0)

# This library requires C++17
set(CMAKE_CXX_STANDARD 17)

option(ES_BUILD_EXAMPLES "Build examples" Off)

add_subdirectory(single_include/)
if (ES_BUILD_EXAMPLES)
    add_subdirectory(example/)
endif()