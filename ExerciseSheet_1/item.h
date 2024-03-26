
#ifndef EXERCISESHEET_1_ITEM_H
#define EXERCISESHEET_1_ITEM_H

struct Item_t {
    std::string name;
    int price;
    bool isValid;
};

void initItem(Item_t* item);

void initItem(Item_t* ITEM, const char* name, int gold);

#endif //EXERCISESHEET_1_ITEM_H
