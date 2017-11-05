#ifndef __WASTESTACK_HPP__
#define __WASTESTACK_HPP__

#include "stack.hpp"

class WasteStack : public Stack {
 public:
  WasteStack(const std::string theName) : Stack(theName, true){};

  virtual bool canDragCards(std::uint8_t number) const override {
    return number == 1;
  }

  virtual bool canDropCards(std::uint8_t number) const override {
    return number == 1;
  }

 private:
};

#endif  //__WASTESTACK_HPP__