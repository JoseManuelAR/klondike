#include "game.hpp"
#include "gameview.hpp"
#include "pilelistview.hpp"

#include <iostream>

void GameView::draw(const Game &theGame) const {
  std::cout << "\033[2J\033[1;1H";
  PileListView().draw(theGame.getPileList());
}
