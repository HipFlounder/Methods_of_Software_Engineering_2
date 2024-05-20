
#ifndef EXERCISESHEET_3_CHARACTER_H
#define EXERCISESHEET_3_CHARACTER_H

#include "item.h"
#include "exceptions.h"

#include <string>
#include <vector>
#include <memory>

//forward declaration
class Game;
class Item;

class Character {

protected:
    std::string name;
    int health;
    int gold;
    std::vector<std::shared_ptr<Item>> inventory;       //Vector
    //std::map<int, Item*> inventory;     //Map
    int armor;
    int magicResistance;
    Game* game = nullptr;

public:
    //Konstruktor
    Character(const std::string& name, int health, int gold, int armor, int magicResistance, Game* game) : name(name), health(health < 0 ? 0 : health), gold(gold), armor(armor), magicResistance(magicResistance), game(game) {
        if (name.size() == 0) {
            throw InvalidArgument("Character: Leerer Name!");
        }
        if (health < 0) {
            throw InvalidArgument("Character: Negative Lebenspunkte!");
        }
        if (gold < 0) {
            throw InvalidArgument("Character: Negativer Wert!");
        }
    }

    //Destruktor
    virtual ~Character() {
        std::cout << "Zerstöre Character " << name << std::endl;
        inventory.clear(); //Clear all Items
    }

    virtual void attack(Character& enemy) = 0;

    int addInventarItem(std::shared_ptr<Item> item);

    std::shared_ptr<Item> removeInventarItem(int slot);

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
    std::shared_ptr<Item> getInventory(int index) const {
        if (index < 0 || index >= (int)inventory.size()) {
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
        } else {
            this->gold = gold;
        }
    }
    void setArmor(int armor) {
        if (armor < 0) {
            throw InvalidArgument("setArmor(): Negativer Wert!");
        } else {
            this->armor = armor;
        }
    }
    void setMagicResistance(int magicResistance) {
        if (magicResistance < 0) {
            throw InvalidArgument("setArmor(): Negativer Wert!");
        } else {
            this->magicResistance = magicResistance;
        }
    }

};

std::ostream& operator<<(std::ostream& out, const Character& character);

#endif //EXERCISESHEET_3_CHARACTER_H
