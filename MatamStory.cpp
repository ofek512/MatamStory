#include "MatamStory.h"
#include "Utilities.h"

MatamStory::MatamStory(std::istream &eventsStream, std::istream &playersStream) {
    std::string eventLine;
    while (std::getline(eventsStream, eventLine)) {
        if (!eventLine.empty()) {
            events.push_back(EventFactory::createEvent(eventLine));
        }
    }

    std::string playerLine;
    while (std::getline(playersStream, playerLine)) {
        if (!playerLine.empty()) {
            std::istringstream iss(playerLine);
            std::string name, job, character;
            iss >> name >> job >> character;
            std::shared_ptr<Player> player = PlayerFactory::createPlayer(name, job, character);
            players.push_back(player);
            sortedPlayers.push_back(player);
        }
    }

    this->m_turnIndex = 1;
}

void MatamStory::playTurn(Player &player) {
    std::unique_ptr<Event> event = std::move(events.front());
    events.pop_front();
    printTurnDetails(m_turnIndex++, player, *event);
    event->runEvent(std::make_shared<Player>(player));
    events.push_back(std::move(event));
}

void MatamStory::playRound() {
    printRoundStart();

    for (auto it = players.begin(); it != players.end();) {
        playTurn(**it);
        if ((*it)->getHealthPoints() == 0) {
            it = players.erase(it);  // Erase returns the iterator to the next element
        } else {
            ++it;  // Move to the next element if not erased
        }
    }

    printRoundEnd();

    // Sort players by level, then by coins, then by name
    std::sort(sortedPlayers.begin(), sortedPlayers.end(), ComparePlayers);

    printLeaderBoardMessage();

    int counter = 1;
    for (const auto &sortedPlayer : sortedPlayers) {
        printLeaderBoardEntry(counter++, *sortedPlayer);
    }

    printBarrier();
}

bool MatamStory::isGameOver() const {
    return players.empty() || sortedPlayers.back()->getLevel() == 10;
}

void MatamStory::play() {
    printStartMessage();

    for (size_t i = 0; i < players.size(); ++i) {
        printStartPlayerEntry(i, *players[i]);
    }

    printBarrier();

    while (!isGameOver()) {
        playRound();
    }

    printGameOver();

    if (!sortedPlayers.empty() && sortedPlayers.back()->getLevel() == 10) {
        printWinner(*sortedPlayers.back());
    } else {
        printNoWinners();
    }
}

bool MatamStory::ComparePlayers(const std::shared_ptr<Player> &p1, const std::shared_ptr<Player> &p2) {
    if (p1->getLevel() != p2->getLevel()) {
        return p1->getLevel() > p2->getLevel();  // Compare levels in descending order
    } else if (p1->getCoins() != p2->getCoins()) {
        return p1->getCoins() > p2->getCoins();  // Compare coins in descending order
    }
    return p1->getName() < p2->getName();  // Lexicographical comparison of names in ascending order
}
