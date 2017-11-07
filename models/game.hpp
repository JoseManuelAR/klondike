#ifndef __GAME_HPP__
#define __GAME_HPP__

#include "pilelist.hpp"

#include <cstdint>
#include <string>

enum class State : std::uint8_t { Start = 0, Move, End };

class Pile;

class Game {
 public:
  Game();

  void start();
  void move(std::string origin, std::string destination, std::uint32_t number);
  bool won() const { return this->piles.won(); }

  const State &getState() const { return state; }
  void setState(const State &theState) { state = theState; }

  const PileList &getPileList() const { return piles; }

 private:
  State state;

  constexpr static std::uint8_t FOUNDATION_PILES = 4;
  constexpr static std::uint8_t TABLEAU_PILES = 7;
  PileList piles;

  void createPiles();
};

#endif  //__GAME_HPP__