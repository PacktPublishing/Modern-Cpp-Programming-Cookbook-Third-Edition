#include <catch2/catch_test_macros.hpp>
#include <catch2/reporters/catch_reporter_teamcity.hpp>

TEST_CASE("case1")
{
   SECTION("function1")
   {
      REQUIRE(true);
   }
}

TEST_CASE("case2")
{
   SECTION("function2")
   {
      REQUIRE(false);
   }
}