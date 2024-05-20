
#ifndef EXERCISESHEET_3_FIGHTER_H
#define EXERCISESHEET_3_FIGHTER_H

#include "npc.h"

class Fighter : public Npc {

protected:
    int strength;

public:
    //Konstruktor
    Fighter(const std::string& name, int health, int gold, int strength, int armor, int magicResistance, Game* game) : Npc(name, health, gold, armor, magicResistance, game), strength(strength) {}

    virtual void attack(Character& enemy) override;

    int getStrength() const {
        return strength;
    }

    void setStrength(int strength) {
        if (strength < 0) {
            throw InvalidArgument("setStrength(): Muss Positiv sein!");
        }
        this->strength = strength;
    }

    //Destruktor
    virtual ~Fighter();

};

#endif //EXERCISESHEET_3_FIGHTER_H
