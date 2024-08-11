#include "Warrior.h"

#include <Character.h>

Warrior::Warrior(string Name, shared_ptr<Character> character)
        : Player(Name, character) {
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
    return Name + ", " + getJob() + " with " + character->toStr() +
           " character " + "(level " + std::to_string(Level) + ", force " +
           std::to_string(getCombatPower());
}

void Warrior::afterFight() {
    setCurrent_HP(Current_HP - 10);
}
