#ifndef __TABLEAUSTACK_HPP__
#define __TABLEAUSTACK_HPP__

#include "stack.hpp"

class TableauStack : public Stack {
 public:
  TableauStack(const std::string theName) : Stack(theName, true){};

  virtual bool canDragCards(std::uint8_t number) const override {
    return number <= this->upturnedCards();
  }

  virtual bool canDropCards(std::uint8_t number) const override {
    return number == 1;
  }

 private:
};

#endif  //__TABLEAUSTACK_HPP__