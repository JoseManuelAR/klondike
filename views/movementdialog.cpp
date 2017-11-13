#include "movementdialog.hpp"
#include "movement.hpp"
#include "strings.hpp"

#include <algorithm>
#include <iostream>
#include <regex>
#include <sstream>

Movement MovementDialog::get() const {
  bool ok = false;
  std::string origin;
  std::string destination;
  std::uint8_t numberOfCards;

  do {
    std::string movement;
    std::cout << "\33[K" << std::flush;
    std::cout << "Enter a movement:" << std::flush;

    try {
      std::getline(std::cin, movement);
      trim(movement);
      std::transform(movement.begin(), movement.end(), movement.begin(),
                     ::toupper);

      std::regex re("[\\s]+");
      std::sregex_token_iterator it(movement.begin(), movement.end(), re, -1);
      std::sregex_token_iterator reg_end;

      origin = it->str();
      numberOfCards = 1;
      if (++it != reg_end) {
        destination = it->str();
        if (++it != reg_end) {
          numberOfCards = std::stoi(it->str());
        }
      }
      ok = true;
    } catch (...) {
    }
  } while (not ok);
  return (Movement(origin, destination, numberOfCards));
}