#include <iostream>
#include "vitals.h"
#include "monitor.h"

// Helper to print all vitals messages and overall status
void printVitalsResult(const VitalsResult& result) {
    std::cout << "Temperature: " << conditionToMessage(result.temp, "temperature") << std::endl;
    std::cout << "Pulse: " << conditionToMessage(result.pulse, "pulse") << std::endl;
    std::cout << "SpO2: " << conditionToMessage(result.spo2, "spo2") << std::endl;

    if (overallVitalsOk(result.temp, result.pulse, result.spo2))
        std::cout << "Vitals OK" << std::endl;
    else
        std::cout << "Vitals NOT OK" << std::endl;
}

int main() {
    // Example inputs, can be replaced with actual sensor input
    float temperature = 95.0f;
    float pulse = 60.0f;
    float spo2 = 90.0f;

    VitalsResult result = evaluateVitals(temperature, pulse, spo2,
                                         tempBoundary,
                                         pulseBoundary,
                                         spo2Boundary);

    printVitalsResult(result);

    return 0;
}
