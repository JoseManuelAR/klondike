#ifndef __DECKDRAGGEDCARDS_HPP__
#define __DECKDRAGGEDCARDS_HPP__

#include "draggedcards.hpp"

class DeckDraggedCards : public DraggedCards {
 public:
  DeckDraggedCards(Pile* theOriginPile) : DraggedCards(theOriginPile){};

  virtual void accept(DraggedCardsVisitor* visitor) override;
};

#endif  //__DECKDRAGGEDCARDS_HPP__