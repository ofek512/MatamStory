#include <list>
#include <string>
#include "Player.h"

#pragma once

using std::list;
using std::string;

class Event {
public:
    virtual ~Event() = default; //check if this should be 0
    virtual void runEvent(Player &player) = 0;
    virtual string getDescription() const; // maybe make virtual? :p
};

