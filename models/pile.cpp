#include "pile.hpp"

#include <iostream>

Pile::Pile(const std::string& theName, bool theExtended)
    : name(theName), extended(theExtended), cards() {}
