#ifndef __PILEVISITOR_HPP__
#define __PILEVISITOR_HPP__

class FoundationPile;
class TableauPile;
class WastePile;
class DeckPile;

class PileVisitor {
 public:
  virtual bool canDragTo(const FoundationPile *pile) const = 0;
  virtual bool canDragTo(const TableauPile *pile) const = 0;
  virtual bool canDragTo(const WastePile *pile) const = 0;
  virtual bool canDragTo(const DeckPile *pile) const = 0;
};

#endif  //__PILEVISITOR_HPP__