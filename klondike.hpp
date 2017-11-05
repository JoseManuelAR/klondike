
class Logic;
class View;

class Klondike {
 public:
  Klondike(Logic* theLogic, View* theView);
  virtual ~Klondike();

  int play();

 private:
  Logic* logic;
  View* view;
};
