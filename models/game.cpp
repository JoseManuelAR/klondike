#include "game.hpp"
#include "deck.hpp"

#include "deckpile.hpp"
#include "foundationpile.hpp"
#include "tableaupile.hpp"
#include "wastepile.hpp"

Game::Game() : state(State::Start) {}

void Game::start() {
  createPiles();

  Deck deck;
  deck.shuffle();
  this->piles.deal(deck);
}

void Game::move(std::string origin, std::string destination,
                std::uint32_t number) {
  Pile *originPile = this->piles.getPile(origin);
  Pile *destinationPile = this->piles.getPile(destination);

  if (originPile && destinationPile && originPile != destinationPile) {
    DraggedCards *draggedCards = nullptr;
    if ((draggedCards = originPile->dragCards(number)) != nullptr) {
      destinationPile->dropCards(draggedCards);
    }
  }
}

void Game::createPiles() {
  for (std::uint8_t i = 0; i < FOUNDATION_PILES; ++i) {
    this->piles.add(new FoundationPile(i + 1));
  }
  for (std::uint8_t i = 0; i < TABLEAU_PILES; ++i) {
    this->piles.add(new TableauPile(i + 1));
  }
  this->piles.add(new WastePile());
  this->piles.add(new DeckPile());
}
