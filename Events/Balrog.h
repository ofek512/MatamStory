#pragma once

#include "Monster.h"

class Balrog : public Monster {
public:
    Balrog();
    void runEvent(shared_ptr<Player>) override;

private:
    unsigned int Power;
};