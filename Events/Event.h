#pragma once

#include <memory>  // Include necessary headers
#include <string>  // Include necessary headers
#include "Players/Player.h"

using std::shared_ptr;
using std::string;

class Event {
public:
    virtual ~Event() = default;
    virtual void runEvent(shared_ptr<Player> players) = 0;
    virtual string getDescription() const;
};

