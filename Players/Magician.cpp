#include <Magician.h>
#include "Player.h"
#pragma once

Magician::Magician(string Name, Character Character):
    Player(Name, Character){}

void Magician::doEclipse() {
    Force++;
}

