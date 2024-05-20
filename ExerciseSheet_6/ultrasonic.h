
#ifndef EXERCISESHEET_6_ULTRASONIC_H
#define EXERCISESHEET_6_ULTRASONIC_H

#include "sensor.h"

class Ultrasonic : public Sensor {

public:

    ~Ultrasonic() override;

    int checkSensor() override;

    void reset() override;

};

#endif //EXERCISESHEET_6_ULTRASONIC_H
