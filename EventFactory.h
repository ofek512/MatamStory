#pragma once

#include "Monster.h"
#include "Balrog.h"
#include "SolarEclipse.h"
#include "PotionsMerchant.h"
#include "Pack.h"
#include <sstream>
#include <vector>

class EventFactory {
public:
    static std::unique_ptr<Event> createEvent(const std::string& eventLine);
};
