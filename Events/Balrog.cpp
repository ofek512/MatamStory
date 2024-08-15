#include "Balrog.h"
#include "Player.h"


Balrog::Balrog() : Monster("Balrog", 15, 100, 9001) {}

void Balrog::afterfight() {
    power += 2;
}
