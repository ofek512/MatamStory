#pragma once
#include <string>
#include "SpecialEvent.h"
#include "Player.h"

class PotionsMerchant: public SpecialEvent{
public:
    void runEvent(Player&) override;
};