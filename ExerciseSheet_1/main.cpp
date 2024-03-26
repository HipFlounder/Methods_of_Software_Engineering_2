
#include "hero.h"
#include "character.h"
#include "item.h"
#include <iostream>
#include <ctime>

int main() {
    //Seed für Zufallszahlen
    std::srand(time(NULL));

    //Erstellung Structs
    Hero_t annina;
    Character_t matthias, pascal;

    char hero_name[50] = "Annina";
    char character_name1[50] = "Matthias";
    char character_name2[50] = "Pascal";

    //Initialisierung Helden und Gegner
    initHero(&annina, hero_name, 300, 0);
    initCharacter(&matthias, character_name1, 50, 20);
    initCharacter(&pascal, character_name2, 100, 50);


    //Kampf 1
    bool WinsFirstFight = fight(&annina, &matthias);

    if (WinsFirstFight) {
        initItem(&annina.inventory[0], (char*)"Zaubertrank", 250);

        //Kampf 2
        bool WinsSecondFight = fight(&annina, &pascal);

        if (WinsSecondFight) {
            initItem(&annina.inventory[1], (char*)"Schwert", 30);

            //Verkaufe Gegenstände am Ende
            for (int i = 0; i < 10; i++) {
                if (annina.inventory[i].isValid) {
                    sellItem(&annina, i);
                }
            }
        } else {
            std::cout << annina.name << " hat verloren. Spiel beendet!" << std::endl;
        }
    } else {
        std::cout << annina.name << " hat verloren. Spiel beendet!" << std::endl;
    }

    return 0;
}


