#ifndef __PILE_HPP__
#define __PILE_HPP__

#include "stack.hpp"

#include <string>

class Deck;
class DraggedCards;
class PileVisitor;

class Pile {
 public:
  Pile(const std::string &theName, bool theExtended);

  virtual Stack *dragCards(const std::uint8_t numberOfCards) = 0;
  virtual bool dropCards(const Stack *stack) = 0;

  virtual void acceptDragCards() = 0;
  virtual void rejectDragCards(Stack *stack) = 0;

  virtual bool canDragTo(const Pile *destinationPile) const = 0;
  virtual bool canDragFrom(const PileVisitor *visitor) const = 0;

  virtual void deal(Deck &deck) = 0;

  const std::string &getName() const { return name; }
  const Stack &getCards() const { return cards; }
  bool isExtended() const { return extended; }

  void push(Card card) { cards.push(card); }
  void pop() { cards.pop(); }
  const Card &top() const { return cards.top(); }
  Card &top() { return cards.top(); }
  bool empty() const { return cards.empty(); };
  std::size_t size() const { return cards.size(); };

  virtual bool won() const = 0;

 protected:
  std::string name;
  bool extended;
  Stack cards;
};

#endif  //__PILE_HPP__