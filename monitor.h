
#pragma once

// Function declaration
int vitalsOk(float temperature, float pulseRate, float spo2);

// Enum to represent vital status
enum VitalStatus {
  OK,
  TEMP_CRITICAL,
  PULSE_CRITICAL,
  SPO2_CRITICAL
};

// Pure function to check vitals
VitalStatus checkVitals(float temperature, float pulseRate, float spo2);

// Alert function for I/O
void showAlert(const std::string& message);

