#include "SceneList.hpp"
#include "catch2/catch.hpp"

TEST_CASE("SceneList", "[scene-list]")
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

    SECTION("by name")
    {
      auto contains = list.contains("b");
      CHECK(contains);
    }

    SECTION("by id")
    {
      auto contains = list.contains(13); // "b"
      CHECK(contains);
    }
  }

  SECTION("get scene")
  {
    Scene* t1 = new Scene("a");
    list.add(t1);

    SECTION("by name")
    {
      auto scene = list.get("a");
      CHECK(scene == t1);
    }

    SECTION("by id")
    {
      // id = 16 because of others creations
      auto scene = list.get(16);
      CHECK(scene == t1);
    }
  }

  SECTION("delete scene")
  {
    Scene* t1 = new Scene("a");
    Scene* t2 = new Scene("b");
    Scene* t3 = new Scene("c");
    list.add(t1).add(t2).add(t3);

    SECTION("by name")
    {
      auto removed = list.remove("a");
      CHECK(removed == true);
      CHECK(list.get(0) == t2);
    }

    SECTION("by pointer")
    {
      auto removed = list.remove(t2);
      CHECK(removed == true);
      CHECK(list.get(0) == t3);
    }
  }
}
