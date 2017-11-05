#ifndef __TABLEAUDRAGGEDCARDS_HPP__
#define __TABLEAUDRAGGEDCARDS_HPP__

#include "draggedcards.hpp"

class TableauDraggedCards : public DraggedCards {
 public:
  TableauDraggedCards(Pile* theOriginPile) : DraggedCards(theOriginPile){};

  virtual void accept(DraggedCardsVisitor* visitor) override;
};

#endif  //__TABLEAUDRAGGEDCARDS_HPP__