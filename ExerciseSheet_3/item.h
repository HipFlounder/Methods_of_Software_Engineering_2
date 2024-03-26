
#ifndef EXERCISESHEET_3_ITEM_H
#define EXERCISESHEET_3_ITEM_H

#include <string>

class Item {

private:
    std::string name;
    int gold;
    bool isValid;

public:
    //Konstruktoren
    Item(const std::string& name, int gold) : name(name), gold(gold), isValid(true) {}
    Item() : gold(0), isValid(false) {}

    //Getter
    const std::string& getName() const{
        return name;
    }
    int getGold() const{
        return gold;
    }
    bool getIsValid() const{
        return isValid;
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
        }
    }
    void setIsValid(bool isValid) {
        this->isValid = isValid;
    }

};

std::ostream& operator<<(std::ostream& out, const Item& item);

#endif //EXERCISESHEET_3_ITEM_H
