#include "Engine/SceneList.hpp"
#include "catch2/catch.hpp"

TEST_CASE("SceneList", "simple use")
{
  SceneList list;

  SECTION("add scenes")
  {
    Scene* t1 = new Scene("a");
    Scene* t2 = new Scene("b");
    Scene* t3 = new Scene("c");
    auto nlist = &list.add(t1).add(t2).add(t3);

    REQUIRE(*(nlist) == list);
  }

  SECTION("contains an scene")
  {
    Scene* t1 = new Scene("a");
    Scene* t2 = new Scene("b");
    Scene* t3 = new Scene("c");
    list.add(t1).add(t2).add(t3);

    auto contains = list.contains("b");
    CHECK(contains);
  }

  SECTION("get scene")
  {
    Scene* t1 = new Scene("d");
    list.add(t1);

    auto scene = list.get("d");
    CHECK(scene == t1);
  }
}
