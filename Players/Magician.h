#pragma once

#include <string>
#include "Player.h"
#include "Character.h"

using std::string;

class Magician : public Player {
public:
    Magician(string Name, shared_ptr<Character> character);
    void doEclipse() override;
    string getDescription() const override;
    string getJob() const override;
};