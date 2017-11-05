cmake_minimum_required(VERSION 3.0.1)

add_library(views consoleview.cpp startview.cpp moveview.cpp gameview.cpp arealistview.cpp areaview.cpp pilelistview.cpp pileview.cpp stackview.cpp cardview.cpp emptyview.cpp)

set (CMAKE_CXX_FLAGS "-g --coverage -fno-exceptions -fno-inline -Wall -std=c++14 ${CMAKE_CXX_FLAGS}")
