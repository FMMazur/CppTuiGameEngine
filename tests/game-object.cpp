#include "catch2/catch.hpp"

#include "Camera.hpp"
#include "GameObject.hpp"
#include "Light.hpp"
#include "Mesh.hpp"
#include "Transform.hpp"

TEST_CASE("Game Object", "[game-object]")
{
  SECTION("create")
  {
    GameObject go("Game Object");

    CHECK(go.name() == "Game Object");
    CHECK(go.childs().size() == 0);
    CHECK(go.components().size() == 1);
  }

  SECTION("get name")
  {
    GameObject go("Player");
    CHECK(go.name() == "Player");
  }

  SECTION("set name")
  {
    GameObject go("Player");
    go.name("Player 1");

    CHECK(go.name() == "Player 1");
  }

  SECTION("child")
  {
    GameObject parent("Parent");
    GameObject* child = new GameObject("Child");

    SECTION("add")
    {
      parent.add(child);
      CHECK(parent.childs().size() == 1);

      parent.childs().iterate([](GameObject* child) {
        CHECK(child->name() == "Child");
        auto parent = child->parent_object();

        CHECK_FALSE(parent == nullptr);
        CHECK(parent->name() == "Parent");
      });
    }

    SECTION("remove")
    {
      GameObject* child2 = new GameObject("Child 2");

      parent.add(child).add(child2);
      CHECK(parent.childs().size() == 2);

      SECTION("by name")
      {
        parent.remove_child("Child");
        CHECK(parent.childs().size() == 1);
      }

      SECTION("by pointer")
      {
        parent.remove(child);
        CHECK(parent.childs().size() == 1);
      }
    }

    SECTION("iterate")
    {
      GameObject* child2 = new GameObject("Child 2");

      uint64_t count = 0;
      parent.add(child).add(child2).childs().iterate([&](GameObject* child) {
        auto parent = child->parent_object();

        CHECK_FALSE(parent == nullptr);
        CHECK(parent->name() == "Parent");
        ++count;
      });

      CHECK(count == 2);
    }

    SECTION("clear")
    {
      SECTION("childs")
      {
        GameObject* child2 = new GameObject("Child 2");
        auto size
            = parent.add(child).add(child2).clear_childs().childs().size();

        CHECK(size == 0);
      }
    }

    SECTION("get pointer")
    {
      auto pointer = &parent.add(child).get_child("Child");

      CHECK(pointer == child);

      pointer->name("Children");
      CHECK(pointer->name() == child->name());
    }
  }

  SECTION("components")
  {
    GameObject go("Game Object");

    SECTION("add")
    {
      Component* mesh = new Mesh();
      Component* camera = new Camera();
      Component* transform = new Transform();

      auto size = go.add(mesh).add(camera).add(transform).components().size();

      CHECK(size == 3);
    }

    SECTION("remove")
    {
      Component* mesh = new Mesh();
      Component* camera = new Camera();

      auto size = go.add(mesh).add(camera).components().size();
      CHECK(size == 3);

      SECTION("by name")
      {
        auto removed = go.remove_component("Transform");
        CHECK_FALSE(removed);

        removed = go.remove_component("Camera");
        CHECK(removed);

        removed = go.remove_component("Mesh");
        CHECK(removed);
      }

      SECTION("by pointer")
      {
        auto transform = &go.get_component("Transform");

        CHECK(go.remove(transform).components().size() == 3);
        CHECK(go.remove(mesh).components().size() == 2);
        CHECK(go.remove(camera).components().size() == 1);
      }
    }

    SECTION("get pointer")
    {
      auto transform = &go.get_component("Transform");
      CHECK(go.components().contains(transform));
    }

    SECTION("iterate")
    {
      Component* mesh = new Mesh();
      Component* camera = new Camera();

      uint64_t count = 0;
      go.add(mesh).add(camera).components().iterate([&](Component* child) {
        auto parent = child->parent();

        CHECK_FALSE(parent == nullptr);
        CHECK(parent->name() == "Game Object");
        ++count;
      });

      CHECK(count == 3);
      CHECK(count == go.components().size());
    }

    SECTION("clear")
    {
      Component* mesh = new Mesh();
      Component* camera = new Camera();
      auto size
          = go.add(mesh).add(camera).clear_components().components().size();

      CHECK(size == 1);
    }

    SECTION("inspect")
    {
      Component* mesh = new Mesh();
      Component* camera = new Camera();
      auto size
          = go.add(mesh).add(camera).clear_components().components().size();

      CHECK(
          go.inspect()
          == "Game Object \"Game Object\" contain 0 childs and 1 components.");
    }
  }
}