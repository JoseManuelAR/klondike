#include "wastedraggedcards.hpp"
#include "draggedcardsvisitor.hpp"

void WasteDraggedCards::accept(DraggedCardsVisitor* visitor) {
  visitor->visit(this);
}