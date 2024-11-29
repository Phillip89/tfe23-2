#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <string>

class ENGINE {
    protected:
    int cubicCapacity; // Hubraum
    int power;         // Leistung

    // Konstruktor der Basisklasse
    ENGINE(int cubicCapacity, int power);
};

class V8 : public ENGINE {
    protected:
    V8(); // Konstruktor
};

class V6 : public ENGINE {
    protected:
    V6(); // Konstruktor
};

class EEngine : public ENGINE {
    protected:
    EEngine(); // Konstruktor
};

#endif
