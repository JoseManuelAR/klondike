#ifndef __DRAGGEDCARDSVISITOR_HPP__
#define __DRAGGEDCARDSVISITOR_HPP__

class FoundationDraggedCards;
class TableauDraggedCards;
class WasteDraggedCards;
class DeckDraggedCards;

class DraggedCardsVisitor {
 public:
  virtual void visit(FoundationDraggedCards* draggedCards) = 0;
  virtual void visit(TableauDraggedCards* draggedCards) = 0;
  virtual void visit(WasteDraggedCards* draggedCards) = 0;
  virtual void visit(DeckDraggedCards* draggedCards) = 0;
};

#endif  //__DRAGGEDCARDSVISITOR_HPP__