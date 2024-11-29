#ifndef CAR_HPP
#define CAR_HPP

class Car {
    public:
    void setEngine();
    void setSuspension();
    virtual void engineStart();
    virtual void engineStop();

    protected:
    int engineStarted;
    int driving;
};

class PorscheTaycan : public Car {
    PorscheTaycan();
};

class DodgeRAM : public Car {
    DodgeRAM();
};

class VWPolo : public Car {
    VWPolo();
};

#endif