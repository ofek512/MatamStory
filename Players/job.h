#pragma once

#include "Player.h"

class Job {
protected:
    std::string type;
public:
    Job();
    virtual ~Job() = default;
    virtual void applyToPlayer(Player&);
    virtual int getCombatPower(Player&);
    virtual std::string getJob();
    virtual void doEclipse(Player&);
    virtual void afterFight(Player&);
};

class Archer : public Job {
public:
    Archer();
    void applyToPlayer(Player&) override;
};

class Magician : public Job {
public:
    Magician();
    void doEclipse(Player&) override;
};

class Warrior : public Job {
public:
    Warrior();
    void applyToPlayer(Player&) override;
    void afterFight(Player&) override;
    int getCombatPower(Player&) override;
};