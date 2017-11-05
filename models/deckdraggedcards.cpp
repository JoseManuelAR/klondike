#include "deckdraggedcards.hpp"
#include "draggedcardsvisitor.hpp"

void DeckDraggedCards::accept(DraggedCardsVisitor* visitor) {
  visitor->visit(this);
}