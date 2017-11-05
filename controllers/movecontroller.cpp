#include "movecontroller.hpp"
#include "controllervisitor.hpp"

MoveController::MoveController(Game& theGame) : Controller(theGame) {}

void MoveController::accept(ControllerVisitor* visitor) {
  visitor->visit(this);
}
