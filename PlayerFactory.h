#pragma once

#include <memory>
#include <string>
#include "Player.h"
#include "Warrior.h"
#include "Magician.h"
#include "Archer.h"
#include "Character.h"
#include <stdexcept>

class PlayerFactory {
public:
    static std::shared_ptr<Player> createPlayer(const std::string& name, const std::string& job, const std::string& character);
};
