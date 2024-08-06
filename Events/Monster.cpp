#include "Monster.h"



// Monster Constructor
Monster::Monster(string xName, unsigned int xPower, unsigned int xLoot,
                 unsigned int xDamage)
        : name(xName), power(xPower), loot(xLoot), damage(xDamage) {}

// Monster Destructor
Monster::~Monster() = default;

// Monster runEvent Implementation
void Monster::runEvent(Player& player) {
    player.doFight(*this);
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

