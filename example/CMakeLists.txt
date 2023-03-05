project(example VERSION 1.0.0 LANGUAGES CXX)

# Example's executable
add_executable(${PROJECT_NAME} example.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC simple_enum_set_lib)