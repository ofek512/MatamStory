#pragma once
#include <string>
#include <Player.h>

class Character{
public:
    virtual void buyPotion(Player&) = 0;
};

class Responsible: Character{
public:
    void buyPotion(Player&) override;
};