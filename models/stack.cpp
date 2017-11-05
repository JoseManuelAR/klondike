#include <algorithm>
#include <iostream>
#include <random>

#include "stack.hpp"
/*
void Stack::moveFrom(Stack& from, std::uint8_t num) {
  while (num > 0) {
    cards.insert(cards.begin(), from.top());
    from.pop();
    num--;
  }
}

void Stack::print() const {
  for (auto rit = cards.crbegin(); rit != cards.crend(); ++rit) {
    rit->print();
    std::cout << " ";
  }
}

bool Stack::hasVisibleCards(uint numberOfCards) const {
  for (auto rit = cards.crbegin(); rit != cards.crend() && numberOfCards > 0;
       ++rit) {
    if (!rit->isVisible()) {
      return false;
    }
    numberOfCards--;
  }
  return true;
}

void Stack::moveFrom(Stack& from, std::uint8_t num) {
  while (num > 0) {
    cards.insert(cards.begin(), from.top());
    from.pop();
    num--;
  }
}

void Stack::upTurned() {
  if (not cards.empty()) {
    cards.back().upTurned();
  }
}

void Stack::downTurned() {
  if (not cards.empty()) {
    cards.back().downTurned();
  }
}*/
