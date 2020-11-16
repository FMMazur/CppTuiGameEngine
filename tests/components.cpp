#include "catch2/catch.hpp"

#include <any>
#include <memory>

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

TEST_CASE("Mesh", "[component]")
{
  SECTION("create")
  {
    Mesh mesh = Mesh();

    CHECK(mesh.class_name() == "Mesh");
    CHECK(mesh.inspect() == "Mesh with 0 vertices and 0 textures");

    CHECK(mesh.id() == 1);
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

    CHECK(transform.id() == 2);
  }
}