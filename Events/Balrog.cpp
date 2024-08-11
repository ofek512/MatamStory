#include "Balrog.h"

// Initialize static members
unsigned int Balrog::Power = 15;
bool Balrog::initialized = false;

Balrog::Balrog() : Monster("Balrog", 15, 100, 9001) {
    if (!initialized) {
        Power = 15; // Initialize combat power only once
        initialized = true;
    }
}

// Balrog Destructor
Balrog::~Balrog() = default;

// Balrog runEvent Implementation
void Balrog::runEvent(Player &player) {
    player.doFight(*this);
    Power += 2; // Increase combat power by 2 for each event
    // Implement the specific event logic for Balrog here
}