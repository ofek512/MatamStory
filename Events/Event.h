#pragma once
#include <iostream>
#include "Player.h"
using std::cout;
using std::endl;

class Event {
public:
    virtual ~Event() = default; //check if this should be 0
    virtual void runEvent(Player &player) = 0;
    virtual string getDescription() const = 0; // maybe make virtual? :p
};

