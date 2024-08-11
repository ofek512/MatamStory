#pragma once

#include "Monster.h"

class Pack : public Monster {
private:
    std::unique_ptr<Monster[]> monsters; // Array of Monsters
    int size;

public:
    Pack(Monster *monstersArray, int size);
    std::string getDescription() const override;
};
