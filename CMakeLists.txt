cmake_minimum_required(VERSION 2.8)

project(deviation)
file(GLOB SRC ${CMAKE_SOURCE_DIR}/src/*.cpp)
add_executable(deviation ${SRC})