#ifndef __FOUNDATIONPILE_HPP__
#define __FOUNDATIONPILE_HPP__

#include "pile.hpp"
#include "pilevisitor.hpp"

class Deck;

class FoundationPile : public Pile, public PileVisitor {
 public:
  FoundationPile(std::uint8_t theIndex);

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

  virtual bool won() const override { return true; }

 private:
  constexpr static const char *PREFIX = "F";
};

#endif  //__FOUNDATIONPILE_HPP__