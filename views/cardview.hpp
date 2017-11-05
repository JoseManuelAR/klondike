#ifndef __CARDVIEW_HPP__
#define __CARDVIEW_HPP__

class Card;

class CardView {
 public:
  void draw(const Card& theCard) const;
};

#endif  //__CARDVIEW_HPP__