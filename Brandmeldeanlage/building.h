
#ifndef BRANDMELDEANLAGE_BUILDING_H
#define BRANDMELDEANLAGE_BUILDING_H

#include "exceptions.h"

#include <iostream>
#include <map>
#include <vector>

//forward declaration
class Siren;
class Sensor;

class Building {

protected:
    int floors = 0;
    //Sirenen
    std::vector<Siren*> innerSirens;
    Siren* outerSiren;

    //Eine Map pro Stockwert
    std::vector<std::map<int, Sensor*>> sensors;
    int nextSensorId;

public:
    //Konstruktor übergibt Anzahl Floors
    Building(int flors);
    //Destruktor
    ~Building();

    int addSensor(int floor, Sensor* sensor);

    Sensor* getSensor(int floor, int id);

    void deleteSensor(int floor, int id);

    void checkSensors();

    void cancelAlarm();

};

#endif //BRANDMELDEANLAGE_BUILDING_H
