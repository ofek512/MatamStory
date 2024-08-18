#include "PlayerFactory.h"
#include <map>
#include <functional>
#include <iostream>


const std::map<std::string, std::function<std::shared_ptr<Job>()>> jobFactory = {
        {"Warrior",  []() { return std::make_shared<Warrior>(); }},
        {"Archer",   []() { return std::make_shared<Archer>(); }},
        {"Magician", []() { return std::make_shared<Magician>(); }}
};

const std::map<std::string, std::function<std::shared_ptr<Character>()>> characterFactory = {
        {"Responsible", []() { return std::make_shared<Responsible>(); }},
        {"RiskTaking",  []() { return std::make_shared<RiskTaker>(); }}
};

auto getCharacterFactory(
        const std::map<std::string, std::function<std::shared_ptr<Character>()>> &map,
        const string &key) {
    auto it = map.find(key);
    if (it == map.end()) {
        throw std::runtime_error(key + "not found");
    }
    return it->second;
}

std::function<std::shared_ptr<Job>()> getJobFactory(
        const std::map<std::string, std::function<std::shared_ptr<Job>()>> &map,
        const string &key) {
    auto it = map.find(key);
    if (it == map.end()) {
        throw std::runtime_error("Invalid Player File");
    }
    return it->second;
}

std::shared_ptr<Job> PlayerFactory::generateJob(const std::string &jobName) {
    return getJobFactory(jobFactory, jobName)();
}

std::shared_ptr<Character>
PlayerFactory::generateCharacter(const std::string &characterName) {
    return getCharacterFactory(characterFactory, characterName)();
}


