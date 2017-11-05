#ifndef __STARTCONTROLLER_HPP__
#define __STARTCONTROLLER_HPP__

#include "controller.hpp"

class StartController : public Controller {
 public:
  StartController(Game& theGame);

  virtual void accept(ControllerVisitor* visitor) override;
};

#endif  //__STARTCONTROLLER_HPP__