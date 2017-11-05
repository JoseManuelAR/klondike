#ifndef __DRAGGEDCARDS_HPP__
#define __DRAGGEDCARDS_HPP__

#include "card.hpp"
#include "pile.hpp"
#include "stack.hpp"

class DraggedCardsVisitor;

class DraggedCards {
 public:
  DraggedCards(Pile* theOriginPile) : originPile(theOriginPile), cards(){};
  virtual ~DraggedCards() = default;

  const Stack& getCards() const { return cards; }

  void rejectDrop() { originPile->rejectDrop(this); }
  void acceptDrop() { originPile->acceptDrop(); }

  virtual void accept(DraggedCardsVisitor* visitor) = 0;

  void push(Card card) { cards.push(card); }
  void pop() { cards.pop(); }
  const Card& top() const { return cards.top(); }
  Card& top() { return cards.top(); }

  bool empty() const { return cards.empty(); };

 private:
  Pile* originPile;
  Stack cards;
};

#endif  //__DRAGGEDCARDS_HPP__