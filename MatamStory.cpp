#include "MatamStory.h"
#include "Utilities.h"
#include <iostream>
#include <sstream>
#include <stdexcept>

MatamStory::MatamStory(std::istream &eventsStream,
                       std::istream &playersStream) {
    std::string eventLine;
    if (eventsStream.peek() == std::istream::traits_type::eof()) {
        throw std::runtime_error("Invalid Events File");
    }
    if (eventsStream.peek() == std::istream::traits_type::eof()) {
        throw std::runtime_error("Invalid Players File");
    }
    while (std::getline(eventsStream, eventLine)) {
        if (!eventLine.empty()) {
            auto event = EventFactory::createEvent(eventLine);
            if (event) {
                events.push_back(std::move(event));
            } else {
                throw std::runtime_error("Invalid Events File");
            }
        }
    }

    std::string playerLine;
    while (std::getline(playersStream, playerLine)) {
        if (!playerLine.empty()) {
            std::istringstream iss(playerLine);
            std::string name, job, character;
            if (!(iss >> name >> job >> character)) {
                throw std::runtime_error(
                        "Invalid Players File");
            }
            try {
                auto player = PlayerFactory::createPlayer(name, job, character);
                if (player) {
                    players.push_back(std::move(player));
                    sortedPlayers.push_back(players.back());
                } else {
                    throw std::runtime_error(
                            "Invalid Players File");
                }
            } catch (const std::runtime_error &e) {
                throw std::runtime_error("Invalid Players File");
            }
        }
    }

    this->m_turnIndex = 1;
}

void MatamStory::playTurn(std::shared_ptr<Player> player) {
    auto event = std::move(events.front());
    events.pop_front();
    printTurnDetails(m_turnIndex++, *player, *event);
    event->runEvent(player);
    events.push_back(std::move(event));
}

void MatamStory::playRound() {
    printRoundStart();

    for (auto it = players.begin(); it != players.end();) {
        playTurn(*it);
        if ((*it)->getHealthPoints() <=
            0) {  // Ensure health is <= 0 to remove the player
            it = players.erase(
                    it);  // Erase returns the iterator to the next element
        } else {
            ++it;  // Move to the next element if not erased
        }
    }

    printRoundEnd();

    // Sort players by level, then by coins, then by name
    std::sort(sortedPlayers.begin(), sortedPlayers.end(), ComparePlayers);

    printLeaderBoardMessage();

    int counter = 1;
    for (const auto &sortedPlayer: sortedPlayers) {
        printLeaderBoardEntry(counter++, *sortedPlayer);
    }

    printBarrier();
}

bool MatamStory::isGameOver() const {
    return players.empty() || sortedPlayers.back()->getLevel() >=
                              10;  // Use >= for inclusive check
}

void MatamStory::play() {
    printStartMessage();

    for (size_t i = 0; i < players.size(); ++i) {
        printStartPlayerEntry(i + 1, *players[i]);
    }

    printBarrier();

    while (!isGameOver()) {
        playRound();
    }

    printGameOver();

    if (!sortedPlayers.empty() &&
        sortedPlayers.back()->getLevel() >= 10) {  // Use >= for inclusive check
        printWinner(*sortedPlayers.back());
    } else {
        printNoWinners();
    }
}

bool MatamStory::ComparePlayers(const std::shared_ptr<Player> &p1,
                                const std::shared_ptr<Player> &p2) {
    if (p1->getLevel() != p2->getLevel()) {
        return p1->getLevel() >
               p2->getLevel();  // Compare levels in descending order
    } else if (p1->getCoins() != p2->getCoins()) {
        return p1->getCoins() >
               p2->getCoins();  // Compare coins in descending order
    }
    return p1->getName() <
           p2->getName();  // Lexicographical comparison of names in ascending order
}
