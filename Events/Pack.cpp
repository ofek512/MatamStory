#include <stdexcept>
#include "Pack.h"
#include <vector>

Pack::Pack(std::vector<std::unique_ptr<Monster>> monsters)
        : Monster("Pack", 0, 0, 0), monsters(std::move(monsters)) {
    // Calculate aggregated values
    for (const auto &monster: this->monsters) {
        power += monster->getPower();
        loot += monster->getLoot();
        damage += monster->getDamage();
    }
}

std::string Pack::getDescription() const {
    return "Pack of " + std::to_string(int(monsters.size())) +
           " members (power " +
           std::to_string(power) +
           ", loot " + std::to_string(loot) + ", damage " +
           std::to_string(damage) + ")";
}

void Pack::runEvent(std::shared_ptr<Player> player) {
    Monster::runEvent(player);
    power = 0;
    for (const auto &monster: monsters) { // recalculate the pack power
        monster->afterfight();
        power += monster->getPower();
    }
}
