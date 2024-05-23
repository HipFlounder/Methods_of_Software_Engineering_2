
#include "machine.h"
#include "exceptions.h"
#include "factory.h"
#include "product.h"

#include "iostream"
#include "cstdlib"

void Machine::setFactory(Factory *f) {
    factory = f;
    f->addMachine(this);
}

void MachineProductA::tick() {

    if (status > 0) {

        std::cout << "Machine A damaged: " << status << std::endl;
        status--;

    } else if (status == 0) {

        //Gefahrenmeldung zwischen 0 - 100
        std::srand(time(0));
        int dice = rand() % 100;    //Wert von 0-99

        //2%
        if (dice < 2) {
            std::cout << "Machine A exploded!" << std::endl;
            status = -1;
            throw MachineExplosionException();
        } //15%
        else if (dice < 15) {
            std::cout << "Machine A damaged!" << std::endl;
            status = 3;
            throw MachineFailureException();
        } else {
            std::cout << "Machine A is producing!" << std::endl;
            //2 Produkte zu Fabrik hinzufügen
            factory->addProduct(new ProductA());
            factory->addProduct(new ProductA());
        }

    }

}

void MachineProductB::tick() {

    if (status > 0) {

        std::cout << "Machine B damaged: " << status << std::endl;
        status--;

    } else if (status == 0) {

        //Gefahrenmeldung zwischen 0 - 100
        std::srand(time(0));
        int dice = rand() % 100;    //Wert von 0-99

        //5%
        if (dice < 5) {
            std::cout << "Machine B exploded!" << std::endl;
            status = -1;
            throw MachineExplosionException();
        } //20%
        else if (dice < 20) {
            std::cout << "Machine B damaged!" << std::endl;
            status = 3;
            throw MachineFailureException();
        } else {
            std::cout << "Machine B is producing!" << std::endl;
            //3 Produkt zu Fabrik hinzufügen
            factory->addProduct(new ProductB());
            factory->addProduct(new ProductB());
            factory->addProduct(new ProductB());
        }

    }

}