#include "EventFactory.h"


std::unique_ptr<Event> parsePack(std::istringstream &stream) {
    int packSize;
    stream >> packSize;

    std::vector<std::unique_ptr<Monster>> monsters;

    for (int i = 0; i < packSize; ++i) {
        std::string subEvent;
        stream >> subEvent;

        if (subEvent == "Pack") {
            auto subPack = parsePack(stream);
            monsters.push_back(std::unique_ptr<Monster>(
                    dynamic_cast<Pack*>(subPack.get())));
        } else if (subEvent == "Snail") {
            monsters.push_back(std::make_unique<Monster>("Snail", 5, 2, 10));
        } else if (subEvent == "Slime") {
            monsters.push_back(std::make_unique<Monster>("Slime", 12, 5, 25));
        } else if (subEvent == "Balrog") {
            monsters.push_back(std::make_unique<Balrog>());
        } else {
            throw std::runtime_error("Unknown monster type in pack: " + subEvent);
        }
    }

    auto monsterArray = std::make_unique<Monster[]>(monsters.size());
    for (size_t i = 0; i < monsters.size(); ++i) {
        monsterArray[i] = *monsters[i];
    }

    return std::make_unique<Pack>(monsterArray.get(), monsters.size());
}

std::unique_ptr<Event> EventFactory::createEvent(const std::string& eventLine) {
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
