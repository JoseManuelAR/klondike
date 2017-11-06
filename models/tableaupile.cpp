#include "tableaupile.hpp"
#include "deck.hpp"
#include "deckdraggedcards.hpp"
#include "foundationdraggedcards.hpp"
#include "tableaudraggedcards.hpp"
#include "wastedraggedcards.hpp"

#include <cassert>

TableauPile::TableauPile(std::uint8_t theIndex)
    : Pile(std::string(PREFIX) + std::to_string(theIndex), true),
      index(theIndex) {}

void TableauPile::visit(FoundationDraggedCards *draggedCards) {
  Stack cards = draggedCards->getCards();
  bool hangDown = true;

  assert(cards.size() == 1);
  assert(cards.top().isVisible());
  assert(this->cards.empty() || this->cards.top().isVisible());

  if (not this->cards.empty()) {
    hangDown = (static_cast<std::uint8_t>(this->cards.top().getNumber()) ==
                static_cast<std::uint8_t>(cards.top().getNumber()) + 1) &&
               (this->cards.top().getColor() != cards.top().getColor());
  } else {
    hangDown = (cards.top().getNumber() == Value::King);
  }
  if (hangDown) {
    this->cards.push(cards.top());
    draggedCards->acceptDrop();
  } else {
    draggedCards->rejectDrop();
  }
}

void TableauPile::visit(TableauDraggedCards *draggedCards) {
  Stack cards = draggedCards->getCards();
  bool hangDown = true;

  while (hangDown && not cards.empty()) {
    if (not this->cards.empty() && this->cards.top().isVisible()) {
      hangDown = (static_cast<std::uint8_t>(this->cards.top().getNumber()) ==
                  static_cast<std::uint8_t>(cards.top().getNumber()) + 1) &&
                 (this->cards.top().getColor() != cards.top().getColor());
    }
    if (hangDown) {
      cards.top().upTurned();
      this->cards.push(cards.top());
      cards.pop();
    }
  }
  if (hangDown) {
    draggedCards->acceptDrop();
  } else {
    draggedCards->rejectDrop();
  }
}

void TableauPile::visit(WasteDraggedCards *draggedCards) {
  Stack cards = draggedCards->getCards();
  bool hangDown = true;

  assert(cards.size() == 1);
  assert(cards.top().isVisible());
  assert(this->cards.empty() || this->cards.top().isVisible());

  if (not this->cards.empty()) {
    hangDown = (static_cast<std::uint8_t>(this->cards.top().getNumber()) ==
                static_cast<std::uint8_t>(cards.top().getNumber()) + 1) &&
               (this->cards.top().getColor() != cards.top().getColor());
  } else {
    hangDown = (cards.top().getNumber() == Value::King);
  }
  if (hangDown) {
    this->cards.push(cards.top());
    draggedCards->acceptDrop();
  } else {
    draggedCards->rejectDrop();
  }
}

void TableauPile::visit(DeckDraggedCards *draggedCards) {
  draggedCards->rejectDrop();
}

void TableauPile::deal(Deck &deck) {
  for (std::uint8_t i = 0; i < index; ++i) {
    this->cards.push(deck.getCard());
  }
  this->cards.top().upTurned();
}

DraggedCards *TableauPile::dragCards(std::uint32_t number) {
  TableauDraggedCards *draggedCards = new TableauDraggedCards(this);
  while (number > 0) {
    if (cards.empty() || not cards.top().isVisible()) {
      this->rejectDrop(draggedCards);
      return nullptr;
    }
    draggedCards->push(cards.top());
    cards.pop();
    number--;
  }
  return draggedCards;
}

void TableauPile::dropCards(DraggedCards *draggedCards) {
  draggedCards->accept(this);
}

void TableauPile::rejectDrop(DraggedCards *draggedCards) {
  while (not draggedCards->empty()) {
    draggedCards->top().upTurned();
    cards.push(draggedCards->top());
    draggedCards->pop();
  }
}

void TableauPile::acceptDrop() {
  if (not cards.empty() && not cards.top().isVisible()) {
    cards.top().upTurned();
  }
}
