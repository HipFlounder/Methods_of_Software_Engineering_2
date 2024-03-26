
#include <iostream>
#include <cstdlib> // für rand()
#include "character.h"
#include "hero.h"

//Gegner greift Held an
void attack(Character_t* character, Hero_t* hero) {
    //Random Schaden zwicshen 15 und 25
    int damage = 15 + (rand() % 11);
    std::cout << character->name << " trifft " << hero->name << " für " << damage << " Lebenspunkte!" << std::endl;
    hero->health -= damage;
}

//Initialisierung des Gegners
void initCharacter(Character_t* character, char* name, int health, int gold) {
    character->name = name;
    character->health = health;
    character->gold = gold;

    for (int i = 0; i < 10; i++) {
        initItem(&character->inventory[i]);
    }
}