
#include "SpecialEvent.h"
#include "Player.h"
#include "vector"


class SolarEclipse : public SpecialEvent {
    void runEvent(Player &) override;
};