#include "catch2/catch.hpp"

#include "GameObject.hpp"
#include "GameObjectList.hpp"

TEST_CASE("GameObjectList,", "[game-object-list]")
{
  GameObject player("Player");
  GameObjectList list = player.childs();

  SECTION("add")
  {
    GameObject* t1 = new GameObject("a");
    GameObject* t2 = new GameObject("b");
    GameObject* t3 = new GameObject("c");
    auto nlist = &list.add(&player, t1).add(&player, t2).add(&player, t3);

    CHECK(*(nlist) == list);
    CHECK(list.size() == 3);
  }

  SECTION("contains")
  {
    GameObject* t1 = new GameObject("a");
    GameObject* t2 = new GameObject("b");
    GameObject* t3 = new GameObject("c");
    list.add(&player, t1).add(&player, t2).add(&player, t3);

    SECTION("by name")
    {
      auto contains = list.contains(t2->name());
      CHECK(contains);
    }

    SECTION("by id")
    {
      auto contains = list.contains(t2->id());
      CHECK(contains);
    }
  }

  SECTION("get")
  {
    GameObject* t1 = new GameObject("a");
    list.add(&player, t1);

    SECTION("by name")
    {
      auto go = list.get("a");
      CHECK(go == t1);
    }

    SECTION("by id")
    {
      // id = 16 because of others creations
      auto go = list.get(t1->id());
      CHECK(go == t1);
    }
  }

  SECTION("remove")
  {
    GameObject* t1 = new GameObject("a");
    GameObject* t2 = new GameObject("b");
    GameObject* t3 = new GameObject("c");
    list.add(&player, t1).add(&player, t2).add(&player, t3);

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
      CHECK(list.get(1) == t3);
    }
  }
}
