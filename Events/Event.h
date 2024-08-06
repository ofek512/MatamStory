#pragma once

#include "Player.h"

using std::string;

class Event {
public:
    virtual ~Event() = default; //check if this should be 0
    virtual void runEvent(Player &) = 0;
    virtual string getDescription() const; // maybe make virtual? :p
};

