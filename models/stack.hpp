#ifndef __STACK_HPP__
#define __STACK_HPP__

#include <stack>
#include <string>

#include "card.hpp"

class Stack {
 public:
  Stack() : cards(){};

  void clean() {
    while (not cards.empty()) {
      cards.pop();
    }
  }

  bool allVisibles() const {
    std::stack<Card> tmp = cards;
    while (not tmp.empty()) {
      if (not tmp.top().isVisible()) {
        return false;
      }
      tmp.pop();
    }
    return true;
  }

  void push(Card card) { cards.push(card); }
  void pop() { cards.pop(); }
  const Card &top() const { return cards.top(); }
  Card &top() { return cards.top(); }

  bool empty() const { return cards.empty(); };
  std::size_t size() const { return cards.size(); };

 private:
  std::stack<Card> cards;
};

#endif  //__STACK_HPP__