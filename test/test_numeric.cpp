#include <catch2/catch_test_macros.hpp>

#include "doom/Numeric.h"


TEST_CASE("factorial", "") {

  SECTION("10", "factorial") {
    REQUIRE( doom::factorial(10) == 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1 );
  }

}