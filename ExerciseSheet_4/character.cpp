
#include <iostream>

#include "character.h"
#include "exceptions.h"

//Übergebener Gegenstand wird zum Inventar hinzugefügt
int Character::addInventarItem(Item* item) {
    for (int i = 0; i < 10; i++) {
        if(inventory[i] == nullptr) {
            inventory[i] = item;
            return i; //Rückgabe Index
        }
    }
    throw FullInventoryException("addInventarItem(): Inventar voll!");
}

//Entsprechender Gegenstand wird entfernt
Item* Character::removeInventarItem(int slot) {
    if (slot < 0 || slot > 9) {
        throw InvalidIndexException("removeInventarItem(): Ungültiger Index!");
    } else if (inventory[slot] != nullptr) {
        Item* retval = inventory[slot];
        inventory[slot] = nullptr;
        return retval;
    } else {
        return nullptr;
    }
}

/*Item* Character::retrieveRandomLoot(Character& enemy) {
    for (int i = 0; i < 10; i++) {
        int rand = std::rand() % 10;
        Item* item = enemy.removeInventarItem(rand);
        if (item != nullptr) {
            if (addInventarItem(item) == -1) {
                throw FullInventoryException("addInventarItem(): Inventar voll!");
            } else {
                std::cout << "Gegenstand " << *item << " wurde zum Inventar der Heldin hinzugefuegt." << std::endl;
                return item;
            }
        }
    }
    std::cout << enemy << " hat keinen braucharen Gegenstand im Inventar." << std::endl;
    return nullptr;
}*/

//Operator << überladen
std::ostream& operator<<(std::ostream& out, const Character& character) {
    out << character.getName();
    return out;
}