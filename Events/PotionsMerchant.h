#pragma once
#include "SpecialEvent.h"
#include "Player.h"

class PotionsMerchant: public SpecialEvent{
public:
    void runEvent(Player&) override;
};