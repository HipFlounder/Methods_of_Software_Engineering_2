
#ifndef EXERCISESHEET_1_CHARACTER_H
#define EXERCISESHEET_1_CHARACTER_H

#include "hero.h"

class Character {

private:
    std::string name;
    int health;
    int gold;
    Item inventory[10];

public:
    void attack(Hero* hero);
    void initCharacter(const std::string& name, int health, int gold);
    int addInventarItem(const Item& item);
    Item removeInventarItem(int slot);

    //Getter
    const std::string& getName() {
        return name;
    }
    int getHealth() {
        return health;
    }
    int getGold() {
        return gold;
    }
    Item* getInventory(int index) {
        if (index < 0 || index > 10) {
            return nullptr;
        }
        return& inventory[index];
    }

    //Setter
    //Name nach anlegen nicht mehr änderbar
    /*void setName(const std::string& name) {
        this->name = name;
    } */
    void setHealth(int health) {
        if (health < 0) {
            this->health = 0;
        }
        this->health = health;
    }
    void setGold(int gold) {
        if (gold >= 0) {
            this->gold = gold;
        }
    }

};


#endif //EXERCISESHEET_1_CHARACTER_H
