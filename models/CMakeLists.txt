cmake_minimum_required(VERSION 3.0.1)

add_library(models game.cpp pilelist.cpp foundationpile.cpp tableaupile.cpp wastepile.cpp deckpile.cpp pile.cpp deck.cpp)

set (CMAKE_CXX_FLAGS "-g --coverage -fno-exceptions -fno-inline -Wall -std=c++14 ${CMAKE_CXX_FLAGS}")
