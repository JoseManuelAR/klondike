#include "foundationdraggedcards.hpp"
#include "draggedcardsvisitor.hpp"

void FoundationDraggedCards::accept(DraggedCardsVisitor* visitor) {
  visitor->visit(this);
}