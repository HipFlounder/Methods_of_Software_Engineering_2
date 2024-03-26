
#ifndef EXERCISESHEET_1_HERO_H
#define EXERCISESHEET_1_HERO_H

#include <string>
#include "item.h"

class Character;

class Hero {

private:
    std::string name;
    int health;
    int gold;
    Item inventory[10];
    Item gear[2];

public:
    void initHero(const std::string& name, int health, int gold);
    void attack(Character* enemy);
    void sellItem(int index);
    bool fight(Character* enemy);
    int addInventarItem(const Item& item);
    int addEquipmentItem(const Item& item);
    Item removeInventarItem(int slot);
    Item removeEquipmentItem(int slot);

    //Getter
    const std::string& getName() {
        return name;
    }
    int getHealth() const{
        return health;
    }
    int getGold() const{
        return gold;
    }
    Item getInventory(int index) const{
        if (index < 0 || index > 9) {
            Item item;
            item.initItem();
            return item;
        }
        return inventory[index];
    }
    Item getGear(int index) const{
        if (index < 0 || index > 1) {
            Item item;
            item.initItem();
            return item;
        }
        return gear[index];
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

};


#endif //EXERCISESHEET_1_HERO_H
