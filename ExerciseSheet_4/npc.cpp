
#include "npc.h"

Item* Npc::retrieveRandomLoot() {
    for (int i = 0; i < 10; i++) {
        int rand = std::rand() % 10;
        Item* item = removeInventarItem(rand);
        if (item != nullptr) {
            return item;
        }
    }
    return nullptr;
}