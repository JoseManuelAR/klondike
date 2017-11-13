#ifndef __CONTROLLER_HPP__
#define __CONTROLLER_HPP__

#include "game.hpp"

#include <string>

class ControllerVisitor;

class Controller {
 public:
  Controller(Game &theGame) : game(theGame) {}
  virtual ~Controller() = default;

  virtual void accept(ControllerVisitor *visitor) = 0;

  virtual void start() { game.start(); }

  virtual void move(const Movement &movement) { game.move(movement); }

  bool won() const { return game.won(); }

  const Game &getGame() const { return game; }

 private:
  Game &game;
};

#endif  //__CONTROLLER_HPP__
