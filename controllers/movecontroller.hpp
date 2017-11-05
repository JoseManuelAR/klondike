#ifndef __MOVECONTROLLER_HPP__
#define __MOVECONTROLLER_HPP__

#include "controller.hpp"

class MoveController : public Controller {
 public:
  MoveController(Game& theGame);

  virtual void accept(ControllerVisitor* visitor) override;
};

#endif  //__MOVECONTROLLER_HPP__