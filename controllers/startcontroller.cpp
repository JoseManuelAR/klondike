#include "startcontroller.hpp"
#include "controllervisitor.hpp"

StartController::StartController(Game& theGame) : Controller(theGame) {}

void StartController::accept(ControllerVisitor* visitor) {
  visitor->visit(this);
}
