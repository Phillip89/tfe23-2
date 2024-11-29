#ifndef SUSPENSION_HPP
#define SUSPENSION_HPP

#include <string>

class SUSPENSION {
    protected:
    int hardness;

    // Konstruktor der Basisklasse
    SUSPENSION(int hardness);
};

class SOFT : public SUSPENSION {
    protected:
    SOFT(); // Konstruktor
};

class SENSITIVE : public SUSPENSION {
    protected:
    SENSITIVE(); // Konstruktor
};

class TERRAIN : public SUSPENSION {
    protected:
    TERRAIN(); // Konstruktor
};

#endif
