
#ifndef BRANDMELDEANLAGE_SENSOR_H
#define BRANDMELDEANLAGE_SENSOR_H

#include <iostream>

class Sensor {

public:
    //Default Konstruktor und Destruktor
    Sensor() = default;
    virtual ~Sensor() = default;

    virtual void checkSensor() = 0;

    virtual int getType() const = 0;

};


class SmokeDetector : public Sensor {

public:

    virtual ~SmokeDetector() {
        std::cout << "Destructor Smoke Detector" << std::endl;
    }

    void checkSensor() override;

    int getType() const override;

};


class InfraredSensor : public Sensor {

public:

    virtual ~InfraredSensor() {
        std::cout << "Destructor Infrared Sensor" << std::endl;
    }

    void checkSensor() override;

    int getType() const override;

};


#endif //BRANDMELDEANLAGE_SENSOR_H
