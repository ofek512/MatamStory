#pragma once

#include "Player.h"
#include <string>

using std::string;

class Warrior : public Player {
public:
    Warrior(string Name, shared_ptr<Character> character);
    void afterFight() override;
    int getCombatPower() const override;
    string getDescription() const override;
    string getJob() const override;
};
