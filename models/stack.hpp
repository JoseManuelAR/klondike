#ifndef __STACK_HPP__
#define __STACK_HPP__

#include <stack>
#include <string>

#include "card.hpp"

class Stack {
 public:
  Stack() : cards(){};

  void push(Card card) { cards.push(card); }
  void pop() { cards.pop(); }
  const Card& top() const { return cards.top(); }
  Card& top() { return cards.top(); }

  bool empty() const { return cards.empty(); };
  std::size_t size() const { return cards.size(); };

  /*std::size_t upturnedCards() const {
    std::stack<Card> auxCards = cards;
    std::size_t upturnedCards = 0;

    while (not auxCards.empty() && auxCards.top().isVisible()) {
      upturnedCards++;
      auxCards.pop();
    }
    return upturnedCards;
  }*/

  /*void upTurn() { cards.front().upTurned(); }
  void downTurn() { cards.front().downTurned(); }

  const Stack& operator=(const std::vector<Card>& theCards) {
    cards = theCards;
    return *this;
  }*/

  /*const Card& operator[](std::uint8_t position) const {
    assert(position < cards.size());
    return (cards.top() - position);
  }*/

  /*bool hasVisibleCards(uint numberOfCards) const;
  void moveFrom(Stack& from, std::uint8_t num);
  void upTurned();
  void downTurned();

  void push(Card card) { cards.insert(cards.begin(), card); }
  void pop() { cards.erase(cards.begin()); }
  const Card& top() const { return cards.front(); }

  std::size_t size() const { return cards.size(); };
  bool empty() const { return cards.empty(); };

  bool isExtended() const { return extended; }*/

 private:
  std::stack<Card> cards;
};

#endif  //__STACK_HPP__