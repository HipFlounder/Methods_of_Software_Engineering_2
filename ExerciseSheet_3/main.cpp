
#include "character.h"
#include "item.h"
#include "hero.h"
#include "npc.h"
#include "fighter.h"
#include "sorcerer.h"
#include <ctime>

int main() {
    //Seed für Zufallszahlen
    std::srand(time(nullptr));

    //Erstellung Objekten
    Hero hero("Annina", 300, 0, 2,2);
    Fighter matthias("Matthias", 50, 20, 4, 1, 1);
    Sorcerer pascal("Pascal", 100, 50, 4, 1, 1);

    //Übergebe Items an Character
    matthias.addInventarItem(Item("Schild", 300));
    matthias.addInventarItem(Item("Schwert", 500));
    pascal.addInventarItem(Item("Zauberwürfel", 1000));
    pascal.addInventarItem(Item("Zaubersand", 50));

    //Kampf 1
    if (hero.fight(matthias)) {
        //Kampf 2
        if (hero.fight(pascal)) {
            //Verkaufe Gegenstände am Ende
            for (int i = 0; i < 10; i++) {
                 if (hero.getInventory(i).getIsValid()) {
                    hero.sellItem(i);
                }
            }
        }
    }

    return 0;
}