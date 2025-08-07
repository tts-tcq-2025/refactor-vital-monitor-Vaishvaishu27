#include <gtest/gtest.h>
#include "./monitor.h"

TEST(Monitor, NotOkWhenAnyVitalIsOffRange) {
  ASSERT_FALSE(vitalsOk(99, 102, 70));  // Pulse high, SpO2 low
  ASSERT_TRUE(vitalsOk(98.1, 70, 98));  // All normal
}

TEST(Monitor, TemperatureOutOfRange) {
  ASSERT_EQ(checkVitals(103, 80, 95), TEMP_CRITICAL);
  ASSERT_EQ(checkVitals(94, 80, 95), TEMP_CRITICAL);
}

TEST(Monitor, PulseRateOutOfRange) {
  ASSERT_EQ(checkVitals(98.6, 55, 95), PULSE_CRITICAL);
  ASSERT_EQ(checkVitals(98.6, 105, 95), PULSE_CRITICAL);
}

TEST(Monitor, SpO2OutOfRange) {
  ASSERT_EQ(checkVitals(98.6, 75, 85), SPO2_CRITICAL);
}

TEST(Monitor, AllVitalsNormal) {
  ASSERT_EQ(checkVitals(98.6, 75, 95), OK);
}
