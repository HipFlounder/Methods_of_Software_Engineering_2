
#include "factory.h"
#include "machine.h"

#include <iostream>

int main() {

    Factory factory;

    MachineProductA* machineA = new MachineProductA;
    MachineProductB* machineB = new MachineProductB;

    machineA->setFactory(&factory);
    machineB->setFactory(&factory);

    factory.run(10);

    std::cout << "Product A: " << factory.getProductACount() << std::endl;
    std::cout << "Product B: " << factory.getProductBCount() << std::endl;

    std::cout << "Product A Map: " << factory.getProductASize() << std::endl;
    std::cout << "Product B Map: " << factory.getProductBSize() << std::endl;

    return 0;
}