#pragma once

#include <string>
#include <memory>

class Character;  // Forward declaration to avoid circular dependency

using std::string;
using std::shared_ptr;

class Player {
protected:
 string Name;
 int Level;
 int Force;
 int Coins;
 int Current_HP;
 int Max_HP;
 shared_ptr<Character> character;  // Use smart pointer to manage Character

public:
 Player(string Name, shared_ptr<Character> character);

 virtual ~Player() = default;  // Virtual destructor to ensure proper cleanup
 virtual void afterFight();
 bool operator<(const Player &other) const;

 virtual string getJob() const;
 virtual string getDescription() const;

 void buyPotion();

 void setLevel(int addition);
 string getName() const;
 int getLevel() const;
 int getForce() const;
 int getHealthPoints() const;
 int getCoins() const;

 virtual void doEclipse();
 virtual int getCombatPower() const;

 void setCoins(int);
 void setCurrent_HP(int);
 int getMax_HP() const;
 shared_ptr<Character> getCharacter();
 void setForce(int);
};
