
#include <string>
#include <Player.h>
#pragma once
using std::string;

class Magician: public Player{
public:
    Magician(string Name, Character Character);
    void doEclipse() override;
};