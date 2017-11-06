cmake_minimum_required(VERSION 3.0.1)

project (klondike)

include_directories ("${PROJECT_SOURCE_DIR}")
include_directories ("${PROJECT_SOURCE_DIR}/utils")
include_directories ("${PROJECT_SOURCE_DIR}/models")
include_directories ("${PROJECT_SOURCE_DIR}/controllers")
include_directories ("${PROJECT_SOURCE_DIR}/views")

add_subdirectory(models)
add_subdirectory(controllers)
add_subdirectory(views)

add_executable(klondike main.cpp klondike.cpp standaloneklondike.cpp)
target_link_libraries (klondike views controllers models)

set (CMAKE_CXX_FLAGS "-g --coverage -fno-exceptions -fno-inline -Wall -std=c++14 ${CMAKE_CXX_FLAGS}")