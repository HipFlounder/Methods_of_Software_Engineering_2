
#include "fighter.h"
#include <iostream>

void Fighter::attack(Character& enemy) {
    //Random Schaden zwischen 5 und 10
    int damage = (5 + (std::rand() % 6)) + getStrength() - enemy.getArmor();
    std::cout << this->name << " trifft " << enemy << " für " << damage << " Lebenspunkte!" << std::endl;
    enemy.setHealth(enemy.getHealth() - damage);
}

Fighter::~Fighter() {
    std::cout << "Kämpfer " << getName() << " sagt: Auf Wiedersehen!" << std::endl;
}