cmake_minimum_required(VERSION 3.10)

project(hello_cmake LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#使得其它指定目录下的文件可以被看见
include_directories(${PROJECT_SOURCE_DIR}
${PROJECT_SOURCE_DIR}/include
${PROJECT_SOURCE_DIR}/lib
)

#链接动态库的目录
link_directories(${PROJECT_SOURCE_DIR}/lib)


# Add executable for a.cpp (assumes a.cpp is in the same directory)
add_executable(a_exec a.cpp)
add_executable(pointer_exec pointer.cpp)
add_executable(class_exec class.cpp)
add_executable(class_inherit class_inherit.cpp)

target_link_libraries(class_inherit  class_lib)
target_link_libraries(a_exec  b_lib)
# Installation (optional)


