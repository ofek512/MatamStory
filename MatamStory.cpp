
#include "MatamStory.h"
#include "Utilities.h"

using std::make_unique;

unique_ptr<Event> createEvent(const std::string &eventName) {
    if (eventName == "Snail") {
        return make_unique<Snail>();
    } else if (eventName == "Slime") {
        return make_unique<Slime>();
    } else if (eventName == "Pack") {
        //need to create logic for pack creation
    } else if (eventName == "Balrog") {
        return make_unique<Balrog>();
    } else if (eventName == "SolarEclipse") {
        return make_unique<SolarEclipse>();
    } else if (eventName == "PotionsMerchant") {
        return make_unique<PotionsMerchant>();
    } else {
        throw std::runtime_error("Unknown event type: " + eventName);
    }
}

MatamStory::MatamStory(std::istream &eventsStream,
                       std::istream &playersStream) {

    /*===== TODO: Open and read events file =====*/
    string eventName;
    while (std::getline(eventsStream, eventName)) {
        if (!eventName.empty()) {
            events.push_back(createEvent(eventName));
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
