
#include "ultrasonic.h"
#include "exceptions.h"

#include <cstdlib>  //für rand()
#include <ctime>
#include <exception>
#include <iostream>

int Ultrasonic::checkSensor() {

    //Gefahrenmeldung zwischen 0 - 60
    std::srand(time(0));
    int dangerLevel = rand() % 61;

    //Gefahren kleiner 6 (10%)
    if (dangerLevel < 6) {
        throw CriticalDangerException();
    }
    //Wert kleiner 20 (20%)
    if (dangerLevel < 12) {
        errorState = true;
        throw InternalErrorException();
    }

    return dangerLevel;
}

void Ultrasonic::reset() {
    //bei 60% Wahrscheinlichkeit zurückgesetzt
    if (rand() % 101 < 60) {
        errorState = false;
        std::cout << "Ultrasonic wurde zurückgesetzt!" << std::endl;
    } else {
        throw InternalErrorException();
    }

}

Ultrasonic::~Ultrasonic() {
    std::cout << "Destruktor Ultraschallsensor" << std::endl;
}