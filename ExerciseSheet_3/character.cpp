
#include <iostream>
#include "character.h"
#include "hero.h"

//Übergebener Gegenstand wird zum Inventar hinzugefügt
int Character::addInventarItem(const Item& item) {
    for (int i = 0; i < 10; i++) {
        if(inventory[i].getIsValid() == false) {
            inventory[i] = item;
            return i; //Rückgabe Index
        }
    }

    return -1;
}

//Entsprechender Gegenstand wird entfernt
Item Character::removeInventarItem(int slot) {
    if(slot >= 0 && slot < 10 && inventory[slot].getIsValid()) {
        Item retval = inventory[slot];
        inventory[slot].setIsValid(false);
        return retval;
    } else {
        Item item;
        return item;
    }
}

Item Character::retrieveRandomLoot(Character& enemy) {
    for (int i = 0; i < 10; i++) {
        int rand = std::rand() % 10;
        Item item = enemy.removeInventarItem(rand);
        if (item.getIsValid()) {
            if (addInventarItem(item) == -1) {
                std::cout << "Kein Platz mehr vorhanden!" << std::endl;
            } else {
                std::cout << "Gegenstand " << item << " wurde zum Inventar der Heldin hinzugefuegt." << std::endl;
                return item;
            }
        }
    }
    std::cout << enemy << " hat keinen braucharen Gegenstand im Inventar." << std::endl;
    Item item;
    return item;
}

//Operator << überladen
std::ostream& operator<<(std::ostream& out, const Character& character) {
    out << character.getName();
    return out;
}