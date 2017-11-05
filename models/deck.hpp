#ifndef __DECK_HPP__
#define __DECK_HPP__

#include <vector>
#include "card.hpp"

class Deck {
 public:
  Deck();

  void shuffle();

  std::size_t size() const { return cards.size(); };
  bool empty() const { return cards.empty(); };

  const Card getCard() {
    Card returnCard = front();
    pop();
    return returnCard;
  }

 private:
  std::vector<Card> cards;

  const Card &front() const { return cards.front(); }
  void pop() { cards.erase(cards.begin()); }
};

#endif  //__DECK_HPP__