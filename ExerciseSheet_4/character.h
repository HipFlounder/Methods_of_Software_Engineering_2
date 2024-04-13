
#ifndef EXERCISESHEET_3_CHARACTER_H
#define EXERCISESHEET_3_CHARACTER_H

#include "item.h"
#include "exceptions.h"

#include <string>

class Character {

protected:
    std::string name;
    int health;
    int gold;
    Item* inventory[10]; //Array von Pointern
    int armor;
    int magicResistance;

public:
    //Konstruktor
    Character(const std::string& name, int health, int gold, int armor, int magicResistance) : name(name), health(health), gold(gold), armor(armor), magicResistance(magicResistance) {
        if (name.size() == 0) {
            throw InvalidArgument("Character: Leerer Name!");
        }
        if (health < 0) {
            throw InvalidArgument("Hero: Negative Lebenspunkte!");
        }
        if (gold < 0) {
            throw InvalidArgument("Character: Negativer Wert!");
        }
        //Initialisierung Invenatr mit Nullpointern
        for (int i = 0; i < 10; ++i) {
            inventory[i] = nullptr;
        }
    }

    virtual ~Character() {
        for (int i = 0; i < 10; ++i) {
            if (inventory[i] != nullptr) {
                delete inventory[i];
                inventory[i] = nullptr;
            }
        }
    }

    virtual void attack(Character& enemy) = 0;

    int addInventarItem(Item* item);

    Item* removeInventarItem(int slot);

    Item* retrieveRandomLoot(Character& enemy);

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
    Item* getInventory(int index) const {
        if (index < 0 || index > 10) {
            throw InvalidIndexException("getInventory(): Ungültiger Index!");
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
        if (name.size() == 0) {
            throw InvalidArgument("setName(): Leerer Name!");
        }
        this->name = name;
    }
    void setHealth(int health) {
        this->health = health;
    }
    void setGold(int gold) {
        if (gold < 0) {
            throw InvalidArgument("setGold(): Negativer Wert!");
        }
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
