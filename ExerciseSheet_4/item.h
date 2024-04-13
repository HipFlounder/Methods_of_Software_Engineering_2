
#ifndef EXERCISESHEET_3_ITEM_H
#define EXERCISESHEET_3_ITEM_H

#include "exceptions.h"

#include <string>

class Item {

private:
    std::string name;
    int gold;

public:
    //Konstruktoren
    Item(const std::string& name, int gold) : name(name), gold(gold) {
        if (name.size() == 0) {
            throw InvalidArgument("Item: Leerer Name!");
        }
        if (gold < 0) {
            throw InvalidArgument("Item: Negativer Wert!");
        }
    }

    //Getter
    const std::string& getName() const{
        return name;
    }
    int getGold() const{
        return gold;
    }

    //Setter
    void setName(const std::string &name) {
        if (name.size() > 0 ) {
            this->name = name;
        }
    }
    void setGold(int gold) {
        if (gold >= 0) {
            this->gold = gold;
        } else {
            throw InvalidArgument("setGold(): Negativer Wert!");
        }
    }

};

std::ostream& operator<<(std::ostream& out, const Item& item);

#endif //EXERCISESHEET_3_ITEM_H
