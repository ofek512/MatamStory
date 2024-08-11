#include "Monster.h"



// Monster Constructor
Monster::Monster(string xName, unsigned int xPower, unsigned int xLoot,
                 unsigned int xDamage)
        : name(xName), power(xPower), loot(xLoot), damage(xDamage) {}

// Monster Destructor
Monster::~Monster() = default;

// Monster runEvent Implementation
void Monster::runEvent(shared_ptr<Player> player) {
    player->doFight(*this);
}

int Monster::getDamage() {
    return damage;
}

int Monster::getLoot() {
    return loot;
}

int Monster::getPower() {
    return power;
}

string Monster::getDescription() const {
    return name + " (power " + std::to_string(power) + ", loot" +
    std::to_string(loot) + ", damage" + std::to_string(damage);
}
