#include "monitor.h"

// Define boundaries with warning tolerance 1.5%
const Boundary tempBoundary = {95.0f, 102.0f, 1.5f};
const Boundary pulseBoundary = {60.0f, 100.0f, 1.5f};
const Boundary spo2Boundary = {90.0f, 100.0f, 1.5f};

// Messages for temperature
const std::map<Condition, std::string> tempMessages = {
    {Condition::LOW, "Hypothermia"},
    {Condition::LOW_WARNING, "Warning: Approaching hypothermia"},
    {Condition::NORMAL, "Normal"},
    {Condition::HIGH_WARNING, "Warning: Approaching hyperthermia"},
    {Condition::HIGH, "Hyperthermia"}
};

// Messages for pulse
const std::map<Condition, std::string> pulseMessages = {
    {Condition::LOW, "Bradycardia"},
    {Condition::LOW_WARNING, "Warning: Approaching bradycardia"},
    {Condition::NORMAL, "Normal"},
    {Condition::HIGH_WARNING, "Warning: Approaching tachycardia"},
    {Condition::HIGH, "Tachycardia"}
};

// Messages for spo2
const std::map<Condition, std::string> spo2Messages = {
    {Condition::LOW, "Hypoxia"},
    {Condition::LOW_WARNING, "Warning: Approaching hypoxia"},
    {Condition::NORMAL, "Normal"},
    {Condition::HIGH_WARNING, "Slightly high SPO2"},
    {Condition::HIGH, "Unusual SPO2 level"}
};

const std::map<std::string, const std::map<Condition, std::string>*> messagesMap = {
    {"temperature", &tempMessages},
    {"pulse", &pulseMessages},
    {"spo2", &spo2Messages}
};

const std::map<Condition, std::string>& getMessageMap(const std::string& vitalName) {
    auto it = messagesMap.find(vitalName);
    if (it != messagesMap.end())
        return *(it->second);
    return tempMessages; // fallback
}

std::string conditionToMessage(Condition condition, const std::string& vitalName) {
    const auto& mapRef = getMessageMap(vitalName);
    auto it = mapRef.find(condition);
    if (it != mapRef.end())
        return it->second;
    return "Unknown condition";
}
