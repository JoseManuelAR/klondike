#include "movement.hpp"
#include "pile.hpp"
#include "stack.hpp"

#include <iostream>

bool Movement::flip() const {
  if (originPile != nullptr && destinationPile != nullptr) {
    if (originPile->canDragTo(destinationPile)) {
      Stack *cards = originPile->dragCards(numberOfCards);
      if (cards != nullptr && destinationPile->dropCards(cards)) {
        return true;
      }
    }
  }
  return false;
}

void Movement::execute() const {
  if (originPile != nullptr && destinationPile != nullptr) {
    if (originPile->canDragTo(destinationPile)) {
      Stack *cards = originPile->dragCards(numberOfCards);
      if (cards != nullptr) {
        if (destinationPile->dropCards(cards)) {
          originPile->acceptDragCards();
        } else {
          originPile->rejectDragCards(cards);
        }
      }
    }
  }
}
