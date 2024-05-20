
#ifndef EXERCISESHEET_6_MOTOR_H
#define EXERCISESHEET_6_MOTOR_H

#include "exceptions.h"

#include <iostream>

class Motor {

private:
    int speed = 0;

public:
    //Default Konstruktor
    Motor() = default;

    //Desturktor
    ~Motor() {
        std::cout << "Destruktor Motor" << std::endl;
    }

    void setSpeed(int speed) {
        if (speed < 0 || speed > 10) {
            this->speed = 0;
            throw InvalidArgument("setSpeed(): Ungültiger Wert!");
        }
        this->speed = speed;
    }

    int getSpeed() const {
        return speed;
    }

    void emergencyBrake();

};

#endif //EXERCISESHEET_6_MOTOR_H
