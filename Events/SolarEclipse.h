#pragma once
#include "SpecialEvent.h"
#include "Player.h"
#include "Event.h"


class SolarEclipse : public SpecialEvent {
    void runEvent(Player &) override;
};