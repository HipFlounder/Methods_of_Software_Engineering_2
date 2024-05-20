
#ifndef EXERCISESHEET_6_CAMERA_H
#define EXERCISESHEET_6_CAMERA_H

#include "sensor.h"

class Camera : public Sensor {

public:

    ~Camera() override;

    int checkSensor() override;

    void reset() override;

};

#endif //EXERCISESHEET_6_CAMERA_H
