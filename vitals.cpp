#include "vitals.h"

Condition evaluateVital(float value, const Boundary& boundary) {
    float tolerance = boundary.max * (boundary.warningTolerancePercent / 100.0f);
    float lowWarningMax = boundary.min + tolerance;
    float highWarningMin = boundary.max - tolerance;

    if (value <= boundary.min) return Condition::LOW;
    if (value > boundary.min && value <= lowWarningMax) return Condition::LOW_WARNING;
    if (value > lowWarningMax && value < highWarningMin) return Condition::NORMAL;
    if (value >= highWarningMin && value < boundary.max) return Condition::HIGH_WARNING;
    return Condition::HIGH;
}

VitalsResult evaluateVitals(float temperature, float pulse, float spo2,
                            const Boundary& tempBoundary,
                            const Boundary& pulseBoundary,
                            const Boundary& spo2Boundary) {
    return {
        evaluateVital(temperature, tempBoundary),
        evaluateVital(pulse, pulseBoundary),
        evaluateVital(spo2, spo2Boundary)
    };
}

bool overallVitalsOk(const Condition temp, const Condition pulse, const Condition spo2) {
    auto isOk = [](Condition c) {
        return c == Condition::NORMAL || c == Condition::LOW_WARNING || c == Condition::HIGH_WARNING;
    };
    return isOk(temp) && isOk(pulse) && isOk(spo2);
}
