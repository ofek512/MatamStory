#pragma once

#include "Monster.h"

class Balrog : public Monster {
public:
    Balrog();
    void afterfight() override;
};