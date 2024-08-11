#pragma once

#include "SpecialEvent.h"


class SolarEclipse : public SpecialEvent {
public:
    void runEvent(shared_ptr<Player>) override;
};