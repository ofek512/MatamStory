#include "Balrog.h"
#include "Player.h"


Balrog::Balrog() : Monster("Balrog", 15, 100, 9001) {}

// Balrog runEvent Implementation
void Balrog::runEvent(shared_ptr<Player> player) {
    if (player->getCombatPower() > getPower()) {
        player->setCoins(player->getCoins() + getLoot());
        player->setLevel(player->getLevel() + 1);
        printTurnOutcome(getEncounterWonMessage(*player, getLoot()));
    } else {
        player->setCurrent_HP(player->getHealthPoints() - getDamage());
        printTurnOutcome(getEncounterLostMessage(*player, getDamage()));
    }
    power += 2;
}