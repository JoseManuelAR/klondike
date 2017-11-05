#ifndef __CONTROLLER_HPP__
#define __CONTROLLER_HPP__

#include "game.hpp"

#include <string>

class ControllerVisitor;

class Controller {
 public:
  Controller(Game& theGame) : game(theGame) {}
  virtual ~Controller() = default;

  virtual void accept(ControllerVisitor* visitor) = 0;

  virtual void start() {
    game.start();
    game.setState(State::Move);
  }

  virtual void move(std::string origin, std::string destination,
                    std::uint8_t number) {
    game.move(origin, destination, number);
    if (game.won()) {
      game.setState(State::End);
    } else {
      game.setState(State::Move);
    }
  }

  bool won() const { return game.won(); }

  const Game& getGame() const { return game; }

 private:
  Game& game;
};

#endif  //__CONTROLLER_HPP__
