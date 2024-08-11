#pragma once

#include <string>
#include "Player.h"
#include "Utilities.h"


using std::string;
class Character {
protected:
    string type;
public:
    Character(string xtype);
    virtual void buyPotion(Player&) = 0;
    virtual string toStr() const = 0;
};

class Responsible : public Character {
public:
    Responsible();
    void buyPotion(Player&) override;
    string toStr() const override;
};

class RiskTaker : public Character {
public:
    RiskTaker();
    void buyPotion(Player&) override;
    string toStr() const override;
};