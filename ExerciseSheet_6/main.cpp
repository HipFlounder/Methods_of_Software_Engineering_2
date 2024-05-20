
#include "robot.h"
#include "ultrasonic.h"
#include "laser.h"
#include "camera.h"

#include <ctime>
#include <iostream>
#include <cstdlib>

int main() {

    //Evtl. zu Beginn ohne srand um Fehler reproduzierbar zu machen
    srand(time(0));

    Robot robot;
    robot.addSensor(new Ultrasonic());
    robot.addSensor(new Laser());
    robot.addSensor(new Camera());

    try {
        robot.eventLoop();
    } catch (const std::exception& e) {
        std::cout << "Exception in Main: " << e.what() << std::endl;
    }

    /*
    //Bereits im Destruktor von Robot
    robot.deleteSensor(1);
    robot.deleteSensor(2);
    robot.deleteSensor(3);
    */

    return 0;
}