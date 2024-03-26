
#include <cstring>
#include <iostream>
#include "item.h"

std::ostream& operator<<(std::ostream& out, const Item& item) {
    out << item.getName() << " (" << item.getGold() << ")";
    return out;
}