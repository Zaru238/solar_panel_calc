#include <gtest/gtest.h>
#include <library/solar_panel_calc.h>

#include <array>
#include <cstdint>
#include <stdexcept>

namespace {
struct SolarCalcInOut {
  uint64_t day_consumption_in;
  uint64_t sun_day_in;
  solar_panel_calc::Result out;
};
};  // namespace

class RightUsageTest : public ::testing::TestWithParam<SolarCalcInOut> {};

TEST_P(RightUsageTest, CheckConversion) {
  const auto data = GetParam();

  const auto result = solar_panel_calc::calc_solar_system_reqs(
      data.day_consumption_in, data.sun_day_in);

  ASSERT_EQ(result, data.out);
}

const std::array<SolarCalcInOut, 4> kData = {{
    {1000, 5, {4, 1, 2}},
    {2000, 20, {7, 1, 2}},
    {10000, 1, {33, 40, 80}},
    {0, 10, {0, 0, 0}},
}};

INSTANTIATE_TEST_CASE_P(DefaultTestSuite, RightUsageTest,
                        ::testing::ValuesIn(kData));

TEST(SolarPanelCalc, IncorrectUsage) {
  const auto daily_consumption = 1000u;
  const auto incorrect_sun_hours = 30;

  ASSERT_THROW(solar_panel_calc::calc_solar_system_reqs(daily_consumption,
                                                        incorrect_sun_hours),
               std::range_error);
}

