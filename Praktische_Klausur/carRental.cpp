
#include "carRental.h"
#include "car.h"
#include "exceptions.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

CarRental::CarRental() : nextCarId(0) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

CarRental::~CarRental() {
    for (auto& e : cars) {
        std::cout << "Lösche Element: " << e.first << std::endl;
        delete e.second;
    }

    cars.clear();
    std::cout << "Destructor CarRental" << std::endl;

}

int CarRental::addCar(Car* sensor) {

    if (sensor) {
        int id = nextCarId++;
        std::cout << "Adding Car with id " << id << std::endl;
        cars[id] = sensor;
        return id;
    } else {
        throw InvalidArgument();
    }

}

Car* CarRental::getCar(int id) {

    try {
        std::cout << "Getting Car with id " << id << std::endl;
        return cars.at(id);
    } catch (std::out_of_range& e) {    //falls Car an ID nicht gefunden wird, wird eine out_of_range Exception geworfen
        std::cout << "Car with id " << id << " does not exist. " << std::endl;
        throw InvalidArgument();
    }

}

void CarRental::deleteCar(int id) {

    if (cars.find(id) == cars.end()) {
        std::cout << "Car with id " << id << " does not exist. " << std::endl;
        throw InvalidArgument();
    } else {
        std::cout << "Deleting Car with id " << id << std::endl;
        delete cars[id];
        cars.erase(id);
    }

}

Car* CarRental::rentCar(int licenceType, int passengerCount) {

    Car* bestCar = nullptr;
    int minRemainingSeats = 20;
    std::vector<int> carsToRemove;

    for (auto& e : cars) {

        try {

            if (e.second->checkCar() && e.second->getRequiredDrivingLicence() <= licenceType) {
                int passenger = e.second->getPassengerCount();

                if (passenger >= passengerCount) {
                    int remainingSeats = passenger - passengerCount;
                    if (remainingSeats < minRemainingSeats && e.second->getIsRented() == false) {
                        bestCar = e.second;
                        minRemainingSeats = remainingSeats;
                        e.second->setRented(true);
                    } else if (e.second->getIsRented() == true) {
                        std::cout << "Car is already rented!" << std::endl;
                        continue;
                    }
                }
            }

        } catch (BrokenMotorException& ex) {

            std::cout << "BrokenMotor: Removing Car " << e.first << std::endl;
            carsToRemove.push_back(e.first);
            //deleteCar(e.first);

        } catch (ElectronicsFaultException& ex) {

            std::cout << "ElecctronicsFault: Removing Car " << e.first << std::endl;
            carsToRemove.push_back(e.first);
            //deleteCar(e.first);

        } catch (EmissionsTooDirtyException& ex) {
            std::cout << "EmissionsTooDirty: Check Car " << e.first << std::endl;
        }

    }

    if (!bestCar) {
        throw NoCarFoundException();
    }

    for (auto id : carsToRemove) {
        deleteCar(id);
    }

    return bestCar;

}

void CarRental::simulate(int rentals) {
    //std::srand(time(0));
    for (int i = 0; i < rentals; i++) {
        //Zufallszahl zwischen 1-5
        int licenceType = std::rand() % 5 + 1;
        //Zuffalszahl zwischen 1-20
        int passengerCount = std::rand() % 20 + 1;
        try {
            std::cout << "Trying to rent a Car with " << passengerCount << " seats and licence type " << licenceType << std::endl;
            Car* rentedCar = rentCar(licenceType, passengerCount);
            std::cout << "Rental #" << i + 1 << ": Car with " << rentedCar->getPassengerCount()
            << " passenger seats " << "and licence type " << rentedCar->getRequiredDrivingLicence() << std::endl;
        } catch (const NoCarFoundException& e) {
            std::cout << "Rental #" << i + 1 << ": No suitable car found" << std::endl;
        }
    }
}