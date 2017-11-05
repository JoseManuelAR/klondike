#include "waste.hpp"
#include "wastepile.hpp"

Waste::Waste() : Area("Waste") { this->piles.add(new WastePile()); }
