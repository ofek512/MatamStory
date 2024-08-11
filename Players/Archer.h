#pragma once

#include "Player.h"

#pragma once

#include "Player.h"
#include <string>

using std::string;

class Archer : public Player {
public:
    Archer(string Name, class Character *Character);
    string getDescription() const override;
    string getJob() const override;
};
