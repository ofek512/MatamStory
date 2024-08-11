#include "Warrior.h"

Warrior::Warrior(string Name, struct Character *Character)
        : Player(Name, Character) {
    Current_HP = 150;
    Max_HP = 150;
}

int Warrior::getCombatPower() const {
    return Level + (Force * 2);
}


string Warrior::getJob() const {
    return "Warrior";
}

string Warrior::getDescription() const {
    return Name + ", " + getJob() + " with " + Character->toStr() +
           " character " + "(level " + std::to_string(Level) + ", force " +
           std::to_string(getCombatPower());
}

void Warrior::afterFight() {
    setCurrent_HP(Current_HP - 10);
}
