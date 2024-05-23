
#include <iostream>

#include "carRental.h"
#include "car.h"

int main() {

    CarRental rental;

    rental.addCar(new VWBus());
    rental.addCar(new FordFocus());
    rental.addCar(new FerrariF40());
    rental.addCar(new Kleinbus());

    rental.simulate(10);

    std::cout << "finish" << std::endl;

    return 0;

}
