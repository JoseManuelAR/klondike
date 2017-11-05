#include "tableaudraggedcards.hpp"
#include "draggedcardsvisitor.hpp"

void TableauDraggedCards::accept(DraggedCardsVisitor* visitor) {
  visitor->visit(this);
}