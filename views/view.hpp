#include "controllervisitor.hpp"

class Controller;

class View : public ControllerVisitor {
 public:
  virtual ~View() = default;

  virtual void interact(Controller* controller) = 0;
};