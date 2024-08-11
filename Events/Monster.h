#pragma once

#include "Events/Event.h"
#include <string>

using std::string;

class Monster : public Event {
protected:
    string name;
    unsigned int power;
    unsigned int loot;
    unsigned int damage;
public:
    Monster(string xName = "", unsigned int xPower = 0, unsigned int xLoot = 0,
            unsigned int xDamage = 0);
    ~Monster() override;
    void runEvent(Player &) override;
    int getPower();
    int getLoot();
    int getDamage();
    virtual string getDescription() const override;
};

