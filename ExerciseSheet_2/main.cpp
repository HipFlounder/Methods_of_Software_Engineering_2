
#include "hero.h"
#include "character.h"
#include "item.h"
#include <iostream>
#include <ctime>

int main() {
    //Seed für Zufallszahlen
    std::srand(time(nullptr));

    //Erstellung Objekten
    Hero annina;
    Character matthias, pascal;

    //Initialisierung Helden und Gegner
    annina.initHero("Annina", 300, 0);
    matthias.initCharacter("Matthias", 50, 20);
    pascal.initCharacter("Pascal", 100, 50);

    //Ininitalisierung Items
    Item item1, item2, item3, item4;
    item1.initItem("Schild", 300);
    item2.initItem("Schwert", 500);
    item3.initItem("Diamant", 1000);
    item4.initItem("Goldbarren", 800);

    //Übergebe Items an Character
    matthias.addInventarItem(item1);
    matthias.addInventarItem(item2);
    pascal.addInventarItem(item3);
    pascal.addInventarItem(item4);

    //Kampf 1
    if (annina.fight(&matthias)) {

        //Kampf 2
        if (annina.fight(&pascal)) {

            //Verkaufe Gegenstände am Ende
            for (int i = 0; i < 10; i++) {
                if (annina.getInventory(i).getIsValid()) {
                    annina.sellItem(i);
                }
            }
        } else {
            std::cout << annina.getName() << " hat verloren. Spiel beendet!" << std::endl;
        }
    } else {
        std::cout << annina.getName() << " hat verloren. Spiel beendet!" << std::endl;
    }

    return 0;
}


