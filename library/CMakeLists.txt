set(SOURCES
  solar_panel_calc.cpp)

add_library(library STATIC
  ${SOURCES})

target_compile_options(library
  PRIVATE
    -Wall
    -Werror)

target_include_directories(library
  INTERFACE
    include
  PRIVATE
    include/library)
