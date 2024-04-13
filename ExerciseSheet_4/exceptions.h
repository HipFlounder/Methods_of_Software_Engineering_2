
#ifndef EXERCISESHEET_4_EXCEPTIONS_H
#define EXERCISESHEET_4_EXCEPTIONS_H

#include <exception>
#include <iostream>

class GameError : public std::runtime_error {
public:
    using std::runtime_error::runtime_error;
};

class InvalidIndexException : public GameError {
public:
    using GameError::GameError;
};

class FullInventoryException : public GameError {
public:
    using GameError::GameError;
};

class FullGearException : public GameError {
public:
    using GameError::GameError;
};

class InvalidArgument : public GameError {
public:
    using GameError::GameError;
};

#endif //EXERCISESHEET_4_EXCEPTIONS_H
