#include <Player.h>
#include "iostream"
#include "Utilities.h"

using std::cout;
using std::endl;

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

void Player::setForce(int force) {
    if (force < 0) {
        Force = 0;
    }
    Force = force;
}

void Player::doEclipse() {
    printTurnOutcome(getSolarEclipseMessage(*this, -1));
    setForce(Force - 1);
}

int Player::getCombatPower() const {
    return Force * Level;
}

void Player::setCoins(int coins) {
    Coins = coins;
}

void Player::setCurrent_HP(int HP) {
    if (HP > Max_HP) {
        Current_HP = Max_HP;
    } else if (HP < 0) {
        Current_HP = 0;
    }
    Current_HP = HP;
}

int Player::getMax_HP() const {
    return Max_HP;
}

string Player::getDescription() const {
    return "defaul player description";
}

class Character *Player::getCharacter() {
    return Character;
}

void Player::buyPotion() {
    Character->buyPotion();

}

bool Player::operator<(const Player &other) const {
    if (this->Level != other.Level) {
        return this->Level < other.Level;
    }
    return this->Name < other.Name;  // Lexicographical comparison of names
}

void Player::afterFight() {

}

void Player::setLevel(int addition) {
    Level += addition;
}
