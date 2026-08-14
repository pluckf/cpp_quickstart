cmake_minimum_required(VERSION 3.10)

project(hello_leetcode LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(hello_leetcode listnode_reference.cpp)
add_executable(string_exec string_reference.cpp)
