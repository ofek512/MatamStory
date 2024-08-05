#include "Event.h"

// Initialize static members
unsigned int Balrog::combatPower = 15;
bool Balrog::initialized = false;


// Monster Constructor
Monster::Monster(string xName, unsigned int xPower, unsigned int xLoot, unsigned int xDamage)
    : name(xName), power(xPower), loot(xLoot), damage(xDamage) {}

// Monster Destructor
Monster::~Monster() = default;

// Monster runEvent Implementation
void Monster::runEvent(list<Player> players) {
    // Base implementation for Monster events (could be empty or provide some basic functionality)
}

// Balrog Constructor
Balrog::Balrog(string xName, unsigned int xPower, unsigned int xLoot, unsigned int xDamage)
    : Monster(xName, xPower, xLoot, xDamage) {
    if (!initialized) {
        combatPower = xPower; // Initialize combat power only once
        initialized = true;
    }
}
Balrog::Balrog(string xName) : Monster(xName, 15, 100, 9001) {
        if (!initialized) {
        combatPower = 15; // Initialize combat power only once
        initialized = true;
    }
}

// Balrog Destructor
Balrog::~Balrog() = default;

// Balrog runEvent Implementation
void Balrog::runEvent(list<Player> players) {
    combatPower += 2; // Increase combat power by 2 for each event
    // Implement the specific event logic for Balrog here
}
