#ifndef __CONSOLEVIEW_HPP__
#define __CONSOLEVIEW_HPP__

#include "moveview.hpp"
#include "startview.hpp"
#include "view.hpp"

class ConsoleView : public View {
 public:
  virtual void interact(Controller* controller) override;

  virtual void visit(StartController* startController) override;
  virtual void visit(MoveController* moveController) override;

 private:
  StartView startView;
  MoveView moveView;
};

#endif  //__CONSOLEVIEW_HPP__
