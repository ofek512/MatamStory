#pragma once

#include "Monster.h"
#include <vector>

class Pack : public Monster {
private:
    std::vector<std::unique_ptr<Monster>> monsters; // Vector of Monster pointers

public:
    Pack(std::vector<std::unique_ptr<Monster>> monsters);
    std::string getDescription() const override;
    void runEvent(std::shared_ptr<Player>) override;
};
