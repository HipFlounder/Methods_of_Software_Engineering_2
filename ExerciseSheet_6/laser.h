
#ifndef EXERCISESHEET_6_LASER_H
#define EXERCISESHEET_6_LASER_H

#include "sensor.h"

class Laser : public Sensor {

public:

    ~Laser() override;

    int checkSensor() override;

    void reset() override;

};

#endif //EXERCISESHEET_6_LASER_H
