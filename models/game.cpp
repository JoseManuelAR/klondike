#include "game.hpp"
#include "deck.hpp"

#include "deckarea.hpp"
#include "foundation.hpp"
#include "tableau.hpp"
#include "waste.hpp"

#include "pile.hpp"

#include <iostream>

Game::Game() : state(State::Start) {}

void Game::start() {
  Deck deck;

  deck.shuffle();

  this->areas.add(new Foundation());
  this->areas.add(new Tableau());
  this->areas.add(new Waste());
  this->areas.add(new DeckArea());

  this->areas.deal(deck);
}

void Game::move(std::string origin, std::string destination,
                std::uint32_t number) {
  std::cout << "Moving from [" << origin << "] to [" << destination << "] "
            << number << " cards" << std::endl;

  Pile* originPile = getPile(origin);
  Pile* destinationPile = getPile(destination);

  if (originPile) {
    if (destinationPile) {
      if (originPile != destinationPile) {
        DraggedCards* draggedCards = nullptr;
        if ((draggedCards = originPile->dragCards(number)) != nullptr) {
          destinationPile->dropCards(draggedCards);
        }
      }
    }
  }
}

bool Game::won() const { return this->areas.won(); }
