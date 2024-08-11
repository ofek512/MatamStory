
#pragma once

#include "Character.h"
#include <string>


using std::string;

class Player {
protected:
    string Name;
    int Level;
    int Force;
    int Coins;
    int Current_HP;
    int Max_HP;
    Character *Character;

public:

    virtual void afterFight();

    bool operator<(const Player &other) const;

    Player(string Name, class Character *Character);
    /**
     * Gets the description of the player
     *
     * @return - description of the player
    */
    virtual string getJob() const;

    virtual string getDescription() const;

    void setLevel(int addition);
    /**
     * Gets the name of the player
     *
     * @return - name of the player
    */
    string getName() const;

    /**
     * Gets the current level of the player
     *
     * @return - level of the player
    */
    int getLevel() const;

    /**
     * Gets the of force the player has
     *
     * @return - force points of the player
    */
    int getForce() const;

    /**
     * Gets the amount of health points the player currently has
     *
     * @return - health points of the player
    */
    int getHealthPoints() const;

    /**
     * Gets the amount of coins the player has
     *
     * @return - coins of the player
    */
    int getCoins() const;

    virtual void doEclipse();

    virtual int getCombatPower() const;

    void setCoins(int);

    void setCurrent_HP(int);

    int getMax_HP() const;

    class Character *getCharacter();

    int setForce(int);
};
