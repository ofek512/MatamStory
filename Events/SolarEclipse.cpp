#include "SolarEclipse.h"

void SolarEclipse::runEvent(shared_ptr<Player> player) {
    player->doEclipse();

}
