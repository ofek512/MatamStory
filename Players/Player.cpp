#include "Player.h"
#include "Character.h"
#include "Utilities.h"
#include "job.h"

Player::Player(string Name, shared_ptr<Character> character) :
        Name(Name),
        Level(1),
        Force(5),
        Coins(10),
        Current_HP(100),
        Max_HP(100),
        character(character) {}

Player::Player(string Name, shared_ptr<Character> character, shared_ptr<Job> job) :
        Name(Name),
        Level(1),
        Force(5),
        Coins(10),
        Current_HP(100),
        Max_HP(100),
        character(character),
        job(job) {
    job->applyToPlayer(*this);
}

int Player::getCoins() const { return Coins; }
int Player::getForce() const { return Force; }
int Player::getHealthPoints() const { return Current_HP; }
string Player::getName() const { return Name; }
int Player::getLevel() const { return Level; }

void Player::setForce(int force) {
    Force = (force < 0) ? 0 : force;
}

void Player::doEclipse() { job->doEclipse(*this); }

int Player::getCombatPower() { return job->getCombatPower(*this); }

void Player::setCoins(int coins) { Coins = coins; }

void Player::setCurrent_HP(int HP) {
    Current_HP = (HP > Max_HP) ? Max_HP : (HP < 0) ? 0 : HP;
}

int Player::getMax_HP() const { return Max_HP; }

string Player::getDescription() const {
    return Name + ", " + getJob() + " with " + character->toStr() +
    " character " + "(level " + std::to_string(Level) + ", force " +
    std::to_string(Force) + ")";
}

shared_ptr<Character> Player::getCharacter() { return character; }

void Player::buyPotion() { character->buyPotion(*this); }

bool Player::operator<(const Player &other) const {
    if (this->Level != other.Level) return this->Level < other.Level;
    return this->Name < other.Name;
}

void Player::afterFight() { job->afterFight(*this); }

void Player::setLevel(int addition) { Level = addition; }

string Player::getJob() const { return job->getJob(); }

void Player::setMaxHP(int HP) { Max_HP = HP; }
