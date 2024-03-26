
#ifndef EXERCISESHEET_1_HERO_H
#define EXERCISESHEET_1_HERO_H

#include <string>
#include "item.h"

struct Character_t;

struct Hero_t {
    std::string name;
    int health;
    int gold;
    Item_t inventory[10];
    Item_t gear[2];
};

void initHero(Hero_t* hero, char* name, int health, int gold);

void attack(Hero_t* hero, Character_t* enemy);

void sellItem(Hero_t* hero, int index);

bool fight(Hero_t* hero, Character_t* enemy);

#endif //EXERCISESHEET_1_HERO_H
