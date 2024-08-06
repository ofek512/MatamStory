#include <Player.h>
#include "iostream"

Player::Player(std::string Name, class Character *Character) :
        Name(Name),
        Level(1),
        Force(5),
        Coins(10),
        Current_HP(100),
        Max_HP(100),
        Character(Character) {}

int Player::getCoins() const {
    return Coins;
}

int Player::getForce() const {
    return Force;
}

int Player::getHealthPoints() const {
    return Current_HP;
}

string Player::getName() const {
    return Name;
}

int Player::getLevel() const {
    return Level;
}

void Player::doEclipse() {
    Force--;
}

int Player::getCombatPower() {
    return Force * Level;
}

void Player::setCoins(int coins) {
    Coins = coins;
}

void Player::setCurrent_HP(int HP) {
    if (HP > Max_HP) {
        Current_HP = Max_HP;
    }
    Current_HP = HP;
}

int Player::getMax_HP() const {
    return Max_HP;
}

void Player::doFight(Monster &monster) {
    if (getCombatPower() > monster.getPower()) {
        Coins += monster.getCoins();
        Level++;
    } else {
        Current_HP -= monster.getDmg();
    }
}