#pragma once

#include "Events/Monster.h"
#include "Events/Balrog.h"
#include "Events/SolarEclipse.h"
#include "Events/PotionsMerchant.h"
#include "Events/Pack.h"
#include <sstream>
#include <vector>

class EventFactory {
public:
    static std::unique_ptr<Event> createEvent(const std::string& eventLine);
};
