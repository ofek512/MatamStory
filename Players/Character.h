#pragma once

#include <string>

class Player;  // Forward declaration to avoid circular dependency

using std::string;

class Character {
protected:
    string type;

public:
    Character(string xtype) : type(xtype) {}
    virtual ~Character() = default;
    virtual void buyPotion(Player &) = 0;
    virtual string toStr() const = 0;
};

class Responsible : public Character {
public:
    Responsible();
    void buyPotion(Player &) override;
    string toStr() const override;
};

class RiskTaker : public Character {
public:
    RiskTaker();
    void buyPotion(Player &) override;
    string toStr() const override;
};
