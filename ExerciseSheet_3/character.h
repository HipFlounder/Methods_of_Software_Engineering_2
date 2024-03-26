
#ifndef EXERCISESHEET_3_CHARACTER_H
#define EXERCISESHEET_3_CHARACTER_H

#include "item.h"
#include <string>

class Character {

protected:
    std::string name;
    int health;
    int gold;
    Item inventory[10];
    int armor;
    int magicResistance;

public:
    //Konstruktor
    Character(const std::string& name, int health, int gold, int armor, int magicResistance) : name(name), health(health), gold(gold), armor(armor), magicResistance(magicResistance) {}

    virtual void attack(Character& enemy) = 0;

    int addInventarItem(const Item& item);

    Item removeInventarItem(int slot);

    Item retrieveRandomLoot(Character& enemy);

    //Getter
    const std::string& getName() const {
        return name;
    }
    int getHealth() const {
        return health;
    }
    int getGold() const {
        return gold;
    }
    Item getInventory(int index) const {
        if (index < 0 || index > 1) {
            Item item;
            return item;
        }
        return inventory[index];
    }
    int getArmor() const {
        return armor;
    }
    int getMagicResistance() const {
        return magicResistance;
    }

    //Setter
    void setName(const std::string &name) {
        this->name = name;
    }
    void setHealth(int health) {
        this->health = health;
    }
    void setGold(int gold) {
        this->gold = gold;
    }
    void setArmor(int armor) {
        this->armor = armor;
    }
    void setMagicResistance(int magicResistance) {
        this->magicResistance = magicResistance;
    }

};

std::ostream& operator<<(std::ostream& out, const Character& character);

#endif //EXERCISESHEET_3_CHARACTER_H
