#include <Magician.h>
#include "Player.h"

#pragma once

Magician::Magician(string Name, class Character *Character) :
        Player(Name, Character) {}

void Magician::doEclipse() {
    Force++;
}

