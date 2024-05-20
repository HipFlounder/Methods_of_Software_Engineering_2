
#ifndef EXERCISESHEET_6_EXCEPTIONS_H
#define EXERCISESHEET_6_EXCEPTIONS_H

#include <stdexcept>

class RobotException : public std::runtime_error {
public:
    using std::runtime_error::runtime_error;
};

class InvalidArgument : public RobotException  {
public:
    //InvalidArgument() : RobotException("Invalid value.") {}
    explicit  InvalidArgument(const std::string &msg = "Invalid value")
            : RobotException(msg) {}
};

class CriticalDangerException : public RobotException {
public:
    CriticalDangerException() : RobotException("CriticalDangerException: Notstopp!") {}
    //using RobotException::RobotException;
};

class InternalErrorException : public RobotException {
public:
    InternalErrorException() : RobotException("InternalErrorException: Geschwindigkeitsreduktion!") {}
};

#endif //EXERCISESHEET_6_EXCEPTIONS_H
