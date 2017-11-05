#include "consoleview.hpp"
#include "controller.hpp"

void ConsoleView::interact(Controller* controller) { controller->accept(this); }

void ConsoleView::visit(StartController* startController) {
  startView.interact(startController);
}

void ConsoleView::visit(MoveController* moveController) {
  moveView.interact(moveController);
}
