# solar_panel_calc

## Requirements

Cmake >= 3.05

Gcc with c++11 support

Gtest >= 1.8 (Optional)

## Usage

./program a b

Where 'a' is a daily consumption - valid range is from 0 to 2^32
  and 'b' is a sun hours - valid range is from 1 to 24

Returns amount of batteries, amount of panels and required roof space
