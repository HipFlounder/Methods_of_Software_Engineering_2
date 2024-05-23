
#ifndef BRANDMELDEANLAGE_EXCEPTIONS_H
#define BRANDMELDEANLAGE_EXCEPTIONS_H

#include <stdexcept>

class FireAlarmException : public std::runtime_error {
public:
    using std::runtime_error::runtime_error;
};

class InvalidArgument : public FireAlarmException  {
public:
    InvalidArgument() : FireAlarmException("Invalid value!") {}
};

//Feuer detektiert
class FireDetectedException : public FireAlarmException {
public:
    FireDetectedException() : FireAlarmException("Fire detected!") {}
};

//Fehler detektiert
class ErrorDetectedException : public FireAlarmException {
public:
    ErrorDetectedException() : FireAlarmException("Error detected!") {}
};

#endif //BRANDMELDEANLAGE_EXCEPTIONS_H
