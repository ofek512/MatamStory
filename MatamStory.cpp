
#include "MatamStory.h"
#include "Utilities.h"

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

    /*============================================*/


    this->m_turnIndex = 1;
}

void MatamStory::playTurn(Player &player) {

    /**
     * Steps to implement (there may be more, depending on your design):
     * 1. Get the next event from the events list
     * 2. Print the turn details with "printTurnDetails"
     * 3. Play the event
     * 4. Print the turn outcome with "printTurnOutcome"
    */

    m_turnIndex++;
}

void MatamStory::playRound() {

    printRoundStart();

    /*===== TODO: Play a turn for each player =====*/

    /*=============================================*/

    printRoundEnd();

    printLeaderBoardMessage();

    /*===== TODO: Print leaderboard entry for each player using "printLeaderBoardEntry" =====*/

    /*=======================================================================================*/

    printBarrier();
}

bool MatamStory::isGameOver() const {
    /*===== TODO: Implement the game over condition =====*/
    return false; // Replace this line
    /*===================================================*/
}

void MatamStory::play() {
    printStartMessage();
    /*===== TODO: Print start message entry for each player using "printStartPlayerEntry" =====*/

    /*=========================================================================================*/
    printBarrier();

    while (!isGameOver()) {
        playRound();
    }

    printGameOver();
    /*===== TODO: Print either a "winner" message or "no winner" message =====*/

    /*========================================================================*/
}

