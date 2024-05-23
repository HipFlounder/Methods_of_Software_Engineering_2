
#include "car.h"
#include "exceptions.h"

#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>

bool VWBus::checkCar() {

    //std::srand(time(0));
    int chance = rand() % 101;

    if (chance < 5) {
        throw BrokenMotorException();
    } else if (chance < 15) {
        throw ElectronicsFaultException();
    }

    return true;

}

bool FordFocus::checkCar() {

    //std::srand(time(0));
    int chance = rand() % 101;

    if (chance < 8) {
        throw BrokenMotorException();
    } else if (chance < 14) {
        throw ElectronicsFaultException();
    } else if (chance < 29) {
        throw EmissionsTooDirtyException();
    }

    return true;
}

bool FerrariF40::checkCar() {

    return true;

}


bool Kleinbus::checkCar() {

    //std::srand(time(0));
    int chance = rand() % 101;

    if (chance < 15) {
        throw BrokenMotorException();
    } else if (chance < 25) {
        throw ElectronicsFaultException();
    } else if (chance < 30) {
        throw EmissionsTooDirtyException();
    }

    return true;

}









