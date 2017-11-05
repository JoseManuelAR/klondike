#include "pilelist.hpp"
#include "pile.hpp"

PileList::PileList() {}

void PileList::deal(Deck& deck) {
  for (auto pile : list) {
    pile->deal(deck);
  }
}

Pile* PileList::getPile(const std::string& name) const {
  std::vector<Pile*>::const_iterator it;
  if ((it = std::find_if(list.cbegin(), list.cend(), [name](Pile* s) {
         return (s)->getName() == name;
       })) != list.end()) {
    return *it;
  }
  return nullptr;
}

bool PileList::won() const {
  for (const auto pile : list) {
    if (not pile->won()) {
      return false;
    }
  }
  return true;
}
