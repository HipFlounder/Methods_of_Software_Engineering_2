
#ifndef EXERCISESHEET_1_CHARACTER_H
#define EXERCISESHEET_1_CHARACTER_H

#include "hero.h"

struct Character_t {
    std::string name;
    int health;
    int gold;
    Item_t inventory[10];
};

void attack(Character_t* character, Hero_t* hero);

void initCharacter(Character_t* character, char* name, int health, int gold);

#endif //EXERCISESHEET_1_CHARACTER_H
