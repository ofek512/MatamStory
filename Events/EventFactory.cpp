#include "EventFactory.h"

#include <Balrog.h>
#include <sstream>
#include <stdexcept>
#include <unordered_map>
#include <memory>
#include <Pack.h>
#include <PotionsMerchant.h>
#include <SolarEclipse.h>

std::unique_ptr<Event> EventFactory::createEvent(const std::string& eventLine) {
    std::istringstream stream(eventLine);
    std::string eventName;
    stream >> eventName;

    // Create a map of event names to lambda expressions that create the events
    static const std::unordered_map<std::string, std::function<std::unique_ptr<Event>()>> eventCreators = {
        {"Snail", []() { return std::make_unique<Monster>("Snail", 5, 2, 10); }},
        {"Slime", []() { return std::make_unique<Monster>("Snail", 12, 5, 25); }},
        {"Balrog", []() { return std::make_unique<Balrog>(); }},
        {"SolarEclipse", []() { return std::make_unique<SolarEclipse>(); }},
        {"PotionsMerchant", []() { return std::make_unique<PotionsMerchant>(); }}
    };

    auto it = eventCreators.find(eventName);
    if (it != eventCreators.end()) {
        return it->second();  // Call the lambda to create the event
    } else if (eventName == "Pack") {
        return parsePack(stream);  // Special handling for Pack
    } else {
        throw std::runtime_error("Invalid Events File");
    }
}

std::unique_ptr<Event> EventFactory::parsePack(std::istringstream &stream) {
    int packSize;
    stream >> packSize;
    std::vector<std::unique_ptr<Monster>> monsters;

    for (int i = 0; i < packSize; ++i) {
        std::string subEvent;
        stream >> subEvent;

        static const std::unordered_map<std::string, std::function<std::unique_ptr<Event>()>> eventCreators = {
            {"Monster", []() { return std::make_unique<Monster>(); }},
            {"Balrog", []() { return std::make_unique<Balrog>(); }},
            {"SolarEclipse", []() { return std::make_unique<SolarEclipse>(); }},
            {"PotionsMerchant", []() { return std::make_unique<PotionsMerchant>(); }}
        };

        auto it = eventCreators.find(subEvent);
        if (it != eventCreators.end()) {
            auto event = it->second();
            auto monster = dynamic_cast<Monster*>(event.get());

            if (monster) {
                monsters.push_back(std::make_unique<Monster>(*monster));
            } else {
                throw std::runtime_error("Invalid Events File");
            }
        } else {
            throw std::runtime_error("Invalid Events File");
        }
    }

    auto monsterArray = std::make_unique<Monster[]>(monsters.size());
    for (size_t i = 0; i < monsters.size(); ++i) {
        monsterArray[i] = *monsters[i];
    }

    return std::make_unique<Pack>(monsterArray.get(), monsters.size());
}
