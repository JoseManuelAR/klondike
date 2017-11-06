#include "foundationpile.hpp"
#include "deck.hpp"
#include "deckdraggedcards.hpp"
#include "foundationdraggedcards.hpp"
#include "tableaudraggedcards.hpp"
#include "wastedraggedcards.hpp"

FoundationPile::FoundationPile(std::uint8_t theIndex)
    : Pile(std::string(PREFIX) + std::to_string(theIndex), false) {}

void FoundationPile::visit(FoundationDraggedCards *draggedCards) {
  draggedCards->rejectDrop();
}

void FoundationPile::visit(TableauDraggedCards *draggedCards) {
  Stack cards = draggedCards->getCards();

  bool putUp = true;
  while (putUp && not cards.empty()) {
    if (not this->cards.empty()) {
      if (this->cards.top().isVisible()) {
        putUp = (static_cast<std::uint8_t>(this->cards.top().getNumber()) ==
                 static_cast<std::uint8_t>(cards.top().getNumber()) - 1) &&
                (this->cards.top().getFigure() == cards.top().getFigure());
      } else {
        putUp = false;
      }
    } else {
      putUp = (cards.top().getNumber() == Value::Ace);
    }
    if (putUp) {
      cards.top().upTurned();
      this->cards.push(cards.top());
      cards.pop();
    }
  }
  if (putUp) {
    draggedCards->acceptDrop();
  } else {
    draggedCards->rejectDrop();
  }
}

void FoundationPile::visit(WasteDraggedCards *draggedCards) {
  Stack cards = draggedCards->getCards();

  bool putUp = true;
  while (putUp && not cards.empty()) {
    if (not this->cards.empty()) {
      if (this->cards.top().isVisible()) {
        putUp = (static_cast<std::uint8_t>(this->cards.top().getNumber()) ==
                 static_cast<std::uint8_t>(cards.top().getNumber()) - 1) &&
                (this->cards.top().getFigure() == cards.top().getFigure());
      } else {
        putUp = false;
      }
    } else {
      putUp = (cards.top().getNumber() == Value::Ace);
    }
    if (putUp) {
      cards.top().upTurned();
      this->cards.push(cards.top());
      cards.pop();
    }
  }
  if (putUp) {
    draggedCards->acceptDrop();
  } else {
    draggedCards->rejectDrop();
  }
}

void FoundationPile::visit(DeckDraggedCards *draggedCards) {
  draggedCards->rejectDrop();
}

void FoundationPile::deal(Deck &deck) {}

DraggedCards *FoundationPile::dragCards(std::uint32_t number) {
  if (number != 1 || cards.empty()) {
    return nullptr;
  }
  FoundationDraggedCards *draggedCards = new FoundationDraggedCards(this);
  draggedCards->push(cards.top());
  cards.pop();
  return draggedCards;
}

void FoundationPile::dropCards(DraggedCards *draggedCards) {
  draggedCards->accept(this);
}

void FoundationPile::rejectDrop(DraggedCards *draggedCards) {}

void FoundationPile::acceptDrop() {}
