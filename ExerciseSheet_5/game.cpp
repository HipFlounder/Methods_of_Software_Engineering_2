
#include "game.h"
#include "hero.h"
#include "fighter.h"
#include "sorcerer.h"
#include "npc.h"
#include "character.h"

#include <iostream>
#include <ctime>
#include <exception>

void Game::play() {
    try {
        //Seed für Zufallszahlen
        std::srand(time(nullptr));

        //Erstellung Objekten
        std::shared_ptr<Hero> hero(new Hero("Nicolas", 300, 0, 2, 2, this));
        addCharacter(hero);
        std::shared_ptr<Fighter> matthias(new Fighter("Matthias", 50, 20, 4, 1, 1, this));
        addCharacter(matthias);
        std::shared_ptr<Sorcerer> pascal(new Sorcerer("Pascal", 100, 50, 4, 1, 1, this));
        addCharacter(pascal);

        //Übergebe Items an Character
        matthias->addInventarItem(std::shared_ptr<Item>(new Item("Schild", 300)));
        matthias->addInventarItem(std::shared_ptr<Item>(new Item("Schwert", 500)));
        pascal->addInventarItem(std::shared_ptr<Item>(new Item("Zauberwürfel", 1000)));
        pascal->addInventarItem(std::shared_ptr<Item>(new Item("Zaubersand", 50)));

        //Teste Exception
        try {
            matthias->setGold(-1000);
        } catch (InvalidArgument& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

        //Kampf 1
        if (hero->fight(*matthias)) {
            //shared_ptr wird verringert -> Objekt gelöscht
            matthias.reset();
            //Kampf 2
            if (hero->fight(*pascal.get())) {
                pascal.reset();
                //Verkaufe Gegenstände am Ende
                while (hero->getInventorySize() != 0) {
                    try {
                        int a = hero->getInventorySize();
                        hero->sellItem(a-1);
                    } catch (InvalidIndexException& e) {
                        //do nothing
                    }
                }
            }
        }
        hero->setGold(-100);

    } catch(const std::exception& e){
        std::cout << "Exception in Main: " << e.what() << std::endl;
    }
}

void Game::addCharacter(std::shared_ptr<Character> character) {
    if (characters.find(character->getName()) == characters.end()) {
        characters.insert({character->getName(), character});
    } else {
        throw InvalidArgument("addCharacter(): Namen bereits vergeben!");
    }
}

void Game::removeCharacter(const std::string &name) {
    if (characters.find(name) != characters.end()) {
        characters.erase(name);
    } else {
        throw InvalidArgument("removeCharacter(): Namen nicht gefunden!");
    }
}

void Game::addItem(std::shared_ptr<Item> item) {
    soldItems.push_back(item);
}

Game::~Game() {
    characters.clear();
    soldItems.clear();
}