#ifndef MONITOR_H
#define MONITOR_H

#include "vitals.h"
#include <string>
#include <map>

extern const Boundary tempBoundary;
extern const Boundary pulseBoundary;
extern const Boundary spo2Boundary;

// Map Condition enums to messages for each vital sign
const std::map<Condition, std::string>& getMessageMap(const std::string& vitalName);

// Helper to get message string given condition and boundary for the vital
std::string conditionToMessage(Condition condition, const std::string& vitalName);

#endif



