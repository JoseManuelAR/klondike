#include "cardview.hpp"

#include "card.hpp"

#include <iostream>

#define RESET "\033[0m"
#define BLACK "\033[30m"
#define RED "\033[31m"

static std::string Suits[] = {"\xe2\x99\xa0", "\xe2\x99\xa3", "\xe2\x99\xa5",
                              "\xe2\x99\xa6"};

static std::string Values[] = {"A", "2", "3",  "4", "5", "6", "7",
                               "8", "9", "10", "J", "Q", "K"};

void CardView::draw(const Card& theCard) const {
  if (not theCard.isVisible()) {
    std::cout << "XX";
  } else {
    if (theCard.getFigure() == Suit::Diamond ||
        theCard.getFigure() == Suit::Heart) {
      std::cout << RED;
    }
    std::cout << Values[static_cast<int>(theCard.getNumber())]
              << Suits[static_cast<int>(theCard.getFigure())];
    std::cout << RESET;
  }
}
