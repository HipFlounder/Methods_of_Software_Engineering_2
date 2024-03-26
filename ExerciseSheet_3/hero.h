
#ifndef EXERCISESHEET_3_HERO_H
#define EXERCISESHEET_3_HERO_H

#include "item.h"
#include "character.h"
#include <string>

class Hero : public Character {

protected:
    Item gear[2];

public:
    //Konstruktoren
    Hero(const std::string& name, int health, int gold, int armor, int magicResistance) : Character(name, health, gold, armor, magicResistance) {}

   void attack(Character& enemy) override;

    void sellItem(int index);

    bool fight(Character& enemy);

    int addEquipmentItem(const Item& item);

    Item removeEquipmentItem(int slot);

    //Getter
    Item getGear(int index) const{
        if (index < 0 || index > 1) {
            Item item;
            return item;
        }
        return gear[index];
    }

    //Dekunstruktor
    virtual ~Hero();

};

#endif //EXERCISESHEET_3_HERO_H
