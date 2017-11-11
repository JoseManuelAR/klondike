#include "tableaupile.hpp"
#include "deck.hpp"

TableauPile::TableauPile(std::uint8_t theIndex)
    : Pile(std::string(PREFIX) + std::to_string(theIndex), true),
      index(theIndex) {}

bool TableauPile::dragCards(const std::uint8_t numberOfCards, Stack &stack) {
  stack.clean();

  std::uint8_t n = numberOfCards;
  while (n > 0 && not this->empty()) {
    if (this->top().isVisible()) {
      stack.push(this->top());
      this->pop();
      n--;
    } else {
      n = 0;
    }
  }
  return numberOfCards == stack.size();
}

bool TableauPile::dropCards(const Stack &stack) {
  Stack localStack = stack;
  bool ok = true;
  while (not localStack.empty() && ok) {
    ok = false;
    if (this->empty()) {
      if (localStack.top().getNumber() == Value::King) {
        this->push(localStack.top());
        localStack.pop();
        ok = true;
      }
    } else {
      if (this->top().getColor() != localStack.top().getColor() &&
          this->top().isNext(localStack.top())) {
        this->push(localStack.top());
        localStack.pop();
        ok = true;
      }
    }
  }
  return ok;
}

void TableauPile::acceptDragCards() {
  if (not this->empty()) {
    this->top().upTurned();
  }
};

void TableauPile::rejectDragCards(Stack &stack) {
  while (not stack.empty()) {
    this->push(stack.top());
    stack.pop();
  }
}

bool TableauPile::canDragTo(const Pile *destinationPile) const {
  return destinationPile->canDragFrom(this);
}

bool TableauPile::canDragFrom(const PileVisitor *visitor) const {
  return visitor->canDragTo(this);
}

bool TableauPile::canDragTo(const FoundationPile *pile) const { return true; }

bool TableauPile::canDragTo(const TableauPile *pile) const { return true; }

bool TableauPile::canDragTo(const WastePile *pile) const { return false; }

bool TableauPile::canDragTo(const DeckPile *pile) const { return false; }

void TableauPile::deal(Deck &deck) {
  for (std::uint8_t i = 0; i < index; ++i) {
    this->cards.push(deck.getCard());
  }
  this->cards.top().upTurned();
}
