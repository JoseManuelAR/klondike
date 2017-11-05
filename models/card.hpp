#ifndef __CARD_HPP__
#define __CARD_HPP__

#include <cstdint>

enum class Color : std::uint8_t { Red = 0, Black };

enum class Suit : std::uint8_t { Spade = 0, Club, Heart, Diamond, Last };

enum class Value : std::uint8_t {
  Ace = 0,
  Two,
  Three,
  Four,
  Five,
  Six,
  Seven,
  Eight,
  Nine,
  Ten,
  Jack,
  Queen,
  King,
  Last
};

class Card {
 public:
  Card(Value theNumber, Suit theFigure)
      : number(theNumber), figure(theFigure), visible(false){};

  Color getColor() const {
    return (figure == Suit::Heart || figure == Suit::Diamond) ? Color::Red
                                                              : Color::Black;
  }
  Suit getFigure() const { return figure; }
  Value getNumber() const { return number; }
  bool isVisible() const { return visible; }

  void upTurned() { visible = true; }
  void downTurned() { visible = false; }

 protected:
  Value number;
  Suit figure;
  bool visible;
};

#endif  //__CARD_HPP__