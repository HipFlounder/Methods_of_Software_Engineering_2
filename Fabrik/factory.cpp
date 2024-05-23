
#include "factory.h"
#include "exceptions.h"
#include "product.h"
#include "machine.h"

#include <iostream>
#include <unistd.h>
#include <vector>

//Fügt eine neuen Maschine hinzu. Der Rückgabewert ist eine ID, die die jeweilige Maschine eindeutig identifiziert.
unsigned int Factory::addMachine(Machine *m) {
    if (m) {
        int id = nextMachineID++;
        std::cout << "Adding Machine with id " << id << std::endl;
        machines[id] = m;
        return id;
    } else {
        throw InvalidArgument();
    }
}

//Gibt die Maschine mit der angegebenen ID zurück.
Machine *Factory::getMachine(unsigned int id) {
    try {
        std::cout << "Getting Machine with id " << id << std::endl;
        return machines.at(id);
    } catch (std::out_of_range& e) {    //falls sensor an ID nicht gefunden wird, wird eine out_of_range Exception geworfen
        std::cout << "Machine with id " << id << " does not exist. " << std::endl;
        throw InvalidArgument();
    }
}

//Entfernt die Maschine mit der angegebenen ID und gibt alle damit verbundenen Ressourcen wieder frei.
void Factory::deleteMachine(unsigned int id) {
    std::cout << "Deleting Machine with id " << id << std::endl;
    if (machines.erase(id) == 0) {
        std::cout << "Machine with id " << id << " does not exist. " << std::endl;
        throw InvalidArgument();
    }
}

//Übergibt ein neues Produkt der Fabrik. Die Fabrik muss dann den Typ des Produkts bestimmen und in das entsprechende Lager einsortieren.
void Factory::addProduct(Product *p) {
    int type = p->getType();

    switch(type) {
        case 1: {
            int idA = nextProductAID++;
            //std::cout << "Adding Product A with id " << idA << std::endl;
            productA[idA] = p;
            productACount++;
            break;
        }
        case 2: {
            int idB = nextProductBID++;
            //std::cout << "Adding Product B with id " << idB << std::endl;
            productB[idB] = p;
            productBCount++;
            break;
        }
        //Wenn ein unbekanntes Produkt übergeben wird, dann soll eine MachineFailureException geworfen werden.
        default:
            throw MachineFailureException();
    }
    //delete p;
}

unsigned int Factory::getProductACount() {
    return productACount;
}

unsigned int Factory::getProductBCount() {
    return productBCount;
}

//Diese Methode implementiert die Zeitschleife. Der Eingabeparameter iterations gibt an, nach wievielen Iterationen die Zeitschleife abgebrochen werden soll.
void Factory::run(unsigned iterations) {

    for (unsigned i = 0; i < iterations || iterations == 0; i++) {
        std::cout << "Iteration: " << i << std::endl;
        std::vector<unsigned> removedMachines;

        for (auto& e : machines) {
            try {
            //Tick für jede Maschine
            e.second->tick();
            } catch(MachineFailureException& ex) {
                //std::cout << "Failure" << std::endl;
            } catch(MachineExplosionException& ex) {
                //std::cout << "Explosion" << std::endl;
                //removedMachines.push_back(e.first);
                std::cout << "Removing machine " << e.first << std::endl;
                int id = e.first;
                deleteMachine(id);
            }/*
            for (auto id : removedMachines) {
                std::cout << "Removing machine " << e.first << std::endl;
                deleteMachine(id);
            }*/

        }

        sleep(1);
    }

}