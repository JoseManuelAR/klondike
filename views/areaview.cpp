#include "areaview.hpp"
#include "pilelistview.hpp"

#include "area.hpp"

void AreaView::draw(const Area& theArea) const {
  PileListView().draw(theArea.getPileList());
}