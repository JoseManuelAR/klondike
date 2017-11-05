#ifndef __DECKPILE_HPP__
#define __DECKPILE_HPP__

#include "draggedcardsvisitor.hpp"
#include "pile.hpp"

class Deck;

class DeckPile : public Pile, public DraggedCardsVisitor {
 public:
  DeckPile();

  virtual void visit(FoundationDraggedCards* draggedCards) override;
  virtual void visit(TableauDraggedCards* draggedCards) override;
  virtual void visit(WasteDraggedCards* draggedCards) override;
  virtual void visit(DeckDraggedCards* draggedCards) override;

  virtual void deal(Deck& deck) override;
  virtual DraggedCards* dragCards(std::uint32_t number) override;
  virtual void dropCards(DraggedCards* draggedCards) override;

  virtual void rejectDrop(DraggedCards* draggedCards) override;
  virtual void acceptDrop() override;

  virtual bool won() const override { return cards.empty(); }

 protected:
};

#endif  //__DECKPILE_HPP__