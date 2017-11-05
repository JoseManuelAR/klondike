#ifndef __WASTEDRAGGEDCARDS_HPP__
#define __WASTEDRAGGEDCARDS_HPP__

#include "draggedcards.hpp"

class WasteDraggedCards : public DraggedCards {
 public:
  WasteDraggedCards(Pile* theOriginPile) : DraggedCards(theOriginPile){};

  virtual void accept(DraggedCardsVisitor* visitor) override;
};

#endif  //__WASTEDRAGGEDCARDS_HPP__