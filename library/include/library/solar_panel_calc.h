#pragma once

#include <cstdint>
#include <tuple>

namespace solar_panel_calc {
struct Result {
  uint64_t battery_count;
  uint64_t solar_panel_count;
  uint64_t solar_panel_area;
};

bool operator==(const Result& lhs, const Result& rhs);

// daily_cons accepts any value
// sun_hours accepts value from 1 to 24 otherwise throws std::range_error
Result calc_solar_system_reqs(const uint64_t daily_cons,
                              const uint64_t sun_hours);
}  // namespace solar_panel_calc
