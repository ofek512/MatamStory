#include "Player.h"
#include "Character.h"
#include "Utilities.h"

Player::Player(string Name, shared_ptr<Character> character) :
        Name(Name),
        Level(1),
        Force(5),
        Coins(10),
        Current_HP(100),
        Max_HP(100),
        character(character) {}

int Player::getCoins() const { return Coins; }
int Player::getForce() const { return Force; }
int Player::getHealthPoints() const { return Current_HP; }
string Player::getName() const { return Name; }
int Player::getLevel() const { return Level; }

void Player::setForce(int force) {
    Force = (force < 0) ? 0 : force;
}

void Player::doEclipse() {
    printTurnOutcome(getSolarEclipseMessage(*this, -1));
    setForce(Force - 1);
}

int Player::getCombatPower() const { return Force * Level; }

void Player::setCoins(int coins) { Coins = coins; }

void Player::setCurrent_HP(int HP) {
    Current_HP = (HP > Max_HP) ? Max_HP : (HP < 0) ? 0 : HP;
}

int Player::getMax_HP() const { return Max_HP; }

string Player::getDescription() const { return "default player description"; }

shared_ptr<Character> Player::getCharacter() { return character; }

void Player::buyPotion() { character->buyPotion(*this); }

bool Player::operator<(const Player &other) const {
    if (this->Level != other.Level) return this->Level < other.Level;
    return this->Name < other.Name;
}

void Player::afterFight() {}

void Player::setLevel(int addition) { Level = addition; }

string Player::getJob() const {
    return "";
}
