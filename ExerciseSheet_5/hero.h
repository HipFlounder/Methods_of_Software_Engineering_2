
#ifndef EXERCISESHEET_3_HERO_H
#define EXERCISESHEET_3_HERO_H

#include "character.h"
#include "exceptions.h"

#include <iostream>
#include <string>

//forward declaration
class Item;
class Npc;

class Hero : public Character {

protected:
    std::shared_ptr<Item> gear[2]; //Array von Shared_ptr

public:
    //Konstruktoren
    Hero(const std::string& name, int health, int gold, int armor, int magicResistance, Game* game) : Character(name, health, gold, armor, magicResistance, game) {
        if (name.size() == 0) {
            throw InvalidArgument("Hero: Leerer Name!");
        }
        if (health < 0) {
            throw InvalidArgument("Hero: Negative Lebenspunkte!");
        }
        if (gold < 0) {
            throw InvalidArgument("Hero: Negativer Wert!");
        }
        //Initialisierung Invenatr mit Nullpointern
        for (int i = 0; i < 2; ++i) {
            gear[i] = nullptr;
        }
    }

    //Destruktor
    virtual ~Hero() {
        std::cout << "Held " << getName() << " sagt: Auf Wiedersehen!" << std::endl;
    }

   void attack(Character& enemy) override;

    void sellItem(int index);

    bool fight(Npc& enemy);

    int addEquipmentItem(std::shared_ptr<Item> item);

    std::shared_ptr<Item> removeEquipmentItem(int slot);

    //Getter
    std::shared_ptr<Item> getGear(int index) const{
        if (index < 0 || index > 1) {
            throw InvalidIndexException("getGear(): Ungültiger Index!");
        }
        return gear[index];
    }
    int getInventorySize() const {
        return inventory.size();
    }

};

#endif //EXERCISESHEET_3_HERO_H
