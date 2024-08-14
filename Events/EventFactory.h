#ifndef EVENT_FACTORY_H
#define EVENT_FACTORY_H

#include <string>
#include <memory>
#include <unordered_map>
#include <functional>
#include <sstream>

// Forward declarations of Event classes
class Event;
class Monster;
class Balrog;
class SolarEclipse;
class PotionsMerchant;
class Pack;

class EventFactory {
public:
    // Factory method to create an Event object based on the eventLine string
    static std::unique_ptr<Event> createEvent(const std::string& eventLine);

private:
    // Helper function to parse and create a Pack event
    static std::unique_ptr<Event> parsePack(std::istringstream &stream);

    // Static map associating event names with their respective creation lambdas
    static const std::unordered_map<std::string, std::function<std::unique_ptr<Event>()>> eventCreators;
};

#endif // EVENT_FACTORY_H
