
#include <iostream>
#include <cstdlib> // für rand()
#include "character.h"
#include "hero.h"

//Gegner greift Held an
void Character::attack(Hero* hero) {
    //Random Schaden zwicshen 15 und 25
    int damage = 15 + (std::rand() % 11);
    std::cout << name << " trifft " << hero->getName() << " für " << damage << " Lebenspunkte!" << std::endl;
    hero->setHealth(hero->getHealth() - damage);
}

//Initialisierung des Gegners
void Character::initCharacter(const std::string& name, int health, int gold) {
    this->name = name;
    this->health = health;
    this->gold = gold;
    for (int i = 0; i < 10; i++) {
        inventory[i].initItem();
    }
}

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
        item.initItem();
        return item;
    }
}