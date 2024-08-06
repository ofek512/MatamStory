#pragma once

#include <list>
#include <string>
#include "Player.h"
#include "../Players/Player.h"

using std::list;
using std::string;

class Event {
public:
    virtual ~Event() = 0; //check if this should be 0
    virtual void runEvent(list<Player> players) = 0;
    string getDescription() const; // maybe make virtual? :p
};


class Monster : public Event {
protected:
    string name;
    unsigned int power;
    unsigned int loot;
    unsigned int damage;
public:
    Monster(string xName, unsigned int xPower, unsigned int xLoot,
            unsigned int xDamage);
    ~Monster() override;
    void runEvent(list<Player> players) override;
};


class Balrog : public Monster {
public:
    Balrog(string xName);
    ~Balrog() override;
    void runEvent(list<Player> players) override;

private:
    static unsigned int combatPower;
    static bool initialized;
};
