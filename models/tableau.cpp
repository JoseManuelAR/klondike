#include "tableau.hpp"
#include "deck.hpp"
#include "tableaupile.hpp"

Tableau::Tableau() : Area() {
  this->piles.add(new TableauPile(this->piles.size() + 1));
  this->piles.add(new TableauPile(this->piles.size() + 1));
  this->piles.add(new TableauPile(this->piles.size() + 1));
  this->piles.add(new TableauPile(this->piles.size() + 1));
  this->piles.add(new TableauPile(this->piles.size() + 1));
  this->piles.add(new TableauPile(this->piles.size() + 1));
  this->piles.add(new TableauPile(this->piles.size() + 1));
}
