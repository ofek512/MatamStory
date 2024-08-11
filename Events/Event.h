#pragma once

#include "Player.h"

class Event {
public:
    virtual ~Event() = default; //check if this should be 0
    virtual void runEvent(shared_ptr<Player>) = 0;
    virtual string getDescription() const; // maybe make virtual? :p
};

