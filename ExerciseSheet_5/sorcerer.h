
#ifndef EXERCISESHEET_3_SORCERER_H
#define EXERCISESHEET_3_SORCERER_H

#include "npc.h"

class Sorcerer : public Npc {

protected:
    int magicPower;

public:
    //Konstruktor
    Sorcerer(const std::string& name, int health, int gold, int magicPower, int armor, int magicResistance, Game* game) : Npc(name, health, gold, armor, magicResistance, game), magicPower(magicPower) {}

    virtual void attack(Character& enemy) override;

    int getMagicPower() const {
        return magicPower;
    }

    void setMagicPower(int magicPower) {
        if (magicPower < 0) {
            throw InvalidArgument("setMagicPower(): Muss Positiv sein!");
        }
        this->magicPower = magicPower;
    }

    //Destruktor
    virtual ~Sorcerer();

};


#endif //EXERCISESHEET_3_SORCERER_H
