#ifndef __AREA_HPP__
#define __AREA_HPP__

#include "pilelist.hpp"

#include <string>

class Deck;

class Area {
 public:
  Pile *getPile(const std::string &name) const { return piles.getPile(name); }
  const PileList &getPileList() const { return piles; }

  void deal(Deck &deck) { piles.deal(deck); }

  bool won() const { return piles.won(); }

 protected:
  PileList piles;
};

#endif  //__DECK_HPP__