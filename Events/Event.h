#pragma once

#include <memory>  // Include necessary headers
#include <string>  // Include necessary headers
#include "Player.h"

using std::shared_ptr;
using std::string;


class Event {
public:
    virtual ~Event() = default; //check if this should be 0
    virtual void runEvent(shared_ptr<Player> players) = 0;
    virtual string getDescription() const; // maybe make virtual? :p
};

