#pragma once

#include "Encounter.h"  // Include the Encounter class definition

using std::string;
using std::shared_ptr;

class Monster : public Encounter {
protected:
    string name;
    unsigned int power;
    unsigned int loot;
    unsigned int damage;
public:
    Monster(string xName = "", unsigned int xPower = 0, unsigned int xLoot = 0,
            unsigned int xDamage = 0);
    ~Monster() override;
    void runEvent(shared_ptr<Player>) override;
    int getPower();
    int getLoot();
    int getDamage();
    string getDescription() const override;
};
