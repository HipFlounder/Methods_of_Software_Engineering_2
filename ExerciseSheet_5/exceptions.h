
#ifndef EXERCISESHEET_4_EXCEPTIONS_H
#define EXERCISESHEET_4_EXCEPTIONS_H

#include <stdexcept>

//Basisklasse Game
class GameError : public std::runtime_error {
public:
    using std::runtime_error::runtime_error;
};

//Ungültiger Wert
class InvalidArgument : public GameError {
public:
    //InvalidArgument() : GameError("Invalid value.") {}
    explicit  InvalidArgument(const std::string &msg = "Invalid value")
            : GameError(msg) {}
};

//Basisklasse Inventory
class InventoryException: public GameError {
public:
    using GameError::GameError;
};

//Exception Iventar voll
class FullInventoryException : public InventoryException {
public:
    //FullInventoryException() : InventoryException("Inventory full.") {}
    explicit  FullInventoryException(const std::string &msg = "Inventory full")
            : InventoryException(msg) {}
};

//Ungültiger Index
class InvalidIndexException : public InventoryException {
public:
    //InvalidIndexException() : InventoryException("Invalid index.") {}
    explicit  InvalidIndexException(const std::string &msg = "Invalid index")
            : InventoryException(msg) {}
};

#endif //EXERCISESHEET_4_EXCEPTIONS_H
