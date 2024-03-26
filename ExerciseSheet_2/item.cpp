
#include <cstring>
#include <iostream>
#include "item.h"

//setze isValid auf false auf übergebenes Item
void Item::initItem() {
    isValid = false;
}

//Initialisierung des Items
void Item::initItem(const std::string& name, int gold) {
    this->name = name;
    if (gold >= 0) {
        this->gold = gold;
    } else {
        this->gold = 0;
    }
    isValid = true;
}