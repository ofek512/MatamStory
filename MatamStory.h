
#pragma once

#include "Monster.h"
#include "Balrog.h"
#include "Encounter.h"
#include "SolarEclipse.h"
#include "SpecialEvent.h"
#include "PotionsMerchant.h"
#include "Pack.h"
#include <iostream>
#include <vector>
#include <list>
#include "Players/Player.h"
#include "Warrior.h"
#include "Magician.h"
#include "Archer.h"
#include "Character.h"
#include "Events/Event.h"
#include <memory>
#include <sstream>
#include <string>
#include "Utilities.h"

using std::shared_ptr;
using std::vector;
using std::list;
using std::unique_ptr;

struct ComparePlayers {
    bool operator()(const std::shared_ptr<Player> &p1,
                    const std::shared_ptr<Player> &p2) const {
        if (p1->getLevel() != p2->getLevel()) {
            return p1->getLevel() >
                   p2->getLevel();  // Compare levels in descending order
        } else if (p1->getCoins() != p2->getCoins()) {
            return p1->getCoins() > p2->getCoins();
        }
        return p1->getName() >
               p2->getName();  // Lexicographical comparison of names in reverse order
    }
};

class MatamStory {
private:
    unsigned int m_turnIndex;
    vector<shared_ptr<Player>> players;
    vector<shared_ptr<Player>> sortedPlayers;
    list<unique_ptr<Event>> events;
    /**
     * Playes a single turn for a player
     *
     * @param player - the player to play the turn for
     *
     * @return - void
    */
    void playTurn(Player &player);

    /**
     * Plays a single round of the game
     *
     * @return - void
    */
    void playRound();

    /**
     * Checks if the game is over
     *
     * @return - true if the game is over, false otherwise
    */
    bool isGameOver() const;

public:
    static unique_ptr<Event> createEvent(
            const string &); //reads from event txt file and transforms to a vector
    static shared_ptr<Player> createPlayer(const string &);
    static bool isRisk(string &character);
    /**
     * Constructor of MatamStory class
     *
     * @param eventsStream - events input stream (file)
     * @param playersStream - players input stream (file)
     *
     * @return - MatamStory object with the given events and players
     *
    */
    MatamStory(std::istream &eventsStream, std::istream &playersStream);
    static unique_ptr<Event> parsePack(std::istringstream &stream);
    /**
     * Plays the entire game
     *
     * @return - void
    */
    void play();
};
