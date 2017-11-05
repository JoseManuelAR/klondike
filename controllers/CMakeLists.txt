cmake_minimum_required(VERSION 3.0.1)

add_library(controllers locallogic.cpp startcontroller.cpp movecontroller.cpp)

set (CMAKE_CXX_FLAGS "-g --coverage -fno-exceptions -fno-inline -Wall -std=c++14 ${CMAKE_CXX_FLAGS}")
