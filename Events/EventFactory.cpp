#include <functional>
#include <map>
#include "EventFactory.h"

using std::string;
using std::istringstream;


std::unique_ptr<Event> createPack(std::istream&);


const std::map<std::string, std::function<std::unique_ptr<Event>(std::istream&)>> eventFactory = {
        {"SolarEclipse", [](std::istream&) {return std::make_unique<SolarEclipse>();}},
        {"PotionsMerchant", [](std::istream&) {return std::make_unique<PotionsMerchant>();}},
        {"Pack", [](std::istream& input) {return createPack(input);}},
        {"Snail", [](std::istream&) {return std::make_unique<Monster>("Snail", 5, 2, 10);}},
        {"Slime", [](std::istream&) {return std::make_unique<Monster>("Slime", 12, 5, 25);}},
        {"Balrog", [](std::istream&) {return std::make_unique<Balrog>();}}

};


std::unique_ptr<Event> createPack(std::istream& input){
    std::string word;
    int packSize;
    input >> word;
    try {
        packSize = std::stoi(word);
    } catch (...) {
        throw std::runtime_error("Invalid Events File");
    }
    std::vector<std::unique_ptr<Monster>> monsters;
    for (int i = 0; i < packSize; ++i) {
        std::string sub_event;
        input >> sub_event;
        std::unique_ptr<Event> eventPtr = EventFactory::generateEvent(sub_event, input);
        std::unique_ptr<Monster> monsterPtr(dynamic_cast<Monster*>(eventPtr.release()));
        monsters.push_back(std::move(monsterPtr));
    }
    auto monsterArray = std::make_unique<Monster[]>(monsters.size());
    for (size_t i = 0; i < monsters.size(); ++i) {
        monsterArray[i] = *monsters[i];
    }
    return std::make_unique<Pack>(monsterArray.get(), monsters.size());
}

auto getEventFactory(const std::map<std::string, std::function<std::unique_ptr<Event>(std::istream&)>>& map,
                                       const string& key){
    auto it = map.find(key);
    if(it == map.end()) {
        throw std::runtime_error(key + "not found");
    }
    return it->second;
}

std::unique_ptr<Event> EventFactory::generateEvent(const std::string& eventName, std::istream& input){
    return getEventFactory(eventFactory, eventName)(input);
}








/*
std::unique_ptr<Event> parsePack(istringstream &stream) {
    int packSize;
    try {
        stream >> packSize;
    } catch (...) {
        throw std::runtime_error("Invalid Events File");
    }
    std::vector<std::unique_ptr<Monster>> monsters;

    for (int i = 0; i < packSize; ++i) {
        std::string subEvent;
        stream >> subEvent;

        if (subEvent == "Pack") {
            auto subPack = parsePack(stream);
            monsters.push_back(std::unique_ptr<Monster>(
                    dynamic_cast<Pack *>(subPack.get())));
        } else if (subEvent == "Snail") {
            monsters.push_back(std::make_unique<Monster>("Snail", 5, 2, 10));
        } else if (subEvent == "Slime") {
            monsters.push_back(std::make_unique<Monster>("Slime", 12, 5, 25));
        } else if (subEvent == "Balrog") {
            monsters.push_back(std::make_unique<Balrog>());
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

std::unique_ptr<Event> EventFactory::createEvent(const std::string &eventLine) {
    istringstream stream(eventLine);
    string eventName;
    string tester;
    stream >> eventName;

    if (eventName == "Pack") {
        return parsePack(stream);
    }
    if (stream >> tester) {
        throw std::runtime_error("Invalid Events File");
    } else {
        if (eventName == "Slime") {
            return std::make_unique<Monster>("Slime", 12, 5, 25);
        } else if (eventName == "Snail") {
            return std::make_unique<Monster>("Snail", 5, 2, 10);
        } else if (eventName == "Balrog") {
            return std::make_unique<Balrog>();
        } else if (eventName == "SolarEclipse") {
            return std::make_unique<SolarEclipse>();
        } else if (eventName == "PotionsMerchant") {
            return std::make_unique<PotionsMerchant>();
        } else {
            throw std::runtime_error("Invalid Events File");
        }
    }
}*/
