#ifndef __FOUNDATIONDRAGGEDCARDS_HPP__
#define __FOUNDATIONDRAGGEDCARDS_HPP__

#include "draggedcards.hpp"

class FoundationDraggedCards : public DraggedCards {
 public:
  FoundationDraggedCards(Pile* theOriginPile) : DraggedCards(theOriginPile){};

  virtual void accept(DraggedCardsVisitor* visitor) override;
};

#endif  //__FOUNDATIONDRAGGEDCARDS_HPP__