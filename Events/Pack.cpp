#include "Pack.h"

Pack::Pack(Monster* monsters, int size): size(size){
    name = "Pack";
    for (int i = 0; i < size; ++i) {
        power += monsters[i].getPower();
        loot += monsters[i].getLoot();
        damage += monsters[i].getDamage();
    }
}

string Pack::getDescription() const {
    return "Pack of " + std::to_string(size) + " members (power " + std::to_string(power) + ", loot" +
                                               std::to_string(loot) + ", damage" + std::to_string(damage);
}