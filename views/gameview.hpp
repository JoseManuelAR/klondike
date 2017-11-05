#ifndef __GAMEVIEW_HPP__
#define __GAMEVIEW_HPP__

class Game;

class GameView {
 public:
  void draw(const Game& theGame) const;
};

#endif  //__GAMEVIEW_HPP__