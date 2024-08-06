#include "Archer.h"

Archer::Archer(string Name, struct Character *Character)
        : Player(Name, Character) {
    Coins = 20;
}
//this is