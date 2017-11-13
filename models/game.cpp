#include "game.hpp"
#include "deck.hpp"
#include "movement.hpp"

#include "deckpile.hpp"
#include "foundationpile.hpp"
#include "tableaupile.hpp"
#include "wastepile.hpp"

#include <iostream>

Game::Game()
    : state(State::Start), piles(), wastePile(nullptr), deckPile(nullptr) {}

void Game::start() {
  createPiles();
  dealCards();
  state = State::Move;
}

void Game::move(const Movement &movement) {
  movement.update(this->piles);
  if (movement.getOriginPile() == deckPile &&
      movement.getDestinationPile() == wastePile) {
    if (not movement.flip()) {
      this->moveWasteToDeck();
    }
  } else {
    movement.execute();
  }
  state = this->won() ? State::End : State::Move;
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

void Game::dealCards() {
  Deck deck;
  deck.shuffle();
  this->piles.deal(deck);
}

void Game::moveWasteToDeck() {
  while (not wastePile->empty()) {
    deckPile->push(wastePile->top());
    deckPile->top().downTurned();
    wastePile->pop();
  }
}
