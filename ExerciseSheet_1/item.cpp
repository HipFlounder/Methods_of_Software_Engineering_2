
#include <cstring>
#include <iostream>
#include "item.h"

//setze isValid auf false auf übergebenes Item
void initItem(Item_t* item) {
    item->isValid = false;
}

//Initialisierung des Items
void initItem(Item_t* ITEM, const char* name, int gold) {
    ITEM->name = name;
    if (gold >= 0) {
        ITEM->price = gold;
    } else {
        ITEM->price = 0;
    }
    ITEM->isValid = true;
    std::cout << "Gegenstand " << ITEM->name << " wurde zum Inventar der Heldin hinzugefuegt." << std::endl;
}