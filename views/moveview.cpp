#include "moveview.hpp"
#include "gameview.hpp"
#include "movecontroller.hpp"
#include "movement.hpp"

#include "movementdialog.hpp"
#include "windialog.hpp"

void MoveView::interact(MoveController *moveController) {
  Movement movement = MovementDialog().get();
  moveController->move(movement);
  GameView().draw(moveController->getGame());
  if (moveController->won()) {
    WinDialog().show();
  }
}
