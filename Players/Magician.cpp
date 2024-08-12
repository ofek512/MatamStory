#include "Magician.h"
#include "Utilities.h"

Magician::Magician(string Name, shared_ptr<Character> character) :
        Player(Name, character) {}

void Magician::doEclipse() {
    printTurnOutcome(getSolarEclipseMessage(*this, 1));
    Force++;
}

string Magician::getJob() const {
    return "Magician";
}

string Magician::getDescription() const {
    return Name + ", " + getJob() + " with " + character->toStr() +
           " character " + "(level " + std::to_string(Level) + ", force " +
           std::to_string(Force) + ")";
}


