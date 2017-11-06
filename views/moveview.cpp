#include "moveview.hpp"
#include "gameview.hpp"
#include "movecontroller.hpp"
#include "strings.hpp"

#include <algorithm>
#include <iostream>
#include <regex>
#include <sstream>

void MoveView::interact(MoveController *moveController) {
  std::string movement;
  std::cout << "\33[K" << std::flush;
  std::cout << "Enter a movement <origin> <destination> <number[default 1]> "
               "(i.e: T1 T4 2, T2 F1):"
            << std::flush;
  std::getline(std::cin, movement);
  trim(movement);
  std::transform(movement.begin(), movement.end(), movement.begin(), ::toupper);

  std::regex re("[\\s]+");
  std::sregex_token_iterator it(movement.begin(), movement.end(), re, -1);
  std::sregex_token_iterator reg_end;

  std::string origin = it->str();
  std::string destination;
  std::uint8_t number = 1;

  if (++it != reg_end) {
    destination = it->str();
    if (++it != reg_end) {
      number = std::stoi(it->str());
    }
  }
  moveController->move(origin, destination, number);
  GameView().draw(moveController->getGame());
  if (moveController->won()) {
    std::cout << "Ganador!!!!!" << std::flush;
  }
}
