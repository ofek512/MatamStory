#include "Archer.h"

#include <Character.h>

Archer::Archer(string Name, shared_ptr<Character> character)
        : Player(Name, character) {
    Coins = 20;
}

string Archer::getJob() const {
    return "Archer";
}

string Archer::getDescription() const {
    return Name + ", " + getJob() + " with " + character->toStr() +
           " character " + "(level " + std::to_string(Level) + ", force " +
           std::to_string(getCombatPower());
}
