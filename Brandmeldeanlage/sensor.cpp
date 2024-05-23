
#include "sensor.h"
#include "exceptions.h"

#include "cstdlib"
#include "iostream"

int SmokeDetector::getType() const {
    return 1;
}

void SmokeDetector::checkSensor() {

    std::srand(time(0));
    int dice = rand() % 100;    //Wert von 0-99

    //Wahrscheinlichkeit von 2% kann ein Fehler auftreten
    if (dice < 2) {
        //std::cout << "Error!" << std::endl;
        throw ErrorDetectedException();
    } //Wahrscheinlichkeit von 3% Feuer
    else if (dice < 5) {
        //std::cout << "Fire!" << std::endl;
        throw FireDetectedException();
    }

}

int InfraredSensor::getType() const {
    return 2;
}

void InfraredSensor::checkSensor() {

    std::srand(time(0));
    int dice = rand() % 100;    //Wert von 0-99

    //Wahrscheinlichkeit von 4% kann ein Fehler auftreten
    if (dice < 4) {
        //std::cout << "Error!" << std::endl;
        throw ErrorDetectedException();
    } //Wahrscheinlichkeit von 5% Feuer
    else if (dice < 9) {
        //std::cout << "Fire!" << std::endl;
        throw FireDetectedException();
    }

}
