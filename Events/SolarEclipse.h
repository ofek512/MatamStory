#pragma once

#include "SpecialEvent.h"
#include "Player.h"


class SolarEclipse : public SpecialEvent {
public:
    void runEvent(Player &) override;
};