#include "deckpile.hpp"
#include "deck.hpp"

DeckPile::DeckPile() : Pile(std::string(PREFIX), false) {}

bool DeckPile::dragCards(const std::uint8_t numberOfCards, Stack &stack) {
  stack.clean();
  if (numberOfCards == 1) {
    return this->dragCard(stack);
  }
  return false;
}

bool DeckPile::dragCard(Stack &stack) {
  if (not this->empty() && not this->top().isVisible()) {
    stack.push(this->top());
    this->pop();
    return true;
  }
  return false;
}

bool DeckPile::dropCards(const Stack &stack) { return false; }

void DeckPile::acceptDragCards(){};

void DeckPile::rejectDragCards(Stack &stack) {
  while (not stack.empty()) {
    this->push(stack.top());
    stack.pop();
  }
}

bool DeckPile::canDragTo(const Pile *destinationPile) const {
  return destinationPile->canDragFrom(this);
}

bool DeckPile::canDragFrom(const PileVisitor *visitor) const {
  return visitor->canDragTo(this);
}

bool DeckPile::canDragTo(const FoundationPile *pile) const { return false; }

bool DeckPile::canDragTo(const TableauPile *pile) const { return false; }

bool DeckPile::canDragTo(const WastePile *pile) const { return true; }

bool DeckPile::canDragTo(const DeckPile *pile) const { return false; }

void DeckPile::deal(Deck &deck) {
  while (not deck.empty()) {
    this->cards.push(deck.getCard());
  }
}
