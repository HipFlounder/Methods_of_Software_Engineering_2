
#ifndef CARRENTAL_H
#define CARRENTAL_H

#include <map>
#include <iostream>

//forward declaration
class Car;

class CarRental {

protected:
    std::map<int, Car*> cars;
    int nextCarId = 0;

public:

    CarRental();

    virtual ~CarRental();

    int addCar(Car* sensor);

    Car* getCar(int id);

    void deleteCar(int id);

    Car* rentCar(int licenceType, int passengerCount);

    void simulate(int rentals);

};

#endif //CARRENTAL_H
