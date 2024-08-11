#include "Balrog.h"
#include "Player.h"

// Initialize static members
unsigned int Balrog::Power = 15;
bool Balrog::initialized = false;

Balrog::Balrog() : Monster("Balrog", 15, 100, 9001) {
    if (!initialized) {
        Power = 15; // Initialize combat power only once
        initialized = true;
    }
}

// Balrog Destructor
Balrog::~Balrog() = default;

// Balrog runEvent Implementation
void Balrog::runEvent(shared_ptr<Player> player) {
    if (player->getCombatPower() > getPower()) {
        player->setCoins(player->getCoins() + getLoot());
        player->setLevel(player->getLevel() + 1);
        printTurnOutcome(getEncounterWonMessage(*player, getLoot()));
    } else {
        player->setCurrent_HP(player->getHealthPoints() - getDamage());
        printTurnOutcome(getEncounterLostMessage(*player, getDamage()))
    }
    power += 2;
}