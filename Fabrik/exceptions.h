
#ifndef FABRIK_EXCEPTIONS_H
#define FABRIK_EXCEPTIONS_H

#include <stdexcept>

class FactoryException : public std::runtime_error {
public:
    using std::runtime_error::runtime_error;
};

class InvalidArgument : public FactoryException  {
public:
    InvalidArgument() : FactoryException("Invalid value.") {}
    //explicit  InvalidArgument(const std::string &msg = "Invalid value") : FactoryException(msg) {}
};

class MachineFailureException : public FactoryException {
public:
    MachineFailureException() : FactoryException("MachineFailure") {}
};

class MachineExplosionException : public FactoryException {
public:
    MachineExplosionException() : FactoryException("MachineExplosion") {}
};

#endif //FABRIK_EXCEPTIONS_H
