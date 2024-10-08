#pragma once

#include <string>
#include "Monster.h"

class Balrog : public Monster {
public:
    Balrog();
    ~Balrog() override;
    void runEvent(Player &) override;

private:
    static unsigned int Power;
    static bool initialized;
};