#include "waste.hpp"
#include "wastepile.hpp"

Waste::Waste() : Area() { this->piles.add(new WastePile()); }
