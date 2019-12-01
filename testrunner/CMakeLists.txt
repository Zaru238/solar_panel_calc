include(CTest)
find_package(GTest)

message("Kostian")
message(${GTest_FOUND})

if (NOT ${GTest_FOUND})
  message(WARNING "Gtest hasn't found. Unitests are skipped")
  return()
endif()

enable_testing()

  set(SOURCES
  main.cpp
  solar_panel_calc.cpp)

add_executable(testrunner
  "${SOURCES}")

target_compile_options(testrunner
  PRIVATE
    -Wall
    -Werror)

target_link_libraries(testrunner
  PRIVATE
    GTest::GTest
    library)

gtest_discover_tests(testrunner)

