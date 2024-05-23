
#ifndef CAR_H
#define CAR_H

#include <iostream>

class Car {

protected:
    bool isRented = false;

public:

    //virtual ~Car() {}
    virtual ~Car() = default;

    virtual bool checkCar() = 0;

    virtual int getRequiredDrivingLicence() = 0;

    virtual int getPassengerCount() = 0;

    virtual bool getIsRented() = 0;

    virtual void setRented(bool isRented) = 0;

};


class VWBus : public Car {

protected:
    bool isRented = false;

public:

    virtual ~VWBus() {
        std::cout << "Destructor VWBUS" << std::endl;
    }

    bool checkCar() override;

    int getRequiredDrivingLicence() override {
        return 2;
    }

    int getPassengerCount() override {
        return 8;
    }

    bool getIsRented() override {
        return isRented;
    }

    void setRented(bool isRented) override {
        this->isRented = isRented;
    }

};


class FordFocus : public Car {

protected:
    bool isRented = false;

public:

    virtual ~FordFocus() {
        std::cout << "Destructor FordFocus" << std::endl;
    }

    bool checkCar() override;

    int getRequiredDrivingLicence() override {
        return 1;
    }

    int getPassengerCount() override {
        return 4;
    }

    bool getIsRented() override {
        return isRented;
    }

    void setRented(bool isRented) override {
        this->isRented = isRented;
    }

};


class FerrariF40 : public Car {

protected:
    bool isRented = false;

public:

    virtual ~FerrariF40() {
        std::cout << "Destructor FerrariF40" << std::endl;
    }

    bool checkCar() override;

    int getRequiredDrivingLicence() override {
        return 3;
    }

    int getPassengerCount() override {
        return 1;
    }

    bool getIsRented() override {
        return isRented;
    }

    void setRented(bool isRented) override {
        this->isRented = isRented;
    }

};


class Kleinbus : public Car {

protected:
    bool isRented = false;

public:

    virtual ~Kleinbus() {
        std::cout << "Destructor Kleinbus" << std::endl;
    }

    bool checkCar() override;

    int getRequiredDrivingLicence() override {
        return 4;
    }

    int getPassengerCount() override {
        return 20;
    }

    bool getIsRented() override {
        return isRented;
    }

    void setRented(bool isRented) override {
        this->isRented = isRented;
    }

};

#endif //CAR_H
