#ifndef __WASTEPILE_HPP__
#define __WASTEPILE_HPP__

#include "pile.hpp"
#include "pilevisitor.hpp"

class Deck;

class WastePile : public Pile, public PileVisitor {
 public:
  WastePile();

  virtual bool dragCards(const std::uint8_t numberOfCards,
                         Stack &stack) override;
  virtual bool dragCard(Stack &stack) override;
  virtual bool dropCards(const Stack &stack) override;

  virtual void acceptDragCards() override;
  virtual void rejectDragCards(Stack &stack) override;

  virtual bool canDragTo(const Pile *destinationPile) const override;
  virtual bool canDragFrom(const PileVisitor *visitor) const override;

  virtual bool canDragTo(const FoundationPile *pile) const override;
  virtual bool canDragTo(const TableauPile *pile) const override;
  virtual bool canDragTo(const WastePile *pile) const override;
  virtual bool canDragTo(const DeckPile *pile) const override;

  virtual void deal(Deck &deck) override;

  virtual bool won() const override { return cards.empty(); }

 private:
  constexpr static const char *PREFIX = "W";
};

#endif  //__TABLEAUPILE_HPP__