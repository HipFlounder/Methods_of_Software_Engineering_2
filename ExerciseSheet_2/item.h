
#ifndef EXERCISESHEET_1_ITEM_H
#define EXERCISESHEET_1_ITEM_H

class Item {

private:
    std::string name;
    int gold;
    bool isValid;

public:
    void initItem();
    void initItem(const std::string& name, int gold);

    //Getter
    const std::string& getName() const {
        return name;
    }
    int getGold() const{
        return gold;
    }
    bool getIsValid() const{
        return isValid;
    }

    //Setter
    void setName(const std::string& name) {
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

#endif //EXERCISESHEET_1_ITEM_H
