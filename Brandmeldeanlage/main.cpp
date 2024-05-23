
#include "building.h"
#include "sensor.h"

#include <iostream>

int main() {

    try {
        //Erzeuge Gebäude mit Stockwerken
        Building building(5);

        building.addSensor(0, new SmokeDetector);
        building.addSensor(0, new InfraredSensor);
        building.addSensor(1, new SmokeDetector);
        building.addSensor(2, new InfraredSensor);
        building.addSensor(3, new SmokeDetector);
        building.addSensor(4, new InfraredSensor);

        building.deleteSensor(0,0);
        building.deleteSensor(0,0);
        building.deleteSensor(0,1);

        for (int i = 0; i < 3; i++) {
            building.checkSensors();
        }
    } catch (FireAlarmException& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

}
