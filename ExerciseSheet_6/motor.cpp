
#include "motor.h"

#include <iostream>

void Motor::emergencyBrake() {
    std::cout << "Emergency brake!" << std::endl;
    setSpeed(0);
}
