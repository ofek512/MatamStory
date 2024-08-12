#include "Monster.h"



// Monster Constructor
Monster::Monster(string xName, unsigned int xPower, unsigned int xLoot,
                 unsigned int xDamage)
        : name(xName), power(xPower), loot(xLoot), damage(xDamage) {}

// Monster Destructor

// Monster runEvent Implementation
void Monster::runEvent(shared_ptr<Player> player) {
    if (player->getCombatPower() > getPower()) {
        player->setCoins(player->getCoins() + getLoot());
        player->setLevel(player->getLevel() + 1);
        printTurnOutcome(getEncounterWonMessage(*player, getLoot()));
        player->afterFight();
    } else {
        player->setCurrent_HP(player->getHealthPoints() - getDamage());
        printTurnOutcome(getEncounterLostMessage(*player, getDamage()));
    }
}

int Monster::getDamage() const {
    return damage;
}

int Monster::getLoot() const {
    return loot;
}

int Monster::getPower() {
    return power;
}

string Monster::getDescription() const {
    return name + " (power " + std::to_string(power) + ", loot " +
    std::to_string(loot) + ", damage " + std::to_string(damage) + ")";
}
