cmake_minimum_required(VERSION 2.8)

project(Learning)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_BUILD_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BUILD_DIR})

include_directories("${PROJECT_SOURCE_DIR}")

add_executable(main ${PROJECT_SOURCE_DIR}/src/main.cpp)