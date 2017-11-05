#include "arealistview.hpp"
#include "areaview.hpp"

#include "arealist.hpp"

void AreaListView::draw(const AreaList& theAreaList) const {
  for (auto area : theAreaList.getList()) {
    AreaView().draw(*area);
  }
}