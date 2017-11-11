#include "wastepile.hpp"
#include "deck.hpp"

WastePile::WastePile() : Pile(std::string(PREFIX), false) {}

bool WastePile::dragCards(const std::uint8_t numberOfCards, Stack &stack) {
  stack.clean();
  if (numberOfCards == 1 && not this->empty()) {
    if (this->top().isVisible()) {
      stack.push(this->top());
      this->pop();
    }
  }
  return numberOfCards == stack.size();
}

bool WastePile::dropCards(const Stack &stack) {
  if (stack.size() == 1) {
    this->push(stack.top());
    this->top().upTurned();
    return true;
  }
  return false;
}

void WastePile::acceptDragCards(){};

void WastePile::rejectDragCards(Stack &stack) {
  while (not stack.empty()) {
    this->push(stack.top());
    stack.pop();
  }
}

bool WastePile::canDragTo(const Pile *destinationPile) const {
  return destinationPile->canDragFrom(this);
}

bool WastePile::canDragFrom(const PileVisitor *visitor) const {
  return visitor->canDragTo(this);
}

bool WastePile::canDragTo(const FoundationPile *pile) const { return true; }

bool WastePile::canDragTo(const TableauPile *pile) const { return true; }

bool WastePile::canDragTo(const WastePile *pile) const { return false; }

bool WastePile::canDragTo(const DeckPile *pile) const { return false; }

void WastePile::deal(Deck &deck) {}
