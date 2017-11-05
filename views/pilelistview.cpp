#include "pilelistview.hpp"
#include "pileview.hpp"

#include "pilelist.hpp"

void PileListView::draw(const PileList& thePileList) const {
  for (auto pile : thePileList.getList()) {
    PileView().draw(*pile);
  }
}