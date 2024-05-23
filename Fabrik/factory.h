
#ifndef FABRIK_FACTORY_H
#define FABRIK_FACTORY_H

#include "machine.h"
#include "product.h"

#include <map>
#include <iostream>

//forward declaration
//class Product;

class Factory {

protected:
    int productACount = 0;
    int productBCount = 0;
    std::map<int, Machine*> machines;
    int nextMachineID = 0;
    std::map<int, Product*> productA;
    int nextProductAID = 0;
    std::map<int, Product*> productB;
    int nextProductBID = 0;

public:

    Factory() = default;
    virtual ~Factory() {
        for (auto& e : machines) {       //Mengenschleife
            std::cout << "Lösche Element: " << e.first << std::endl;
            delete e.second;    //Second = Value ; First = ID
        }
        //Speicher vom Produkt A freigeben
        for (auto& e : productA) {       //Mengenschleife
            std::cout << "Lösche Produkt A: " << e.first << std::endl;
            delete e.second;    //Second = Value ; First = ID
        }
        //Speicher vom Produkt B freigeben
        for (auto& e : productB) {       //Mengenschleife
            std::cout << "Lösche Produkt B: " << e.first << std::endl;
            delete e.second;    //Second = Value ; First = ID
        }

        machines.clear();
        productA.clear();
        productB.clear();

        std::cout << "Destructor Factory" << std::endl;
    }

    unsigned addMachine(Machine* m);

    Machine* getMachine(unsigned id);

    void deleteMachine(unsigned id);

    void addProduct(Product* p);

    unsigned getProductACount();

    unsigned getProductBCount();

    unsigned getProductASize() {
        return productA.size();
    }

    unsigned getProductBSize() {
        return productB.size();
    }

    void run(unsigned iterations);

};

#endif //FABRIK_FACTORY_H
