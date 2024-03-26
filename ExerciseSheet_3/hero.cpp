
#include <iostream>
#include <cstdlib> // für rand()
#include "hero.h"
#include "character.h"

//Held greift Gegner an
void Hero::attack(Character& enemy) {
    //Random Schaden zwischen 15 und 25
    int damage = (15 + (std::rand() % 11)) - enemy.getArmor();
    std::cout << this->getName() << " trifft " << enemy << " für " << damage << " Lebenspunkte!" << std::endl;
    enemy.setHealth(enemy.getHealth() - damage);
}

//Gegenstand verkaufen
void Hero::sellItem(int index) {
    if (index >= 0 && index < 10) {
        if (inventory[index].getIsValid()) {
            setGold(gold += inventory[index].getGold());
            inventory[index].setIsValid(false);
            std::cout << "Gegenstand " << this->inventory[index].getName() << " wurde verkauft. " << this->getName() << " besitzt nun " << this->getGold() << " Gold." << std::endl;
        }
    }
}

//Kampf zwischen Held und Gegner
bool Hero::fight(Character& enemy) {
    while (this->getHealth() > 0 && enemy.getHealth() > 0) {
        attack(enemy);

        if (enemy.getHealth() <= 0) {
            std::cout << enemy << " fiel in Ohnmacht! " << this->getName() << " hat noch " << this->getHealth() << " Lebenspunkte uebrig!" << std::endl;
            retrieveRandomLoot(enemy);
            return true; //Held gewinnt Kampf
        }

        //Derefenzierungsoperator da this ein Pointer - brauchen aber Objekt deshalb *this
        enemy.attack(*this);
        if (health <= 0) {
            std::cout << this->getName() << " fiel in Ohnmacht! " << enemy << " hat noch " << enemy.getHealth() << " Lebenspunkte uebrig!" << std::endl;
            std::cout << this->getName() << " hat verloren. Spiel beendet!" << std::endl;
            return false; //Gegner gewinnt Kampf
        }
    }
    return false;
}

//Übergebener Gegenstand wird zur Ausrüstung hinzugefügt
int Hero::addEquipmentItem(const Item& item) {
    for (int i = 0; i < 10; i++) {
        if(gear[i].getIsValid() == false) {
            gear[i] = item;
            return i; //Rückgabe Index
        }
    }
    return -1; //Wenn alle Plätze belegt
}

//Entsprechender Gegenstand wird entfernt
Item Hero::removeEquipmentItem(int slot) {
    if(slot >= 0 && slot < 2 && gear[slot].getIsValid()) {
        Item retval = gear[slot];
        gear[slot].setIsValid(false);
        return retval; //Rückgabe Element
    } else {
        Item item;
        return item;
    }
}

//Dekunstruktor
Hero::~Hero() {
    std::cout << "Heldin " << getName() << " sagt: Auf Wiedersehen!" << std::endl;
}