#pragma once

#include "Monster.h"

class Balrog : public Monster {
public:
    Balrog();
    ~Balrog() override;
    void runEvent(shared_ptr<Player>) override;

private:
    static unsigned int Power;
    static bool initialized;
};