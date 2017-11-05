#include "locallogic.hpp"
#include "movecontroller.hpp"
#include "startcontroller.hpp"

LocalLogic::LocalLogic()
    : game(),
      startController(new StartController(game)),
      moveController(new MoveController(game)) {}

LocalLogic::~LocalLogic() {
  delete startController;
  delete moveController;
}

Controller* LocalLogic::getController() {
  switch (game.getState()) {
    case State::Start:
      return startController;
    case State::Move:
      return moveController;
      break;
    case State::End:
      break;
  }
  return nullptr;
}
