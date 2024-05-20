
#include "laser.h"
#include "exceptions.h"

#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>

int Laser::checkSensor() {

    //Gefahrenmeldung zwischen 0 - 80
    std::srand(time(0));
    int dangerLevel = rand() % 81;

    //Gefahren kleiner 16 (20%)
    if (dangerLevel < 16) {
        throw CriticalDangerException();
    }
    //Wert zwischen 0 und 99 -> unter 10 (10%)
    if (rand() % 100 < 10) {
        errorState = true;
        throw InternalErrorException();
    }

    return dangerLevel;
}

void Laser::reset() {
    //bei 50% Wahrscheinlichkeit zurückgesetzt
    if (rand() % 101 < 50) {
        //Zurücksetzen
        errorState = false;
        std::cout << "Laser wurde zurückgesetzt!" << std::endl;
    } else {
        throw InternalErrorException();
    }

}

Laser::~Laser() {
    std::cout << "Destruktor Laser" << std::endl;
}