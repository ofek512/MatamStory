#pragma once

#include "Event.h"  // Include the Encounter class definition

using std::string;
using std::shared_ptr;

class Monster : public Event {
protected:
    string name;
    unsigned int power;
    unsigned int loot;
    unsigned int damage;
public:
    Monster(string xName = "", unsigned int xPower = 0, unsigned int xLoot = 0,
            unsigned int xDamage = 0);
    void runEvent(shared_ptr<Player>) override;
    int getPower();
    int getLoot() const;
    int getDamage() const;
    string getDescription() const override;
};
