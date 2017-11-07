#include "deckarea.hpp"
#include "deckpile.hpp"

DeckArea::DeckArea() : Area() { this->piles.add(new DeckPile()); }
