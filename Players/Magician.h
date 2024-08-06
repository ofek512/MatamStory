
#include <string>
#include <Player.h>
#include "Character.h"

#pragma once
using std::string;

class Magician : public Player {
public:
    Magician(string Name, class Character *Character);
    void doEclipse() override;
    string getDescription() const override;
    string getJob() const override;
};