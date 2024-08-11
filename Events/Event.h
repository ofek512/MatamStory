#pragma once

#include "Player.h"

class Event {
public:
    virtual ~Event() = 0; //check if this should be 0
    virtual void runEvent(Player &) = 0;
    virtual string getDescription() const = 0; // maybe make virtual? :p
};

