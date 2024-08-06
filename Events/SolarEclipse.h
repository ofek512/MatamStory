#pragma once

#include "SpecialEvent.h"
#include "Event.h"
#include "Player.h"
#include "vector"


class SolarEclipse : public SpecialEvent {
public:
    void runEvent(Player &) override;
};