cmake_minimum_required(VERSION 2.8)

project(openqube)

set(CMAKE_MODULE_PATH "${openqube_SOURCE_DIR}/cmake")

include(CTest)
enable_testing()

add_subdirectory(src)
add_subdirectory(tools)
