#include "catch2/catch.hpp"

#include "ComponentList.hpp"

#include "Camera.hpp"
#include "Component.hpp"
#include "GameObject.hpp"
#include "Light.hpp"
#include "Mesh.hpp"
#include "Transform.hpp"

TEST_CASE("ComponentList,", "[component-list]")
{
  GameObject player("Player");
  ComponentList& list = player.components();

  SECTION("add")
  {
    Component* mesh = new Mesh();
    Component* camera = new Camera();
    Component* light = new Light2f();
    &list.add(&player, mesh).add(&player, camera).add(&player, light);

    CHECK(list.size() == 4);
  }

  SECTION("contains")
  {
    Component* mesh = new Mesh();
    Component* camera = new Camera();
    Component* light = new Light2f();
    list.add(&player, mesh).add(&player, camera).add(&player, light);

    SECTION("by name")
    {
      auto contains = list.contains(camera->class_name());
      CHECK(contains);
    }

    SECTION("by id")
    {
      auto contains = list.contains(camera->id());
      CHECK(contains);
    }
  }

  SECTION("get")
  {
    Component* mesh = new Mesh();
    Component* camera = new Camera();
    Component* light = new Light2f();
    list.add(&player, mesh).add(&player, camera).add(&player, light);

    SECTION("by name")
    {
      auto scene = list.get("Mesh");
      CHECK(scene == mesh);
    }

    SECTION("by id")
    {
      // id = 16 because of others creations
      auto scene = list.get(mesh->id());
      CHECK(scene == mesh);
    }
  }

  SECTION("delete scene")
  {
    Component* mesh = new Mesh();
    Component* camera = new Camera();
    Component* light = new Light2f();
    list.add(&player, mesh).add(&player, camera).add(&player, light);

    SECTION("by name")
    {
      auto removed = list.remove("Mesh");
      CHECK(removed == true);
      CHECK(list.get("Mesh") == nullptr);
    }

    SECTION("by pointer")
    {
      auto removed = list.remove(camera);
      CHECK(removed == true);
      CHECK(list.get("Camera") == nullptr);
    }
  }
}
