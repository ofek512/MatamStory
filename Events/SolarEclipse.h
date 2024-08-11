#pragma once

#include "SpecialEvent.h"
#include "Player.h"
#include "Event.h"
#include "vector"


class SolarEclipse : public SpecialEvent {
public:
    void runEvent(shared_ptr<Player>) override;
};