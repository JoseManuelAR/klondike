#include "deck.hpp"
#include <algorithm>
#include <random>

Deck::Deck() : cards() {
  for (std::uint8_t suit = static_cast<std::uint8_t>(Suit::Spade);
       suit < static_cast<std::uint8_t>(Suit::Last); ++suit) {
    for (std::uint8_t value = static_cast<std::uint8_t>(Value::Ace);
         value < static_cast<std::uint8_t>(Value::Last); ++value) {
      cards.emplace_back(
          Card(static_cast<Value>(value), static_cast<Suit>(suit)));
    }
  }
}

void Deck::shuffle() {
  std::random_device rd;
  std::mt19937 g(rd());

  std::shuffle(cards.begin(), cards.end(), g);
}
