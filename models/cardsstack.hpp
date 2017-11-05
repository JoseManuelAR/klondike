#ifndef __CARDSSTACK_HPP__
#define __CARDSSTACK_HPP__

#include "card.hpp"

#include <algorithm>
#include <stack>
#include <vector>

class CardsStack {
 public:
  CardsStack();

  virtual const std::string& getName() const = 0;

  void push(Card card);

 private:
  std::stack<Card> cards;
};

class CardsStackList {
 public:
  CardsStackList();

  std::size_t size() const { return stacks.size(); };

  CardsStack* operator[](std::uint8_t position) const {
    assert(position < stacks.size());
    return stacks[position];
  }

  CardsStack* operator[](const std::string& name) const {
    std::vector<CardsStack*>::const_iterator it;
    if ((it = std::find_if(stacks.cbegin(), stacks.cend(),
                           [name](CardsStack* s) {
                             return (s)->getName() == name;
                           })) != stacks.end()) {
      return *it;
    }
    return nullptr;
  }

 private:
  std::vector<CardsStack*> stacks;
};

#endif  //__CARDSSTACK_HPP__