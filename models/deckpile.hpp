#ifndef __DECKPILE_HPP__
#define __DECKPILE_HPP__

#include "pile.hpp"
#include "pilevisitor.hpp"

class Deck;

class DeckPile : public Pile, public PileVisitor {
 public:
  DeckPile();

  virtual Stack *dragCards(const std::uint8_t numberOfCards) override;
  virtual bool dropCards(const Stack *stack) override;

  virtual void acceptDragCards() override;
  virtual void rejectDragCards(Stack *stack) override;

  virtual bool canDragTo(const Pile *destinationPile) const override;
  virtual bool canDragFrom(const PileVisitor *visitor) const override;

  virtual bool canDragTo(const FoundationPile *pile) const override;
  virtual bool canDragTo(const TableauPile *pile) const override;
  virtual bool canDragTo(const WastePile *pile) const override;
  virtual bool canDragTo(const DeckPile *pile) const override;

  virtual void deal(Deck &deck) override;

  virtual bool won() const override { return cards.empty(); }

 private:
  constexpr static const char *PREFIX = "D";
};

#endif  //__DECKPILE_HPP__