cmake_minimum_required(VERSION 3.0.1)

add_library(views consoleview.cpp startview.cpp moveview.cpp movementdialog.cpp windialog.cpp gameview.cpp pilelistview.cpp pileview.cpp stackview.cpp cardview.cpp emptyview.cpp)

set (CMAKE_CXX_FLAGS "-g --coverage -fexceptions -fno-inline -Wall -std=c++14 ${CMAKE_CXX_FLAGS}")
