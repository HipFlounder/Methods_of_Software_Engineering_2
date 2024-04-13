
#ifndef EXERCISESHEET_3_FIGHTER_H
#define EXERCISESHEET_3_FIGHTER_H

#include "npc.h"

class Fighter : public Npc {

protected:
    int strength;

public:
    //Konstruktor
    Fighter(const std::string& name, int health, int gold, int strength, int armor, int magicResistance) : Npc(name, health, gold, armor, magicResistance), strength(strength) {}

    virtual void attack(Character& enemy) override;

    int getStrength() const {
        return strength;
    }

    void setStrength(int strength) {
        this->strength = strength;
    }

    //Destruktor
    virtual ~Fighter();

};

#endif //EXERCISESHEET_3_FIGHTER_H
