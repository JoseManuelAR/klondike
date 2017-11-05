#ifndef __PILE_HPP__
#define __PILE_HPP__

#include "stack.hpp"

#include <string>

class Deck;
class DraggedCards;

class Pile {
 public:
  Pile(const std::string& theName, bool theExtended);

  virtual void deal(Deck& deck) = 0;
  virtual DraggedCards* dragCards(std::uint32_t number) = 0;
  virtual void dropCards(DraggedCards* draggedCards) = 0;

  virtual void rejectDrop(DraggedCards* draggedCards) = 0;
  virtual void acceptDrop() = 0;

  const std::string& getName() const { return name; }
  const Stack& getCards() const { return cards; }
  bool isExtended() const { return extended; }

  std::size_t size() const { return cards.size(); };

  virtual bool won() const = 0;

 protected:
  std::string name;
  bool extended;
  Stack cards;
};

#endif  //__PILE_HPP__