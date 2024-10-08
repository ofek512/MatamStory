#include <Player.h>
#include "iostream"

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

int Player::setForce(int force) {
    if(force < 0)
        Force = 0;
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
    } else if (HP < 0){
        Current_HP = 0;
    }
    Current_HP = HP;
}

int Player::getMax_HP() const {
    return Max_HP;
}

void Player::doFight(Monster &monster) {
    if (getCombatPower() > monster.getPower()) {
        Coins += monster.getLoot();
        Level++;
        printTurnOutcome(getEncounterWonMessage(*this, monster.getLoot()));
    } else {
        setCurrent_HP(Current_HP - monster.getDamage());
        printTurnOutcome(getEncounterLostMessage(*this, monster.getDamage()))
    }
}

string Player::getDescription() const {

}

class Character *Player::getCharacter() {
    return Character;
}

bool Player::operator<(const Player& other) const {
    if (this->Level != other.Level) {
        return this->Level < other.Level;
    }
    return this->Name < other.Name;  // Lexicographical comparison of names
}