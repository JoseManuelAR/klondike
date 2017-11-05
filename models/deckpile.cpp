#include "deckpile.hpp"
#include "deck.hpp"
#include "deckdraggedcards.hpp"
#include "foundationdraggedcards.hpp"
#include "tableaudraggedcards.hpp"
#include "wastedraggedcards.hpp"

DeckPile::DeckPile() : Pile("D", false) {}

void DeckPile::visit(FoundationDraggedCards* draggedCards) {
  draggedCards->rejectDrop();
}

void DeckPile::visit(TableauDraggedCards* draggedCards) {
  draggedCards->rejectDrop();
}

void DeckPile::visit(WasteDraggedCards* draggedCards) {
  draggedCards->rejectDrop();
}

void DeckPile::visit(DeckDraggedCards* draggedCards) {
  draggedCards->rejectDrop();
}

void DeckPile::deal(Deck& deck) {
  while (not deck.empty()) {
    this->cards.push(deck.getCard());
  }
}

DraggedCards* DeckPile::dragCards(std::uint32_t number) {
  if (number != 1) {
    return nullptr;
  }
  DeckDraggedCards* draggedCards = new DeckDraggedCards(this);
  if (not cards.empty()) {
    draggedCards->push(cards.top());
    cards.pop();
  }
  return draggedCards;
}

void DeckPile::dropCards(DraggedCards* draggedCards) {
  draggedCards->accept(this);
}

void DeckPile::rejectDrop(DraggedCards* draggedCards) {
  while (not draggedCards->empty()) {
    draggedCards->top().downTurned();
    cards.push(draggedCards->top());
    draggedCards->pop();
  }
}

void DeckPile::acceptDrop() {}
