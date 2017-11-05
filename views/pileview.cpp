#include "pileview.hpp"
#include "stackview.hpp"

#include "pile.hpp"

#include <iostream>

void PileView::draw(const Pile& thePile) const {
  std::cout << thePile.getName() << ":";
  StackView().draw(thePile.getCards(), thePile.isExtended());
  std::cout << std::endl;
}