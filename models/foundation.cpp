#include "foundation.hpp"
#include "deck.hpp"
#include "foundationpile.hpp"

Foundation::Foundation() : Area() {
  this->piles.add(new FoundationPile(this->piles.size() + 1));
  this->piles.add(new FoundationPile(this->piles.size() + 1));
  this->piles.add(new FoundationPile(this->piles.size() + 1));
  this->piles.add(new FoundationPile(this->piles.size() + 1));
}
