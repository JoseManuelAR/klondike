#ifndef __DECKSTACK_HPP__
#define __DECKSTACK_HPP__

#include "stack.hpp"

class DeckStack : public Stack {
 public:
  DeckStack(const std::string theName) : Stack(theName, false){};

  virtual bool canDragCards(std::uint8_t number) const override {
    return number == 1;
  }

  virtual bool canDropCards(std::uint8_t number) const override {
    return false;
  }

 private:
};

#endif  //__DECKSTACK_HPP__