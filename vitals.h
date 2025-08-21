#ifndef VITALS_H
#define VITALS_H

#include <string>
#include <vector>

enum class Condition {
    LOW,
    LOW_WARNING,
    NORMAL,
    HIGH_WARNING,
    HIGH
};

struct Boundary {
    float min;
    float max;
    float warningTolerancePercent;
};

struct VitalsResult {
    Condition temp;
    Condition pulse;
    Condition spo2;
};

// Evaluates a single vital based on value and its boundary limits
Condition evaluateVital(float value, const Boundary& boundary);

// Evaluate all vitals and return conditions
VitalsResult evaluateVitals(float temperature, float pulse, float spo2,
                            const Boundary& tempBoundary,
                            const Boundary& pulseBoundary,
                            const Boundary& spo2Boundary);

// Returns true if all vitals are in NORMAL or WARNING zones (no HIGH or LOW critical)
bool overallVitalsOk(const Condition temp, const Condition pulse, const Condition spo2);

#endif
