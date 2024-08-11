#pragma once

#include <string>


using std::string;
class Character {
protected:
    string type;
public:
    Character(string xtype);
    virtual void buyPotion();
    virtual string toStr() const = 0;
};

class Responsible : public Character {
public:
    Responsible();
    void buyPotion() override;
    string toStr() const override;
};

class RiskTaker : public Character {
public:
    RiskTaker();
    void buyPotion() override;
    string toStr() const override;
};