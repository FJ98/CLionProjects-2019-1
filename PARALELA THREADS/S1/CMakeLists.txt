cmake_minimum_required(VERSION 3.14)
project(S1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)

add_executable(S1 main.cpp)