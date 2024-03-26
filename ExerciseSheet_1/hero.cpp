
#include <iostream>
#include <cstdlib> // für rand()
#include "hero.h"
#include "character.h"

//Held greift Gegner an
void attack(Hero_t* hero, Character_t* enemy) {
   //Random Schaden zwicshen 15 und 25
    int damage = 15 + (rand() % 11);
    std::cout << hero->name << " trifft " << enemy->name << " für " << damage << " Lebenspunkte!" << std::endl;
    enemy->health -= damage;
}

//Gegenstand verkaufen
void sellItem(Hero_t* hero, int index) {
    if (index >= 0 && index < 10) {
        if (hero->inventory[index].isValid) {
            hero->gold += hero->inventory[index].price;
            hero->inventory[index].isValid = false;
            std::cout << "Gegenstand " << hero->inventory[index].name << " wurde verkauft. " << hero->name << " besitzt nun " << hero->gold << " Gold." << std::endl;
        }
    }
}

//Kampf zwischen Held und Gegner
bool fight(Hero_t* hero, Character_t* enemy){
    while (hero->health > 0 && enemy->health > 0) {
        attack(hero, enemy);
        if (enemy->health <= 0) {
            std::cout << enemy->name << " fiel in Ohnmacht! " << hero->name << " hat noch " << hero->health << " Lebenspunkte uebrig!" << std::endl;
            return true; //Held gewinnt Kampf
        }

        attack(enemy, hero);
        if (hero->health <= 0) {
            std::cout << hero->name << " fiel in Ohnmacht! " << enemy->name << " hat noch " << enemy->health << " Lebenspunkte uebrig!" << std::endl;
            return false; //Gegner gewinnt Kampf
        }
    }
    return false;
}

//Initialisierung des Helden
void initHero(Hero_t* hero, char* name, int health, int gold) {
    hero->name = name;
    hero->health = health;
    hero->gold = gold;

    for (int i = 0; i < 10; i++) {
        initItem(&hero->inventory[i]);
    }
    initItem(&hero->gear[0]);
    initItem(&hero->gear[1]);
}