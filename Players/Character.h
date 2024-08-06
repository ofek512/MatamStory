#pragma once

#include <string>
#include <Player.h>

class Character {
protected:
    string type;
public:
    Character(string xtype);
    virtual void buyPotion(Player &);
    virtual string toStr() const = 0;
};

class Responsible : public Character {
public:
    void buyPotion(Player &) override;
    string toStr() const override;
};

class RiskTaker : public Character {
public:
    void buyPotion(Player &) override;
    string toStr() const override;
};