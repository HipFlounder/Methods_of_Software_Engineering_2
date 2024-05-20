
#ifndef EXERCISESHEET_6_ROBOT_H
#define EXERCISESHEET_6_ROBOT_H

#include "motor.h"
#include "sensor.h"

#include <map>
#include <string>
#include <memory>

//forward declaration
class Motor;

class Robot {

protected:
    Motor motor;
    //std::vector<Sensor*> sensors;
    std::map<int, Sensor*> sensors;
    int nextSensorID = 0;

public:
    //Default Konstruktor
    Robot() = default;

    //Desturktor
    ~Robot() {
        /*
        for (int i = sensors.size()-1; i >= 0; i--) {
            deleteSensor(i);
        }
        std::cout << "Destruktor Roboter" << std::endl;
         */

        for (auto& e : sensors) {       //Mengenschleife
            std::cout << "Lösche Element: " << e.first << std::endl;
            delete e.second;    //Second = Value ; First = ID
        }

        std::cout << "Destruktor Roboter" << std::endl;
    }

    int addSensor(Sensor* sensor);

    Sensor* getSensor(int id);

    void deleteSensor(int id);

    void eventLoop();

};

#endif //EXERCISESHEET_6_ROBOT_H
