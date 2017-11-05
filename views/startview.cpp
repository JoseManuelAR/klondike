#include "startview.hpp"
#include "gameview.hpp"
#include "startcontroller.hpp"

void StartView::interact(StartController* startController) {
  startController->start();
  GameView().draw(startController->getGame());
}
