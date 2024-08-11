#pragma once

#include "Player.h"

#pragma once

#include "Player.h"
#include <string>

using std::string;

class Archer : public Player {
public:
    Archer(string Name, shared_ptr<Character> character);
    string getDescription() const override;
    string getJob() const override;
};
