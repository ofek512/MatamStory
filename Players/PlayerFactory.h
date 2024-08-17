#pragma once

#include <memory>
#include <string>
#include "Players/Player.h"
#include "Character.h"
#include <stdexcept>
#include "Players/job.h"

class PlayerFactory {
public:
    static std::shared_ptr<Job> generateJob(const std::string&);
    static std::shared_ptr<Character> generateCharacter(const std::string&);
};
