
#include "building.h"
#include "siren.h"
#include "sensor.h"

#include <iostream>
#include <unistd.h>

//Konstruktor übergibt Anzahl Floors
Building::Building(int floors) : floors(floors), nextSensorId(0) {
    if (floors < 0) {
        throw InvalidArgument();
    }
    for (int i = 0; i < floors; i++) {
        //Erzeuge pro Stockwerk eine Innensirene
        innerSirens.push_back(new Siren());
        //Füge pro Stockwerk dem Vektor eine eigene Map hinzu
        sensors.push_back(std::map<int, Sensor*>());

    }
    outerSiren = new Siren();
}

//Destruktor
Building::~Building() {
    //Speicher für alle Innensensoren freigeben
    for (auto& e : innerSirens) {       //Mengenschleife über Vector
        std::cout << "Delete Inner Sirene: " << e << std::endl;
        delete e;
    }
    //Speicher für Außensensor freigeben
    delete outerSiren;
    //Speicher Sensoren pro Stockwerk freigeben
    for (auto& vector : sensors) {       //Mengenschleife über Vector (Stockwerke)
        for (auto& map : vector) {                 //Mengenschleife über Map (Sensoren)
            std::cout << "Delete Sensor: " << map.first << std::endl;
            delete map.second;  //Second = Value ; First = ID
        }
    }

    std::cout << "Destructor Building" << std::endl;
}

// Fügt einen neuen Sensor zum angegebenen Stockwerk hinzu (Nummerierung startet bei 0).
// Der Rückgabewert ist eine ID, die den jeweiligen Sensor eindeutig im jeweiligen Stockwerk identifiziert
int Building::addSensor(int floor, Sensor* sensor) {
    if (floor >= 0 && sensor) {
        int id = nextSensorId++;
        std::cout << "Adding Sensor on Floor "<< floor << " with id " << id << std::endl;
        sensors[floor][id] = sensor;
        return id;
    } else {
        throw InvalidArgument();
    }
}

//Gibt den Sensor im angegebenen Stockwerk mit der angegebenen ID zurück.
Sensor* Building::getSensor(int floor, int id) {
    try {
        std::cout << "Getting Sensor on Floor "<< floor << " with id " << id << std::endl;
        return sensors[floor].at(id);
    } catch (std::out_of_range& e) {
        throw InvalidArgument();
    }
}

//Zerstört den Sensor im angegebenen Stockwerk mit der angegebenen ID.
void Building::deleteSensor(int floor, int id) {
    //iterator auf Objekt und kontrolle ob exisitiert
    auto it = sensors[floor].find(id);
    if (it != sensors[floor].end()) {
        std::cout << "Deleting Sensor on Floor " << floor << " of type " << it->second->getType() << std::endl;
        delete it->second;
        sensors[floor].erase(it);
    } else {
        std::cout << "Sensor on Floor " << floor << " with ID " << id << " does not exist." << std::endl;
        throw InvalidArgument();
    }

    /*
    std::cout << "Deleting Sensor on Floor "<< floor << " of type " << sensors[floor][id]->getType() << std::endl;
    delete sensors[floor][id];
    if (sensors[floor].erase(id) == 0) {
        std::cout << "Sensor on Floor "<< floor << " of type " << sensors[floor][id]->getType() << " does not exist." << std::endl;
        throw InvalidArgument();
    }*/
}

//Überprüft alle Sensoren in allen Stockwerken. Diese Funktion wird in regelmäßigen Zeitabständen aufgerufen
void Building::checkSensors() {

    //Iteriere über Anzahl Stockwerke
    for (int i = 0; i < floors; i++) {

        for (auto& e : sensors[i]) {                 //Mengenschleife über Map (Sensoren)

            try {
                std::cout << "Check Sensor " << e.first << " on Floor " << i << std::endl;
                e.second->checkSensor();
                cancelAlarm();
            } catch (FireDetectedException& fire) {
                innerSirens[i]->switchOn();
                outerSiren->switchOn();
            } catch (ErrorDetectedException& error) {
                std::cout << "Error on Floor " << i << " detectet. Please Check Sensor!" << std::endl;
            }

        }

        sleep(1);
    }

}

//Schaltet alle Sirenen wieder aus.
void Building::cancelAlarm() {
    for (auto& siren : innerSirens) {
        siren->switchOff();
    }
    outerSiren->switchOff();
}



