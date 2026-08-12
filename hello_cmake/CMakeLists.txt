cmake_minimum_required(VERSION 3.10)

project(hello_cmake LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add executable for a.cpp (assumes a.cpp is in the same directory)
add_executable(a_exec a.cpp)

# Installation (optional)


