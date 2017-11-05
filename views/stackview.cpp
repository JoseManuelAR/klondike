#include "stackview.hpp"
#include "cardview.hpp"
#include "emptyview.hpp"

#include "stack.hpp"

#include <iostream>

void StackView::draw(const Stack& theStack, bool isExtended) const {
  if (theStack.empty()) {
    EmptyView().draw();
  } else {
    if (isExtended) {
      Stack cards = theStack;
      while (not cards.empty()) {
        CardView().draw(cards.top());
        std::cout << " ";
        cards.pop();
      }
    } else {
      std::cout << "[" << theStack.size() << "] ";
      CardView().draw(theStack.top());
    }
  }
  std::cout << std::flush;
}
