cmake_minimum_required(VERSION 3.0.1)

add_library(models game.cpp arealist.cpp area.cpp foundation.cpp tableau.cpp waste.cpp deckarea.cpp pilelist.cpp foundationpile.cpp tableaupile.cpp wastepile.cpp deckpile.cpp pile.cpp foundationdraggedcards.cpp tableaudraggedcards.cpp wastedraggedcards.cpp deckdraggedcards.cpp stack.cpp deck.cpp)

set (CMAKE_CXX_FLAGS "-g --coverage -fno-exceptions -fno-inline -Wall -std=c++14 ${CMAKE_CXX_FLAGS}")
