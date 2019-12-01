#include "solar_panel_calc.h"

#include <cmath>
#include <stdexcept>

namespace {
const uint64_t kBatteryCapacityAH = 26;
const uint64_t kBatteryVoltage = 12;
const uint64_t kBatteryCapacityWatt = kBatteryCapacityAH * kBatteryVoltage;

const uint64_t kPanelCapacity = 250;
const uint64_t kSqMetersForPanel = 2;

const uint64_t kHoursPerDay = 24;
}  // namespace

namespace solar_panel_calc {
bool operator==(const Result& lhs, const Result& rhs) {
  return (lhs.battery_count == rhs.battery_count) &&
         (lhs.solar_panel_count == rhs.solar_panel_count) &&
         (lhs.solar_panel_area == rhs.solar_panel_area);
}

Result calc_solar_system_reqs(const uint64_t daily_cons,
                              const uint64_t sun_hours) {
  if ((0 == sun_hours) || (kHoursPerDay < sun_hours)) {
    throw std::range_error("Sun hours is invalid");
  }

  Result answer{};

  answer.battery_count =
      std::ceil(static_cast<double>(daily_cons) / kBatteryCapacityWatt);

  answer.solar_panel_count =
      std::ceil(static_cast<double>(daily_cons) / (kPanelCapacity * sun_hours));

  answer.solar_panel_area = answer.solar_panel_count * kSqMetersForPanel;

  return answer;
}

}  // namespace solar_panel_calc

