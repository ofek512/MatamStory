#pragma once

#include "Player.h"
#include <string>

using std::string;

class Warrior : public Player {
public:
    Warrior(string Name, class Character *Character);
    void doFight(Monster &monster) override;
    int getCombatPower() override;

};