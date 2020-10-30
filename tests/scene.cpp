#include "Engine/Scene.hpp"
#include "catch2/catch.hpp"
#include <any>
#include <memory>

TEST_CASE("Scene", "simple use")
{
  Scene t1("t1");
  SECTION("change name")
  {
    t1.set_name("new t1");
    CHECK(t1.name() == "new t1");
  }
}