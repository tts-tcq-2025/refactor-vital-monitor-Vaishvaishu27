#include "./monitor.h"
#include <iostream>
#include <thread>
#include <chrono>

using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds;

// Pure function: checks vitals and returns status
VitalStatus checkVitals(float temperature, float pulseRate, float spo2) {
  if (temperature > 102 || temperature < 95) {
    return TEMP_CRITICAL;
  }
  if (pulseRate < 60 || pulseRate > 100) {
    return PULSE_CRITICAL;
  }
  if (spo2 < 90) {
    return SPO2_CRITICAL;
  }
  return OK;
}

// I/O function: handles alert animation
void showAlert(const std::string& message) {
  cout << message << "\n";
  for (int i = 0; i < 6; ++i) {
    cout << "\r* " << flush;
    sleep_for(seconds(1));
    cout << "\r *" << flush;
    sleep_for(seconds(1));
  }
}

// Main function: combines logic and I/O
int vitalsOk(float temperature, float pulseRate, float spo2) {
  VitalStatus status = checkVitals(temperature, pulseRate, spo2);
  switch (status) {
    case TEMP_CRITICAL:
      showAlert("Temperature is critical!");
      return 0;
    case PULSE_CRITICAL:
      showAlert("Pulse Rate is out of range!");
      return 0;
    case SPO2_CRITICAL:
      showAlert("Oxygen Saturation out of range!");
      return 0;
    case OK:
      return 1;
  }
  return 1; // fallback
}
