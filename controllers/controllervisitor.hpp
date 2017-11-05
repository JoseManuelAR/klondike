
class StartController;
class MoveController;

class ControllerVisitor {
 public:
  virtual void visit(StartController* startController) = 0;
  virtual void visit(MoveController* moveController) = 0;
};
