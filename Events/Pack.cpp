#include "Pack.h"

Pack::Pack(Monster* monsters, int size){
    name = "Pack";
    for (int i = 0; i < size; ++i) {
        power += monsters[i].getPower();
        loot += monsters[i].getLoot();
        damage += monsters[i].getDamage();
    }
}