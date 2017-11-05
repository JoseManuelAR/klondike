#include "foundation.hpp"
#include "deck.hpp"
#include "foundationpile.hpp"

Foundation::Foundation() : Area("Foundation") {
  this->piles.add(new FoundationPile(this->piles.size() + 1));
  this->piles.add(new FoundationPile(this->piles.size() + 1));
  this->piles.add(new FoundationPile(this->piles.size() + 1));
  this->piles.add(new FoundationPile(this->piles.size() + 1));
}
