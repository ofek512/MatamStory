
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
#include "Events/Event.h"
#include <memory>
#include <sstream>
#include <string>

using std::vector;
using std::list;
using std::unique_ptr;

class MatamStory {
private:
    unsigned int m_turnIndex;
    list<unique_ptr<Player>> players;
    vector<unique_ptr<Event>> events;
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
    unique_ptr<Event> createEvent(
            const string &); //reads from event txt file and transforms to a vector
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
