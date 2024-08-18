#include "job.h"
#include "Utilities.h"

Job::Job() : type("") {}

int Job::getCombatPower(Player &player) {
    return player.getForce() + player.getLevel();
}

std::string Job::getJob() {
    return type;
}

void Job::doEclipse(Player &player) {
    printTurnOutcome(getSolarEclipseMessage(player, -1));
    player.setForce(player.getForce() - 1);
}

void Job::afterFight(Player &player) {}

void Job::applyToPlayer(Player &) {}

Archer::Archer() {
    type = "Archer";
}

void Archer::applyToPlayer(Player &player) {
    player.setCoins(20);
}

Magician::Magician() {
    type = "Magician";
}

void Magician::doEclipse(Player &player) {
    printTurnOutcome(getSolarEclipseMessage(player, 1));
    player.setForce(player.getForce() + 1);
}

Warrior::Warrior() {
    type = "Warrior";
}

void Warrior::afterFight(Player &player) {
    player.setCurrent_HP(player.getHealthPoints() - 10);
}

void Warrior::applyToPlayer(Player &player) {
    player.setMaxHP(150);
    player.setCurrent_HP(150);
}

int Warrior::getCombatPower(Player &player) {
    return player.getForce() * 2 + player.getLevel();
}
