#include "suspension.hpp"

// Konstruktor der Basisklasse ENGINE
SUSPENSION::SUSPENSION(int hardness)
    : hardness(hardness) {}

SOFT::SOFT() : SUSPENSION(25) {}

SENSITIVE::SENSITIVE() : SUSPENSION(50) {}

TERRAIN::TERRAIN() : SUSPENSION(100) {}
