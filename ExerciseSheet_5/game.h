
#ifndef EXERCISESHEET_5_GAME_H
#define EXERCISESHEET_5_GAME_H

#include <map>
#include <vector>
#include <memory>
#include <string>

//Forward Declaration
class Character;
class Item;

class Game {
private:
    std::map<std::string, std::shared_ptr<Character>> characters;
    std::vector<std::shared_ptr<Item>> soldItems;

public:
    //Default Konstruktor
    Game() = default;

    //Destruktor
    ~Game();

    void play();

    void addCharacter(std::shared_ptr<Character> character);

    void removeCharacter(const std::string& name);

    void addItem(std::shared_ptr<Item> item);

};


#endif //EXERCISESHEET_5_GAME_H
