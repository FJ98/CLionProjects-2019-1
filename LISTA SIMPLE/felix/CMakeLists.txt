cmake_minimum_required(VERSION 3.13)
project(felix)

set(CMAKE_CXX_STANDARD 14)

add_executable(felix main.cpp LinkedList.cpp LinkedList.h BinarySearchTree.cpp BinarySearchTree.h Location.cpp Location.h)