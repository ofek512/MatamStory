#include <functional>
#include <map>
#include "EventFactory.h"

using std::string;
using std::istringstream;


std::unique_ptr<Event> createPack(std::istream &);


const std::map<std::string, std::function<std::unique_ptr<Event>(
        std::istream &)>> eventFactory = {
        {"SolarEclipse",    [](
                std::istream &) { return std::make_unique<SolarEclipse>(); }},
        {"PotionsMerchant", [](
                std::istream &) { return std::make_unique<PotionsMerchant>(); }},
        {"Pack",            [](std::istream &input) {
            return createPack(input);
        }},
        {"Snail",           [](std::istream &) {
            return std::make_unique<Monster>("Snail", 5, 2, 10);
        }},
        {"Slime",           [](std::istream &) {
            return std::make_unique<Monster>("Slime", 12, 5, 25);
        }},
        {"Balrog",          [](
                std::istream &) { return std::make_unique<Balrog>(); }}

};

std::unique_ptr<Event> createPack(std::istream &input) {
    std::string word;
    int packSize;
    input >> word;
    try {
        packSize = std::stoi(word);
    } catch (...) {
        throw std::runtime_error("Invalid Events File");
    }

    // Create a vector to hold the unique pointers to Monster objects
    std::vector<std::unique_ptr<Monster>> monsters;
    for (int i = 0; i < packSize; ++i) {
        std::string sub_event;
        input >> sub_event;

        // Generate the event
        std::unique_ptr<Event> eventPtr = EventFactory::generateEvent(sub_event,
                                                                      input);

        // Try to cast the Event pointer to a Monster pointer
        Monster *monsterPtr = dynamic_cast<Monster *>(eventPtr.get());
        if (monsterPtr == nullptr) {
            throw std::runtime_error("Event is not a Monster");
        }

        // Transfer ownership to a new std::unique_ptr<Monster>
        monsters.push_back(std::unique_ptr<Monster>(monsterPtr));

        // Release the event pointer to avoid double deletion
        eventPtr.release();
    }

    // Return a Pack object with the vector of Monster pointers
    return std::make_unique<Pack>(std::move(monsters));
}


auto getEventFactory(
        const std::map<std::string, std::function<std::unique_ptr<Event>(
                std::istream &)>> &map,
        const string &key) {
    auto it = map.find(key);
    if (it == map.end()) {
        throw std::runtime_error("Invalid Events File");
    }
    return it->second;
}

std::unique_ptr<Event>
EventFactory::generateEvent(const std::string &eventName, std::istream &input) {
    return getEventFactory(eventFactory, eventName)(input);
}

