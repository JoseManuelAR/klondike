#include "foundationpile.hpp"
#include "deck.hpp"

FoundationPile::FoundationPile(std::uint8_t theIndex)
    : Pile(std::string(PREFIX) + std::to_string(theIndex), false) {}

Stack *FoundationPile::dragCards(const std::uint8_t numberOfCards) {
  Stack *stack = nullptr;
  if (numberOfCards == 1 && not this->empty() && this->top().isVisible()) {
    stack = new Stack();
    stack->push(this->top());
    this->pop();
  }
  return stack;
}

bool FoundationPile::dropCards(const Stack *stack) {
  if (stack != nullptr && stack->size() == 1) {
    if ((this->empty() && stack->top().getNumber() == Value::Ace) ||
        (this->top().getFigure() == stack->top().getFigure() &&
         this->top().isPrevious(stack->top()))) {
      this->push(stack->top());
      this->top().upTurned();
      return true;
    }
  }
  return false;
}

void FoundationPile::acceptDragCards(){};

void FoundationPile::rejectDragCards(Stack *stack) {
  if (stack != nullptr) {
    while (not stack->empty()) {
      this->push(stack->top());
      stack->pop();
    }
  }
}

bool FoundationPile::canDragTo(const Pile *destinationPile) const {
  return destinationPile->canDragFrom(this);
}

bool FoundationPile::canDragFrom(const PileVisitor *visitor) const {
  return visitor->canDragTo(this);
}

bool FoundationPile::canDragTo(const FoundationPile *pile) const {
  return false;
}

bool FoundationPile::canDragTo(const TableauPile *pile) const { return true; }

bool FoundationPile::canDragTo(const WastePile *pile) const { return false; }

bool FoundationPile::canDragTo(const DeckPile *pile) const { return false; }

void FoundationPile::deal(Deck &deck) {}
