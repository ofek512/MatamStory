#include "Warrior.h"

Warrior::Warrior(string Name, struct Character *Character)
        : Player(Name, Character) {
    Current_HP = 150;
    Max_HP = 150;
}

int Warrior::getCombatPower() const {
    return Level + (Force * 2);
}

void Warrior::doFight(Monster &monster) {
    if (getCombatPower() > monster.getPower()) {
        Coins += monster.getLoot();
        Level++;
        Current_HP -= 10;
    } else {
        Current_HP -= monster.getDamage();
    }
}

string Warrior::getJob() const {
    return "Warrior";
}

string Warrior::getDescription() const {
    return Name + ", " + getJob() + " with " + Character->toStr() +
           " character " + "(level " + std::to_string(Level) + ", force " +
           std::to_string(getCombatPower());
}