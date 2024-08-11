#include "Archer.h"

Archer::Archer(string Name, struct Character *Character)
        : Player(Name, Character) {
    Coins = 20;
}

string Archer::getJob() const {
    return "Archer";
}

string Archer::getDescription() const {
    return Name + ", " + getJob() + " with " + Character->toStr() +
           " character " + "(level " + std::to_string(Level) + ", force " +
           std::to_string(getCombatPower());
}
