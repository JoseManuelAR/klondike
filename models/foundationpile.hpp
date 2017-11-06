#ifndef __FOUNDATIONPILE_HPP__
#define __FOUNDATIONPILE_HPP__

#include "draggedcardsvisitor.hpp"
#include "pile.hpp"

class Deck;

class FoundationPile : public Pile, public DraggedCardsVisitor {
 public:
  FoundationPile(std::uint8_t theIndex);

  virtual void visit(FoundationDraggedCards *draggedCards) override;
  virtual void visit(TableauDraggedCards *draggedCards) override;
  virtual void visit(WasteDraggedCards *draggedCards) override;
  virtual void visit(DeckDraggedCards *draggedCards) override;

  virtual void deal(Deck &deck) override;
  virtual DraggedCards *dragCards(std::uint32_t number) override;
  virtual void dropCards(DraggedCards *draggedCards) override;

  virtual void rejectDrop(DraggedCards *draggedCards) override;
  virtual void acceptDrop() override;

  virtual bool won() const override { return true; }

 private:
  constexpr static const char *PREFIX = "F";
};

#endif  //__FOUNDATIONPILE_HPP__