cmake_minimum_required(VERSION 3.10)

project(hello_cmake LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/include)


link_directories(${PROJECT_SOURCE_DIR}/lib)

# Add executable for a.cpp (assumes a.cpp is in the same directory)
add_executable(a_exec a.cpp)
target_link_libraries(a_exec  b_lib)
# Installation (optional)


