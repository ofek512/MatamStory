#include "MatamStory.h"

using std::string;
using std::make_unique;

unique_ptr<Event> MatamStory::parsePack(std::istringstream &stream) {
    int packSize;
    stream >> packSize; // Read the size of the pack

    std::vector<std::unique_ptr<Monster>> monsters;

    for (int i = 0; i < packSize; ++i) {
        std::string subEvent;
        stream >> subEvent;

        if (subEvent == "Pack") {
            // Recursively parse the nested pack
            auto subPack = parsePack(stream);
            // Convert subPack to Pack and manage it as Monster
            monsters.push_back(std::unique_ptr<Monster>(
                    dynamic_cast<Pack *>(subPack.get())));
        } else if (subEvent == "Snail") {
            monsters.push_back(std::make_unique<Monster>("Snail", 5, 2, 10));
        } else if (subEvent == "Slime") {
            monsters.push_back(std::make_unique<Monster>("Slime", 12, 5, 25));
        } else if (subEvent == "Balrog") {
            monsters.push_back(std::make_unique<Balrog>());
        } else {
            throw std::runtime_error(
                    "Unknown monster type in pack: " + subEvent);
        }
    }

    // Create a dynamic array of monsters for the Pack constructor
    auto monsterArray = std::make_unique<Monster[]>(monsters.size());
    for (size_t i = 0; i < monsters.size(); ++i) {
        monsterArray[i] = *monsters[i];
    }

    // Return the new Pack as a unique_ptr<Event>
    return std::make_unique<Pack>(monsterArray.get(), monsters.size());
}

unique_ptr<Event> MatamStory::createEvent(const std::string &eventLine) {
    std::istringstream stream(eventLine);
    std::string eventName;
    stream >> eventName;

    if (eventName == "Snail") {
        return std::make_unique<Monster>("Snail", 5, 2, 10);
    } else if (eventName == "Slime") {
        return std::make_unique<Monster>("Slime", 12, 5, 25);
    } else if (eventName == "Pack") {
        return parsePack(stream);
    } else if (eventName == "Balrog") {
        return std::make_unique<Balrog>();
    } else if (eventName == "SolarEclipse") {
        return std::make_unique<SolarEclipse>();
    } else if (eventName == "PotionsMerchant") {
        return std::make_unique<PotionsMerchant>();
    } else {
        throw std::runtime_error("Unknown event type: " + eventName);
    }
}

/* TODO: get this shit out of this file */
shared_ptr<Player> MatamStory::createPlayer(const std::string &playerLine) {
    string name, job, character;
    std::istringstream iss(playerLine);
    iss >> name >> job >> character;
    if (job == "Warrior") {
        if (isRisk(character)) {
            RiskTaker riskTaker;
            return std::make_shared<Warrior>(name, &riskTaker);
        } else {
            Responsible responsible;
            return std::make_shared<Warrior>(name, &responsible);
        }
    } else if (job == "Archer") {
        if (isRisk(character)) {
            RiskTaker riskTaker;
            return std::make_shared<Archer>(name, &riskTaker);
        } else {
            Responsible responsible;
            return std::make_shared<Archer>(name, &responsible);
        }

    } else if (job == "Magician") {
        if (isRisk(character)) {
            RiskTaker riskTaker;
            return std::make_unique<Magician>(name, &riskTaker);
        } else {
            Responsible responsible;
            return std::make_unique<Magician>(name, &responsible);
        }
    }
    throw;
}

MatamStory::MatamStory(std::istream &eventsStream,
                       std::istream &playersStream) {

    /*===== TODO: Open and read events file =====*/
    string eventLine;
    while (std::getline(eventsStream, eventLine)) {
        if (!eventLine.empty()) {
            events.push_back(createEvent(eventLine));
        }
    }
    /*==========================================*/


    /*===== TODO: Open and Read players file =====*/
    string playerLine;
    while (std::getline(playersStream, playerLine)) {
        if (!playerLine.empty()) {
            shared_ptr<Player> player = createPlayer(playerLine);
            players.push_back(player);
            sortedPlayers.push_back(player);

        }
    }
    /*============================================*/


    this->m_turnIndex = 1;
}

void MatamStory::playTurn(Player &player) {
    unique_ptr<Event> event = std::move(events.front());
    events.pop_front();
    printTurnDetails(m_turnIndex++, player, *event);
    shared_ptr<Player> playerPtr = std::make_shared<Player>(player);
    event->runEvent(playerPtr);
    events.push_back(std::move(event));
}

void MatamStory::playRound() {
    printRoundStart();
    /*===== TODO: Play a turn for each player =====*/
    for (auto it = players.begin(); it != players.end();) {
        playTurn(**it);
        if ((*it)->getHealthPoints() == 0) {
            it = players.erase(
                    it);  // Erase returns the iterator to the next element
        } else {
            ++it;  // Move to the next element if not erased
        }
    }
    /*=============================================*/

    printRoundEnd();

    sort(sortedPlayers.begin(),sortedPlayers.end(), ComparePlayers);


    printLeaderBoardMessage();

    /*===== TODO: Print leaderboard entry for each player using "printLeaderBoardEntry" =====*/
    int counter = 1;
    for(auto & sortedPlayer : sortedPlayers){
        printLeaderBoardEntry(counter++, *sortedPlayer);
    }
    /*=======================================================================================*/

    printBarrier();
}

bool MatamStory::isGameOver() const {
    if(players.empty() || sortedPlayers.back()->getLevel() == 10)
        return true;
    /*===== TODO: Implement the game over condition =====*/
    return false; // Replace this line
    /*===================================================*/
}

void MatamStory::play() {
    printStartMessage();
    /*===== TODO: Print start message entry for each player using "printStartPlayerEntry" =====*/
    for (int i = 0; i < int(players.size()); ++i) {
        printStartPlayerEntry(i, *players[i]);
    }
    /*=========================================================================================*/
    printBarrier();

    while (!isGameOver()) {
        playRound();
    }

    printGameOver();
    /*===== TODO: Print either a "winner" message or "no winner" message =====*/
    if(sortedPlayers.back()->getLevel() == 10){
        printWinner(*sortedPlayers.back());
    } else {
        printNoWinners();
    }
    /*========================================================================*/
}

bool MatamStory::isRisk(string &character) {
    if (character == "RiskTaking") {
        return true;
    }
    return false;
}

bool MatamStory::ComparePlayers(const std::shared_ptr<Player> &p1,
                    const std::shared_ptr<Player> &p2) {
    if (p1->getLevel() != p2->getLevel()) {
        return p1->getLevel() >
               p2->getLevel();  // Compare levels in descending order
    } else if (p1->getCoins() != p2->getCoins()) {
        return p1->getCoins() > p2->getCoins();
    }
    return p1->getName() >
           p2->getName();  // Lexicographical comparison of names in reverse order
}
