#include "game.hpp"
#include "deck.hpp"

#include "deckpile.hpp"
#include "foundationpile.hpp"
#include "tableaupile.hpp"
#include "wastepile.hpp"

#include <iostream>

Game::Game()
    : state(State::Start), piles(), wastePile(nullptr), deckPile(nullptr) {}

void Game::start() {
  createPiles();

  Deck deck;
  deck.shuffle();
  this->piles.deal(deck);
}

void Game::move(std::string origin, std::string destination,
                std::uint8_t numberOfCards) {
  Pile *originPile = this->piles.getPile(origin);
  Pile *destinationPile = this->piles.getPile(destination);
  if (originPile != nullptr && destinationPile != nullptr) {
    Stack cards;
    if (originPile->canDragTo(destinationPile) &&
        originPile->dragCards(numberOfCards, cards) &&
        destinationPile->dropCards(cards)) {
      originPile->acceptDragCards();
    } else {
      if (numberOfCards == 1 && originPile == deckPile &&
          destinationPile == wastePile) {
        while (not wastePile->empty()) {
          deckPile->push(wastePile->top());
          deckPile->top().downTurned();
          wastePile->pop();
        }
      } else {
        originPile->rejectDragCards(cards);
      }
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
  wastePile = new WastePile();
  this->piles.add(wastePile);
  deckPile = new DeckPile();
  this->piles.add(deckPile);
}
