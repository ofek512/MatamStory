#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <memory>
#include <string>
#include <sstream>
#include <algorithm>
#include "Players/Player.h"
#include "Events/Event.h"
#include "PlayerFactory.h"
#include "EventFactory.h"

class MatamStory {
private:
 unsigned int m_turnIndex;
 std::vector<std::shared_ptr<Player>> players;
 std::vector<std::shared_ptr<Player>> sortedPlayers;
 std::list<std::unique_ptr<Event>> events;

 /**
  * Plays a single turn for a player
  *
  * @param player - the player to play the turn for
  */
 void playTurn(Player &player);

 /**
  * Plays a single round of the game
  */
 void playRound();

 /**
  * Checks if the game is over
  *
  * @return true if the game is over, false otherwise
  */
 bool isGameOver() const;

public:
 /**
  * Constructor of MatamStory class
  *
  * @param eventsStream - events input stream (file)
  * @param playersStream - players input stream (file)
  */
 MatamStory(std::istream &eventsStream, std::istream &playersStream);

 /**
  * Plays the entire game
  */
 void play();

 /**
  * Compares two players to sort them for the leaderboard
  *
  * @param p1 - first player
  * @param p2 - second player
  * @return true if p1 should be before p2
  */
 static bool ComparePlayers(const std::shared_ptr<Player> &p1, const std::shared_ptr<Player> &p2);
};

