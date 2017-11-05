#include "wastepile.hpp"
#include "deck.hpp"
#include "deckdraggedcards.hpp"
#include "foundationdraggedcards.hpp"
#include "tableaudraggedcards.hpp"
#include "wastedraggedcards.hpp"

WastePile::WastePile() : Pile("W", false) {}

void WastePile::visit(FoundationDraggedCards* draggedCards) {
  draggedCards->rejectDrop();
}

void WastePile::visit(TableauDraggedCards* draggedCards) {
  draggedCards->rejectDrop();
}

void WastePile::visit(WasteDraggedCards* draggedCards) {
  draggedCards->rejectDrop();
}

void WastePile::visit(DeckDraggedCards* draggedCards) {
  if (draggedCards->empty()) {
    Stack tmp;
    while (not this->cards.empty()) {
      tmp.push(this->cards.top());
      this->cards.pop();
    }
    while (not tmp.empty()) {
      draggedCards->push(tmp.top());
      tmp.pop();
    }
    draggedCards->rejectDrop();
  }
  {
    while (not draggedCards->empty()) {
      draggedCards->top().upTurned();
      cards.push(draggedCards->top());
      draggedCards->pop();
    }
  }
}

void WastePile::deal(Deck& deck) {}

DraggedCards* WastePile::dragCards(std::uint32_t number) {
  if (number != 1 || this->cards.empty()) {
    return nullptr;
  }
  WasteDraggedCards* draggedCards = new WasteDraggedCards(this);
  draggedCards->push(this->cards.top());
  cards.pop();
  return draggedCards;
}

void WastePile::dropCards(DraggedCards* draggedCards) {
  draggedCards->accept(this);
}

void WastePile::rejectDrop(DraggedCards* draggedCards) {
  while (not draggedCards->empty()) {
    draggedCards->top().upTurned();
    cards.push(draggedCards->top());
    draggedCards->pop();
  }
}

void WastePile::acceptDrop() {}
