#include "catch2/catch.hpp"

#include "Camera.hpp"
#include "Component.hpp"
#include "Light.hpp"
#include "Mesh.hpp"
#include "Transform.hpp"

TEST_CASE("Camera", "[component]")
{
  SECTION("create")
  {
    Camera cam = Camera();

    CHECK(cam.class_name() == "Camera");
    CHECK(cam.inspect() == "Camera");

    CHECK(cam.id() == 0);
  }
}

TEST_CASE("Light", "[component]")
{
  SECTION("create 2d")
  {
    Light2f light2d = Light2f();

    CHECK(light2d.class_name() == "Light");
    CHECK(light2d.inspect() == "Light with color: (0, 0, 0, 0)");

    CHECK(light2d.id() == 1);
  }

  SECTION("create 3d")
  {
    Light3f light3d = Light3f();

    CHECK(light3d.class_name() == "Light");
    CHECK(light3d.inspect() == "Light with color: (0, 0, 0, 0)");

    CHECK(light3d.id() == 2);
  }
}

TEST_CASE("Mesh", "[component]")
{
  SECTION("create")
  {
    Mesh mesh = Mesh();

    CHECK(mesh.class_name() == "Mesh");
    CHECK(mesh.inspect() == "Mesh with 0 vertices and 0 textures");

    CHECK(mesh.id() == 3);
  }
}

TEST_CASE("Transform", "[component]")
{
  SECTION("create")
  {
    Transform transform = Transform();

    CHECK(transform.class_name() == "Transform");
    CHECK(transform.inspect()
          == "Transform is at (0, 0, 0) with scale (1, 1, 1) rotated to (0, 0, "
             "0)");

    CHECK(transform.id() == 4);
  }
}