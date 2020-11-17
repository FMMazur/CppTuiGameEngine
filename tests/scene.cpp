#include "catch2/catch.hpp"

#include "GameObject.hpp"
#include "Scene.hpp"

TEST_CASE("Scene", "[scene]")
{
  Scene scene("scene");

  SECTION("creation")
  {
    CHECK(scene.name() == "scene");
    CHECK(scene.id() == 0);
    CHECK(scene.objects().size() == 3);
  }

  SECTION("name")
  {
    SECTION("get") { CHECK(scene.name() == "scene"); }

    SECTION("change")
    {
      scene.name("new scene");
      CHECK(scene.name() == "new scene");
    }
  }

  SECTION("game objects")
  {
    SECTION("add")
    {
      GameObject* go = new GameObject("Game Object");
      GameObject* go1 = new GameObject("Game Object 1");

      scene.add(go).add(go1);

      CHECK(scene.objects().contains(go));
      CHECK(scene.objects().contains(go1));

      scene.clear_objects();
    }

    SECTION("remove")
    {
      GameObject* go = new GameObject("Game Object");
      GameObject* go1 = new GameObject("Game Object 1");

      scene.add(go).add(go1);

      SECTION("by name")
      {
        auto removed = scene.remove("Game Object");
        CHECK(removed);

        removed = scene.remove("Game Object 1");
        CHECK(removed);
      }

      SECTION("by pointer")
      {
        auto size = scene.remove(go).objects().size();
        CHECK(size == 4);

        size = scene.remove(go1).objects().size();
        CHECK(size == 3);
      }

      SECTION("all")
      {
        auto size = scene.clear_objects().objects().size();

        CHECK(size == 0);
      }

      scene.clear_objects();
    }

    SECTION("get pointer")
    {
      GameObject* go = new GameObject("Game Object");
      GameObject* go1 = new GameObject("Game Object 1");

      scene.add(go).add(go1);

      SECTION("by id")
      {
        auto pointer = scene.get_object(go->id());
        CHECK(pointer == go);
      }

      SECTION("by name")
      {
        auto pointer = scene.get_object(go1->name());
        CHECK(pointer == go1);
      }

      scene.clear_objects();
    }

    SECTION("iterate")
    {
      uint64_t count = 0;
      scene.objects().iterate([&](GameObject* child) {
        auto parent = child->parent_scene();

        CHECK_FALSE(parent == nullptr);
        CHECK(parent->name() == "scene");
        ++count;
      });

      CHECK(count == 3);
    }
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