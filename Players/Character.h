#pragma once

#include <string>
#include <Player.h>

class Character {
protected:
    string type;
public:
    Character(string xtype);
    virtual void buyPotion(Player &);
};

class Responsible : public Character {
public:
    void buyPotion(Player &) override;
};

class RiskTaker : public Character {
public:
    void buyPotion(Player &) override;
};