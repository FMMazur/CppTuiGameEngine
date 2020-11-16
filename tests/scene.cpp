#include "Scene.hpp"
#include "catch2/catch.hpp"
#include <any>
#include <memory>

TEST_CASE("Scene", "[scene]")
{
  SECTION("change name")
  {
    Scene t1("t1");
    t1.set_name("new t1");
    CHECK(t1.name() == "new t1");
  }

  SECTION("compare name of two scenes")
  {
    SECTION("equal")
    {
      Scene t1("t1");
      CHECK(t1.compare(t1) == Comparator::EQUAL);
    }
    SECTION("parcial")
    {
      Scene t1("t1");
      Scene newt1("t1");
      CHECK(t1.compare(newt1) == Comparator::PARCIAL);
    }
    SECTION("not equal")
    {
      Scene t1("t1");
      Scene t2("t2");
      CHECK(t1.compare(t2) == Comparator::NOT_EQUAL);
    }
  }
}