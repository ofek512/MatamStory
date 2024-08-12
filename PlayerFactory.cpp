#include "PlayerFactory.h"
#include <iostream>

std::shared_ptr<Player> PlayerFactory::createPlayer(const std::string& name, const std::string& job, const std::string& character) {
    std::shared_ptr<Character> charPtr;

    if (character == "RiskTaking") {
        charPtr = std::make_shared<RiskTaker>();
    } else if (character == "Responsible") {
        charPtr = std::make_shared<Responsible>();
    } else {
        throw std::runtime_error("Invalid Players File");
    }

    if (job == "Warrior") {
        return std::make_shared<Warrior>(name, charPtr);
    } else if (job == "Archer") {
        return std::make_shared<Archer>(name, charPtr);
    } else if (job == "Magician") {
        return std::make_shared<Magician>(name, charPtr);
    } else {
        throw std::runtime_error("Invalid Players File");
    }
}
