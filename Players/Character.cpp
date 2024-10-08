#include "Character.h"

void Character::buyPotion(Player &) {

}

void Responsible::buyPotion(Player &player) {
    int amount = 0;
    while (player.getCoins() > 0 &&
           player.getHealthPoints() != player.getMax_HP()) {
        player.setCoins(player.getCoins() - 5);
        player.setCurrent_HP(player.getHealthPoints() + 10);
        amount++;
    }
    printTurnOutcome(getPotionsPurchaseMessage(*this, amount));
}

string Responsible::toStr() const {
    return "Responsible";
}

string RiskTaker::toStr() const {
    return "RiskTaking";
}

void RiskTaker::buyPotion(Player &player) {
    if (player.getCoins() >= 5 ||
        player.getHealthPoints() < player.getMax_HP()) {
        player.setCoins(player.getCoins() - 5);
        player.setCurrent_HP(player.getHealthPoints() + 5);
    }
    printTurnOutcome(getPotionsPurchaseMessage(*this, 1));
}

Responsible::Responsible() : Character("Responsible") {}

RiskTaker::RiskTaker() : Character("RiskTaking") {}