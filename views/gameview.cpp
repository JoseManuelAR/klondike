#include "game.hpp"
#include "arealistview.hpp"
#include "gameview.hpp"

#include <iostream>

void GameView::draw(const Game& theGame) const {
  std::cout << "\033[2J\033[1;1H";
  AreaListView().draw(theGame.getAreaList());
}
