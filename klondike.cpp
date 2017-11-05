#include "klondike.hpp"
#include "logic.hpp"
#include "view.hpp"

Klondike::Klondike(Logic* theLogic, View* theView)
    : logic(theLogic), view(theView) {}

Klondike::~Klondike() {
  delete logic;
  delete view;
}

int Klondike::play() {
  Controller* controller;

  do {
    controller = logic->getController();
    if (controller != nullptr) {
      view->interact(controller);
    }
  } while (controller != nullptr);
  return 0;
}