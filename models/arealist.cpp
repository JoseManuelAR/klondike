#include "arealist.hpp"
#include "area.hpp"

AreaList::AreaList() : list() {}

void AreaList::deal(Deck& deck) {
  for (auto area : list) {
    area->deal(deck);
  }
}

Pile* AreaList::getPile(const std::string& name) const {
  Pile* pile = nullptr;

  for (const auto area : list) {
    if ((pile = area->getPile(name)) != nullptr) {
      return pile;
    }
  }
  return nullptr;
}

bool AreaList::won() const {
  for (const auto area : list) {
    if (not area->won()) {
      return false;
    }
  }
  return true;
}
