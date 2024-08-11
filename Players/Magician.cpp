#include <Magician.h>
#include "Player.h"

#pragma once

Magician::Magician(string Name, class Character *Character) :
        Player(Name, Character) {}

void Magician::doEclipse() {
    printTurnOutcome(getSolarEclipseMessage(*this, 1));
    Force++;
}

string Magician::getJob() const {
    return "Magician";
}

string Magician::getDescription() const {
    return Name + ", " + getJob() + " with " + Character->toStr() +
           " character " + "(level " + std::to_string(Level) + ", force " +
           std::to_string(getCombatPower());
}


