
#include <iostream>
#include <cstdlib> // für rand()
#include "hero.h"
#include "character.h"

//Initialisierung des Helden
void Hero::initHero(const std::string& name, int health, int gold) {
    setName(name);
    setHealth(health);
    setGold(gold);

    for (int i = 0; i < 10; i++) {
        inventory[i].initItem();
    }
    gear[0].initItem();
    gear[1].initItem();
}

//Held greift Gegner an
void Hero::attack(Character* enemy) {
   //Random Schaden zwicshen 15 und 25
    int damage = 15 + (std::rand() % 11);
    std::cout << this->name << " trifft " << enemy->getName() << " für " << damage << " Lebenspunkte!" << std::endl;
    enemy->setHealth(enemy->getHealth() - damage);
}

//Gegenstand verkaufen
void Hero::sellItem(int index) {
    if (index >= 0 && index < 10) {
        if (inventory[index].getIsValid()) {
            gold += inventory[index].getGold();
            inventory[index].setIsValid(false);
            std::cout << "Gegenstand " << inventory[index].getName() << " wurde verkauft. " << name << " besitzt nun " << getGold() << " Gold." << std::endl;
        }
    }
}

//Kampf zwischen Held und Gegner
bool Hero::fight(Character* enemy) {
    while (getHealth() > 0 && enemy->getHealth() > 0) {
        attack(enemy);

        if (enemy->getHealth() <= 0) {
            std::cout << enemy->getName() << " fiel in Ohnmacht! " << getName() << " hat noch " << getHealth() << " Lebenspunkte uebrig!" << std::endl;
            while (true) {
                int rand = std::rand() % 10;
                Item item = enemy->removeInventarItem(rand);
                if (item.getIsValid()) {
                    if (this->addInventarItem(item) == -1) {
                        std::cout << "Kein Platz mehr vorhanden!" << std::endl;
                    } else {
                        std::cout << "Gegenstand " << item.getName() << " wurde zum Inventar der Heldin hinzugefuegt." << std::endl;
                    }
                    break;
                }
            }
            return true; //Held gewinnt Kampf
        }

        enemy->attack(this);
        if (health <= 0) {
            std::cout << name << " fiel in Ohnmacht! " << enemy->getName() << " hat noch " << enemy->getHealth() << " Lebenspunkte uebrig!" << std::endl;
            return false; //Gegner gewinnt Kampf
        }
    }
    return false;
}

//Übergebener Gegenstand wird zum Inventar hinzugefügt
int Hero::addInventarItem(const Item& item) {
    for (int i = 0; i < 10; i++) {
        if(inventory[i].getIsValid() == false) {
            inventory[i] = item;
            return i; //Rückgabe Index
        }
    }

    return -1; //Wenn alle Plätze belegt
}

//Übergebener Gegenstand wird zur Ausrüstung hinzugefügt
int Hero::addEquipmentItem(const Item& item) {
    for (int i = 0; i < 2; i++) {
        if(gear[i].getIsValid() == false) {
            gear[i] = item;
            return i; //Rückgabe Index
        }
    }

    return -1; //Wenn alle Plätze belegt
}

//Entsprechender Gegenstand wird entfernt
Item Hero::removeInventarItem(int slot) {
    if(slot >= 0 && slot < 10 && inventory[slot].getIsValid()) {
        Item retval = inventory[slot];
        inventory[slot].setIsValid(false);
        return retval; //Rückgabe Element
    } else {
        Item item;
        item.initItem();
        return item;
    }
}

//Entsprechender Gegenstand wird entfernt
Item Hero::removeEquipmentItem(int slot) {
    if(slot >= 0 && slot < 2 && gear[slot].getIsValid()) {
        Item retval = gear[slot];
        gear[slot].setIsValid(false);
        return retval; //Rückgabe Element
    } else {
        Item item;
        item.initItem();
        return item;
    }
}


