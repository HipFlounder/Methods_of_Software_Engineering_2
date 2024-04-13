
#ifndef EXERCISESHEET_3_HERO_H
#define EXERCISESHEET_3_HERO_H

#include "item.h"
#include "character.h"
#include "exceptions.h"
#include "npc.h"

#include <iostream>
#include <string>

class Hero : public Character {

protected:
    Item* gear[2]; //Array von Pointern

public:
    //Konstruktoren
    Hero(const std::string& name, int health, int gold, int armor, int magicResistance) : Character(name, health, gold, armor, magicResistance) {
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

    //Dekunstruktor
    virtual ~Hero() {
        for (int i = 0; i < 2; ++i) {
            if (gear[i] != nullptr) {
                delete gear[i];
                gear[i] = nullptr;
            }
        }
        std::cout << "Heldin " << getName() << " sagt: Auf Wiedersehen!" << std::endl;
    }

   void attack(Character& enemy) override;

    void sellItem(int index);

    bool fight(Npc& enemy);

    int addEquipmentItem(Item* item);

    Item* removeEquipmentItem(int slot);

    //Getter
    Item* getGear(int index) const{
        if (index < 0 || index > 1) {
            throw InvalidIndexException("getGear(): Ungültiger Index!");
        }
        return gear[index];
    }

};

#endif //EXERCISESHEET_3_HERO_H
