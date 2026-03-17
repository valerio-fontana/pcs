cmake_minimum_required(VERSION 3.20)
project(eser1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}-Wall")

set(SOURCES temp.cpp)

add_executable(eser1 temp.cpp)
add_executable(printargs printargs.cpp)