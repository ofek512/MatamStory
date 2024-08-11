#pragma once

#include "Player.h"
#include "Monster.h"
#include <string>

using std::string;

class Warrior : public Player {
public:
    Warrior(string Name, class Character *Character);
    void afterFight() override;
    int getCombatPower() const override;
    string getDescription() const override;
    string getJob() const override;
};