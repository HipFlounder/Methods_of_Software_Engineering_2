
#ifndef FABRIK_MACHINE_H
#define FABRIK_MACHINE_H

#include "iostream"

//forward declaration
class Factory;

class Machine {

protected:
    Factory* factory = nullptr;
    //int status = 0; // > 0 temporary

public:
    virtual ~Machine() {}

    virtual void tick() = 0;

    void setFactory(Factory* f);

};


class MachineProductA : public Machine {

protected:
    int status = 0; // > 0 temporary

public:
    virtual ~MachineProductA() {
        std::cout << "Destructor Machine B" << std::endl;
    }

    void tick() override;

};


class MachineProductB : public Machine {

protected:
    int status = 0; // > 0 temporary

public:
    virtual ~MachineProductB() {
        std::cout << "Destructor Machine B" << std::endl;
    }

    void tick() override;

};

#endif //FABRIK_MACHINE_H
