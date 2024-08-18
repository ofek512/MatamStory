#include <stdexcept>
#include "Pack.h"
#include <vector>

Pack::Pack(Monster *monstersArray, int size) : Monster("Pack", 0, 0, 0),
                                               size(size) {
    monsters = std::make_unique<Monster[]>(size);

    // Initialize the monsters array and calculate aggregated values
    for (int i = 0; i < size; ++i) {
        monsters[i] = monstersArray[i]; // Copy each Monster
        power += monsters[i].getPower();
        loot += monsters[i].getLoot();
        damage += monsters[i].getDamage();
    }
}

std::string Pack::getDescription() const {
    return "Pack of " + std::to_string(size) + " members (power " +
           std::to_string(power) +
           ", loot " + std::to_string(loot) + ", damage " +
           std::to_string(damage) + ")";
}

void Pack::runEvent(shared_ptr<Player> player) {
    Monster::runEvent(player);
    for (int i = 0; i < size; ++i) { //recalculate the pack power
        monsters[i].afterfight();
        power += monsters[i].getPower();
    }
}

