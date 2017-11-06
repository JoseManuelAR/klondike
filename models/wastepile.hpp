#ifndef __WASTEPILE_HPP__
#define __WASTEPILE_HPP__

#include "draggedcardsvisitor.hpp"
#include "pile.hpp"

class Deck;

class WastePile : public Pile, public DraggedCardsVisitor {
 public:
  WastePile();

  virtual void visit(FoundationDraggedCards *draggedCards) override;
  virtual void visit(TableauDraggedCards *draggedCards) override;
  virtual void visit(WasteDraggedCards *draggedCards) override;
  virtual void visit(DeckDraggedCards *draggedCards) override;

  virtual void deal(Deck &deck) override;
  virtual DraggedCards *dragCards(std::uint32_t number) override;
  virtual void dropCards(DraggedCards *draggedCards) override;

  virtual void rejectDrop(DraggedCards *draggedCards) override;
  virtual void acceptDrop() override;

  virtual bool won() const override { return cards.empty(); }

 private:
  constexpr static const char *PREFIX = "W";
};

#endif  //__TABLEAUPILE_HPP__