#include "engine.hpp"

// Konstruktor der Basisklasse ENGINE
ENGINE::ENGINE(int cubicCapacity, int power)
    : cubicCapacity(cubicCapacity), power(power) {}

// Konstruktor der V8-Klasse
V8::V8() : ENGINE(5000, 450) {} // 5000 ccm und 450 PS für einen V8

// Konstruktor der V6-Klasse
V6::V6() : ENGINE(3000, 350) {} // 3000 ccm und 350 PS für einen V6

// Konstruktor der EEngine-Klasse
EEngine::EEngine() : ENGINE(0, 200) {} // 0 ccm und 200 PS für einen Elektromotor
