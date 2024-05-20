
#include <iostream>
#include <cstdlib> // für rand()

#include "hero.h"
#include "character.h"
#include "exceptions.h"
#include "game.h"
#include "npc.h"

//Held greift Gegner an
void Hero::attack(Character& enemy) {
    //Random Schaden zwischen 15 und 25
    int damage = (15 + (std::rand() % 11)) - enemy.getArmor();
    std::cout << this->getName() << " trifft " << enemy << " für " << damage << " Lebenspunkte!" << std::endl;
    enemy.setHealth(enemy.getHealth() - damage);
}

//Gegenstand verkaufen
void Hero::sellItem(int index) {
    if (index >= 0 && index < (int)inventory.size()) {
        std::shared_ptr<Item> item = inventory[index];
        if(item != nullptr) {
            setGold(gold += inventory[index]->getGold());
            game->addItem(inventory[index]);
            removeInventarItem(index);
            std::cout << "Gegenstand " << this->inventory[index]->getName() << " wurde verkauft. " << this->getName() << " besitzt nun " << this->getGold() << " Gold." << std::endl;
        } else {
            throw InvalidIndexException("sellItem(): Ungültiger Index!");
        }
    } else {
        throw InvalidIndexException("sellItem(): Ungültiger Index!");
    }
}

//Kampf zwischen Held und Gegner
bool Hero::fight(Npc& enemy) {
    while (this->getHealth() > 0 && enemy.getHealth() > 0) {
        attack(enemy);

        //Return true if hero wins, else return false
        if (enemy.getHealth() <= 0) {
            std::cout << enemy << " fiel in Ohnmacht! " << this->getName() << " hat noch " << this->getHealth() << " Lebenspunkte uebrig!" << std::endl;
            std::shared_ptr<Item> loot = enemy.retrieveRandomLoot();
            if (loot != nullptr) {
                addInventarItem(loot);
                std::cout << "Gegenstand " << loot->getName() << " wurde zum Inventar des Helden hinzugefuegt." << std::endl;
            } else {
                std::cout << enemy << " hat keinen braucharen Gegenstand im Inventar." << std::endl;
            }
            game->removeCharacter(enemy.getName());
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
int Hero::addEquipmentItem(std::shared_ptr<Item> item) {
    for (int i = 0; i < 2; i++) {
        if(gear[i] == nullptr) {
            gear[i] = item;
            return i; //Rückgabe Index
        }
    }
    throw FullInventoryException("addEquipmentItem(): Inventar voll!");
}

//Entsprechender Gegenstand wird entfernt
std::shared_ptr<Item> Hero::removeEquipmentItem(int slot) {
    if(slot >= 0 && slot < 2 && gear[slot] != nullptr) {
        std::shared_ptr<Item> retval = gear[slot];
        gear[slot] = nullptr; //Setze den Pointer auf Null
        return retval; //Rückgabe Element
    } else {
        throw InvalidIndexException("removeEquipmentItem(): Ungügliter Index!");
    }
}