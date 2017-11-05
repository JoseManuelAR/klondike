#include "tableau.hpp"
#include "deck.hpp"
#include "tableaupile.hpp"

Tableau::Tableau() : Area("Tableau") {
  this->piles.add(new TableauPile(this->piles.size() + 1));
  this->piles.add(new TableauPile(this->piles.size() + 1));
  this->piles.add(new TableauPile(this->piles.size() + 1));
  this->piles.add(new TableauPile(this->piles.size() + 1));
  this->piles.add(new TableauPile(this->piles.size() + 1));
  this->piles.add(new TableauPile(this->piles.size() + 1));
  this->piles.add(new TableauPile(this->piles.size() + 1));
}
