#include "Warrior.h"

Warrior::Warrior(string Name, struct Character *Character)
        : Player(Name, Character) {
    Current_HP = 150;
    Max_HP = 150;
}

int Warrior::getCombatPower() {
    return Level + (Force * 2);
}

void Warrior::doFight(Monster &monster) {
    if (getCombatPower() > monster.getPower()) {
        Coins += monster.getCoins();
        Level++;
        Current_HP -= 10;
    } else {
        Current_HP -= monster.getDmg();
    }
}
