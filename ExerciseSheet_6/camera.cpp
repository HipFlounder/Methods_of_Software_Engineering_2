
#include "camera.h"
#include "exceptions.h"

#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>

int Camera::checkSensor() {

    //Gefahrenmeldung zwischen 0 - 100
    std::srand(time(0));
    int dangerLevel = rand() % 101;

    //Gefahren kleiner 20 (25%)
    if (dangerLevel < 20) {
        throw CriticalDangerException();
    }
    //Wert kleiner 20 (20%)
    if (rand() % 101 < 20) {
        errorState = true;
        throw InternalErrorException();
    }

    return dangerLevel;
}

void Camera::reset() {
    //bei 40% Wahrscheinlichkeit zurückgesetzt
    if (rand() % 101 < 40) {
        //Zurücksetzen
        errorState = false;
        std::cout << "Camera wurde zurückgesetzt!" << std::endl;
    } else {
        throw InternalErrorException();
    }

}

Camera::~Camera() {
    std::cout << "Destruktor Kamera" << std::endl;
}