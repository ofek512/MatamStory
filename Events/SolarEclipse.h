#pragma once

#include "SpecialEvent.h"
#include "Player.h"


class SolarEclipse : public SpecialEvent {
public:
    void runEvent(shared_ptr<Player>) override;
    string getDescription() const override;
};