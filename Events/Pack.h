#pragma once

#include "Monster.h"
#include <vector>

class Pack : public Monster {
private:
    std::vector<std::unique_ptr<Monster>> monsters; // Array of Monsters
    int size;

public:
    Pack(Monster *monstersArray, int size);
    std::string getDescription() const override;
    void runEvent(shared_ptr<Player>) override;
};
