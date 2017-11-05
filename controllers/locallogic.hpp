#include "game.hpp"
#include "logic.hpp"

class StartController;
class MoveController;

class LocalLogic : public Logic {
 public:
  LocalLogic();
  ~LocalLogic();

  Controller* getController() override;

 private:
  Game game;

  StartController* startController;
  MoveController* moveController;
};