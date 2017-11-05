#include "deckarea.hpp"
#include "deckpile.hpp"

DeckArea::DeckArea() : Area("Deck") { this->piles.add(new DeckPile()); }
