
#include "npc.h"

std::shared_ptr<Item> Npc::retrieveRandomLoot() {
    try {
        int rand = std::rand() % inventory.size();
        std::shared_ptr<Item> item = removeInventarItem(rand);
        return item;
    } catch (InvalidIndexException& e) {
        return nullptr;
    }
}