
#include "sorcerer.h"
#include <iostream>

#include "hero.h"

void Sorcerer::attack(Character& enemy) {
    //Random Schaden zwischen 5 und 10
    int damage = (5 + (std::rand() % 6)) + getMagicPower() - enemy.getMagicResistance();
    std::cout << this->name << " trifft " << enemy << " für " << damage << " Lebenspunkte!" << std::endl;
    enemy.setHealth(enemy.getHealth() - damage);
}

Sorcerer::~Sorcerer() {
    std::cout << "Zauberer " << getName() << " sagt: Auf Wiedersehen!" << std::endl;
}