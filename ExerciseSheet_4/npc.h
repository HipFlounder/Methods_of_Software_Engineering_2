
#ifndef EXERCISESHEET_3_NPC_H
#define EXERCISESHEET_3_NPC_H

#include "character.h"

class Npc : public Character {

public:
    //Konstruktor - ertbt alle Konstruktoren von Character
    using Character::Character;

    Item* retrieveRandomLoot();
};

#endif //EXERCISESHEET_3_NPC_H
