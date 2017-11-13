#include "movement.hpp"
#include "pile.hpp"
#include "stack.hpp"

#include <iostream>

bool Movement::flip() const {
  if (originPile != nullptr && destinationPile != nullptr) {
    Stack cards;
    if (originPile->canDragTo(destinationPile) &&
        originPile->dragCards(numberOfCards, cards) &&
        destinationPile->dropCards(cards)) {
      return true;
    }
  }
  return false;
}

void Movement::execute() const {
  if (originPile != nullptr && destinationPile != nullptr) {
    Stack cards;
    if (originPile->canDragTo(destinationPile) &&
        originPile->dragCards(numberOfCards, cards) &&
        destinationPile->dropCards(cards)) {
      originPile->acceptDragCards();
    } else {
      originPile->rejectDragCards(cards);
    }
  }
}
