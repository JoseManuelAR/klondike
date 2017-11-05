#include <cstdint>

class Controller;
class Logic {
 public:
  virtual ~Logic() = default;

  virtual Controller* getController() = 0;

 private:
};