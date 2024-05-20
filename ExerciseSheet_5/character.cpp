
#include <iostream>
#include <vector>

#include "character.h"
#include "exceptions.h"

//Übergebener Gegenstand wird zum Inventar hinzugefügt
int Character::addInventarItem(std::shared_ptr<Item> item) {
    inventory.push_back(item);
    return inventory.size() -1; //Rückgabe Index
}

//Entsprechender Gegenstand wird entfernt
std::shared_ptr<Item> Character::removeInventarItem(int slot) {
    if (slot < 0 || slot >= (int)inventory.size()) {
        throw InvalidIndexException("removeInventarItem(): Ungültiger Index!");
    }
    std::shared_ptr<Item> removedItem = inventory[slot]; //Zeiger auf das entfernte Element
    inventory.erase(inventory.begin() + slot); //Element an der angegebenen Stelle entfernen
    return removedItem;
}

//Operator << überladen
std::ostream& operator<<(std::ostream& out, const Character& character) {
    out << character.getName();
    return out;
}