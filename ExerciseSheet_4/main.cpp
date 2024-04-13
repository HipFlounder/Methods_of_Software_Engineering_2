
#include "hero.h"
#include "fighter.h"
#include "sorcerer.h"
#include "npc.h"

#include <ctime>
#include <exception>

int main() {
    try {

        //Seed für Zufallszahlen
        std::srand(time(nullptr));

        //Erstellung Objekten
        Hero hero("Annina", 300, 0, 2,2);
        Fighter matthias("Matthias", 50, 20, 4, 1, 1);
        Sorcerer pascal("Pascal", 100, 50, 4, 1, 1);

        //Übergebe Items an Character
        matthias.addInventarItem(new Item("Schild", 300));
        matthias.addInventarItem(new Item("Schwert", 500));
        pascal.addInventarItem(new Item("Zauberwürfel", 1000));
        pascal.addInventarItem(new Item("Zaubersand", 50));

        //Kampf 1
        if (hero.fight(matthias)) {
            //Kampf 2
            if (hero.fight(pascal)) {
                //Verkaufe Gegenstände am Ende
                for (int i = 0; i < 10; i++) {
                    if (hero.getInventory(i) != nullptr) {
                        hero.sellItem(i);
                    }
                }
            }
        }
        hero.setGold(-100);

        return 0;

    } catch(std::exception& e){
        std::cout << "Exception in Main: " << e.what() << std::endl;
    }

}