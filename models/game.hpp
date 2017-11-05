#ifndef __GAME_HPP__
#define __GAME_HPP__

#include "arealist.hpp"

#include <cstdint>
#include <string>

enum class State : std::uint8_t { Start = 0, Move, End };

class Area;
class Pile;

class Game {
 public:
  Game();

  const AreaList &getAreaList() const { return areas; }

  void start();
  void move(std::string origin, std::string destination, std::uint32_t number);
  bool won() const;

  const State &getState() const { return state; }
  void setState(const State &theState) { state = theState; }

 private:
  State state;
  AreaList areas;

  Pile *getPile(const std::string &name) const { return areas.getPile(name); }
};

#endif  //__GAME_HPP__