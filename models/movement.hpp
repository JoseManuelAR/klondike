#ifndef __MOVEMENT_HPP__
#define __MOVEMENT_HPP__

#include "pilelist.hpp"

#include <cstdint>
#include <string>

class Pile;

class Movement {
 public:
  Movement(const std::string &theOrigin, const std::string &theDestination,
           std::uint8_t theNumberOfCards)
      : origin(theOrigin),
        destination(theDestination),
        numberOfCards(theNumberOfCards),
        originPile(nullptr),
        destinationPile(nullptr) {}

  void update(const PileList &piles) const {
    originPile = piles.getPile(origin);
    destinationPile = piles.getPile(destination);
  }

  Pile *getOriginPile() const { return originPile; }

  Pile *getDestinationPile() const { return destinationPile; }

  bool flip() const;
  void execute() const;

 private:
  std::string origin;
  std::string destination;
  std::uint8_t numberOfCards;
  mutable Pile *originPile;
  mutable Pile *destinationPile;
};

#endif  //__MOVEMENT_HPP__