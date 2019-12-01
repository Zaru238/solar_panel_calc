#include <library/solar_panel_calc.h>

#include <cstring>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>

int main(int argc, char* argv[]) {
  try {
    if (3 != argc) {
      std::cerr << "Amount of arguments isn't equal 2" << std::endl;
      return 1;
    }

    std::size_t parsed_pos{};
    const auto daily_consumption = std::stoi(argv[1], &parsed_pos);
    if (strlen(argv[1]) > parsed_pos) {
      std::cerr << "Inavalid argument " << argv[1] << std::endl;
      return -1;
    }

    if (0 > daily_consumption) {
      std::cerr << "Invalid argument " << daily_consumption << std::endl;
      return -1;
    }

    const auto sun_hours = std::stoi(argv[2], &parsed_pos);
    if (strlen(argv[2]) > parsed_pos) {
      std::cerr << "Inavalid argument " << argv[2] << std::endl;
      return -1;
    }

    if (0 > sun_hours) {
      std::cout << "Invalid argument " << sun_hours << std::endl;
      return -1;
    }

    const auto result =
        solar_panel_calc::calc_solar_system_reqs(daily_consumption, sun_hours);

    std::cout << "Batteries: " << result.battery_count << std::endl
              << "Solar panel count: " << result.solar_panel_count << std::endl
              << "Square meter on the roof: " << result.solar_panel_area
              << std::endl;
  } catch (const std::exception& e) {
    std::cerr << "Invalid arguments" << std::endl;
    return 1;
  } catch (...) {
    std::cerr << "Unknown error occured" << std::endl;
    return 1;
  }

  return 0;
}
