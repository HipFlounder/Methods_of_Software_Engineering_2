
#include "robot.h"
#include "exceptions.h"
#include "sensor.h"

#include <iostream>
#include <unistd.h>

//Neuen Sensor zu Roboter hinzufügen
int Robot::addSensor(Sensor* sensor) {
    if (sensor) {
        int id = nextSensorID++;
        std::cout << "Adding sensor with id " << id << std::endl;
        sensors[id] = sensor;
        return id;
    } else {
        throw InvalidArgument();
    }
    /*
    sensors.push_back(sensor);
    return (int)sensors.size() - 1; //ID des neuen Sensor
    */
}

//Id von Sensor zurückgeben
Sensor* Robot::getSensor(int id) {
    /*
    if (id < 0 || id >= (int)sensors.size()) {
        throw InvalidArgument();
        return nullptr;
    }
    return sensors[id];
     */
    try {
        std::cout << "Getting sensor with id " << id << std::endl;
        return sensors.at(id);
    } catch (std::out_of_range& e) {    //falls sensor an ID nicht gefunden wird, wird eine out_of_range Exception geworfen
        std::cout << "Sensor with id " << id << " does not exist. " << std::endl;
        throw InvalidArgument();
    }
}

//Entfernt Sensor bei ID
void Robot::deleteSensor(int id) {
    /*
    if (id < 0 || id >= (int)sensors.size()) {
        throw InvalidArgument();
    }
    sensors.erase(sensors.begin() + id);
    delete sensors[id];   //für dynamischen Speicher: mit new allokiert
     */

    std::cout << "Deleting sensor with id " << id << std::endl;
    if (sensors.erase(id) == 0) {
        std::cout << "Sensor with id " << id << " does not exist. " << std::endl;
        throw InvalidArgument();
    }
}

//Abfrage Status der Sensoren
void Robot::eventLoop() {
    /*
    int distance = 0;
    bool criticalDanger = false;
    int criticalDangerCounter = 0;
    int iteration = 0;

    //30 Iterationen
    while (iteration < 30) {

        std::cout << "Iteration " << iteration << std::endl;

        if (criticalDanger && criticalDangerCounter < 3){
            criticalDangerCounter ++;
            std::cout << "Aussetzer: " << criticalDangerCounter << std::endl;
            std::cout << "-------------------------------------------------------" << std::endl;
            sleep(1);
            iteration++;
            continue;
        } else {
            criticalDanger = false;
        }

        int maxDangerLevel = 0;

        //Über Sensoren iterieren
        //for (Sensor* sensor : sensors) {
        for (auto & sensor : sensors) {
            try {
                //Sensor abfragen und höchsten Wert speichern
                int dangerLevel = sensor.second->checkSensor();
                if (dangerLevel > maxDangerLevel) {
                    maxDangerLevel = dangerLevel;
                }

            } catch (CriticalDangerException& e) {
                motor.emergencyBrake();
                criticalDanger = true;
                criticalDangerCounter = 0;
                std::cout << "Kritischer Fehler: Notstopp!" << std::endl;
                break;

            } catch (InternalErrorException& e) {
                motor.setSpeed(1);
                std::cout << "Interner Sensorfehler: Geschwindigkeitsreduktion!" << std::endl;

            }

            if (sensor.second->getErrorState()) {
                std::cout << "Versuche Sensor zu resetten!" << std::endl;

                try {
                    sensor.second->reset();
                } catch (InternalErrorException& e) {
                    std::cout << "Reset war nicht erfolgreich!" << std::endl;
                }
            }

        }

        bool errorState = false;

        for (auto & sensor : sensors) {
            if (sensor.second->getErrorState()) {
                errorState = true;
            }
        }

        if (!errorState && !criticalDanger) {
            std::cout << "Höchst gemeldete Gefahr: " << maxDangerLevel << std::endl;
            motor.setSpeed(10 - maxDangerLevel/10);
            //if motor = 0 -> speed = 1
        }

        std::cout << "Roboter fährt: " << motor.getSpeed() << std::endl;
        std::cout << "-------------------------------------------------------" << std::endl;
        distance += motor.getSpeed();
        sleep(1);
        iteration++;

    }
    //Ausgabe Gesamtstrecke
    std::cout << "Der Roboter hat eine Strecke von " << distance << " m zurückgelegt!" << std::endl;
    */

    //Musterlösung
    int emergencyStopCount = 0;

    for (int i = 0; i < 10; i++) {

        if (emergencyStopCount == 0) {
            try {
                int maxDangerLevel = 0;
                for (auto& e : sensors) {
                    try {
                        if (e.second->getErrorState()) {
                            e.second->reset();
                        }
                        int dangerLevel = e.second->checkSensor();
                        if (dangerLevel > maxDangerLevel) {
                            maxDangerLevel = dangerLevel;
                        }
                    } catch(InternalErrorException& e) {
                        maxDangerLevel = 100;
                    }
                }
                int speed = (100 - maxDangerLevel)/10;
                if (speed == 0) {
                    speed = 1;
                }
                motor.setSpeed(speed);
            } catch(CriticalDangerException& e) {
                std::cout << "Caught critical danger exception, doing an emergency brake!" << std::endl;
                motor.emergencyBrake();
                emergencyStopCount = 3;
            }
        } else {
            std::cout << "Still in emergency mode (" << emergencyStopCount << ")" << std::endl;
            emergencyStopCount--;
        }

        sleep(1);
    }

}
