
#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>

class CarRentalException : public std::runtime_error {
public:
    using std::runtime_error::runtime_error;
};

class InvalidArgument : public CarRentalException  {
public:
    InvalidArgument() : CarRentalException("Invalid value.") {}
    //explicit  InvalidArgument(const std::string &msg = "Invalid value") : FactoryException(msg) {}
};

class BrokenMotorException : public CarRentalException {
public:
    BrokenMotorException() : CarRentalException("Motor Broken!") {}
};

class ElectronicsFaultException : public CarRentalException {
public:
    ElectronicsFaultException() : CarRentalException("Electronic Broken!") {}
};

class EmissionsTooDirtyException : public CarRentalException {
public:
    EmissionsTooDirtyException() : CarRentalException("Error Emissions!") {}
};

class NoCarFoundException : public CarRentalException {
public:
    NoCarFoundException() : CarRentalException("No Car Found!") {}
};


#endif //EXCEPTIONS_H
