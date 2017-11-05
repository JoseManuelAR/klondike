#ifndef __FOUNDATIONSTACK_HPP__
#define __FOUNDATIONSTACK_HPP__

#include "cardsstack.hpp"

class FoundationStack : public CardsStack {
 public:
  FoundationStack(const std::string theName) : CardsStack(theName, true){};

  virtual bool canDragCards(std::uint8_t number) const override {
    return number == 1;
  }

  virtual bool canDropCards(std::uint8_t number) const override {
    return number == 1;
  }

 private:
};

#endif  //__FOUNDATIONSTACK_HPP__