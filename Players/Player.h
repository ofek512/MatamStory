#pragma once

#include <string>
#include <memory>

class Character;  // Forward declaration to avoid circular dependency
class Job;

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
 shared_ptr<Job> job;

public:
 Player(string Name, shared_ptr<Character> character);
 Player(string Name, shared_ptr<Character>, shared_ptr<Job>);

 ~Player() = default;  // Virtual destructor to ensure proper cleanup
 void afterFight(); //to job
 bool operator<(const Player &other) const;

 string getJob() const; //to job
 string getDescription() const; //change

 void buyPotion();

 void setLevel(int addition);
 string getName() const;
 int getLevel() const;
 int getForce() const;
 int getHealthPoints() const;
 int getCoins() const;

 void doEclipse();
 int getCombatPower(); //to job

 void setCoins(int); //add to job
 void setCurrent_HP(int); //add to job
 int getMax_HP() const;
 shared_ptr<Character> getCharacter();
 void setForce(int);
 void setMaxHP(int);
};
