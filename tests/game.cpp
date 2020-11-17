#include "catch2/catch.hpp"

#include <iostream>
#include <sstream>
#include <string>

#include "Game.hpp"

#include "Camera.hpp"
#include "GameObject.hpp"
#include "Light.hpp"
#include "Mesh.hpp"
#include "Transform.hpp"

template<typename T>
std::string print(T* toPrint)
{
  return toPrint.inspect();
};

TEST_CASE("Game", "[game]")
{
  SECTION("create")
  {
    Game game("Super Jump Jump");

    CHECK(game.name() == "Super Jump Jump");
    CHECK(game.inspect() == "Super Jump Jump constains 1 scenes");

    CHECK(game.scenes().size() == 1);
    CHECK(game.get("Main Scene") != nullptr);
  }

  SECTION("scene")
  {
    Game game("Super Jump Jump");

    SECTION("add")
    {
      game.add(new Scene("Main Menu"));

      CHECK(game.scenes().size() == 2);
      CHECK(game.inspect() == "Super Jump Jump constains 2 scenes");
      CHECK(game.get("Main Menu") != nullptr);

      game.clear();
    }

    SECTION("remove")
    {
      game.remove("Main Scene");

      CHECK(game.scenes().size() == 0);
      CHECK(game.inspect() == "Super Jump Jump constains 0 scenes");
      CHECK(game.get("Main Scene") == nullptr);
    }

    SECTION("clear")
    {
      game.add(new Scene("Main Menu"));

      CHECK(game.scenes().size() == 2);

      game.clear();

      CHECK(game.scenes().size() == 0);
      CHECK(game.inspect() == "Super Jump Jump constains 0 scenes");
    }

    SECTION("get pointer")
    {
      auto pointer = game.get("Main Scene");

      CHECK(pointer == game.scenes().get(0));
      CHECK(pointer->compare(*game.scenes().get(0)) == Comparator::EQUAL);
      CHECK(pointer->name() == "Main Scene");
    }

    SECTION("iterate")
    {
      constexpr auto MAX = 10;
      uint64_t count = 0;

      for (size_t i = 1; i < MAX; ++i)
        game.add(new Scene(std::to_string(i)));

      game.scenes().iterate([&](Scene* scene) {
        CHECK(scene != nullptr);

        if (count == 0)
          CHECK(scene->name() == "Main Scene");
        else
          CHECK(scene->name() == std::to_string(count));

        ++count;
      });

      CHECK(count == MAX);
      game.clear();
    }
  }

  SECTION("print game")
  {
    Game game("Super Platform Jump");

    auto inspection = game.inspection();
    CHECK(inspection
          == "Super Platform Jump constains 1 scenes\n"
             "\tScene \"Main Scene\" contain 3 objects.\n"
             "\t\tGame Object \"Cube\" contain 0 childs and 2 components.\n"
             "\t\t\tTransform is at (0, 0, 0) with scale (1, 1, 1) "
             "rotated to (0, 0, 0)\n"
             "\t\t\tMesh with 0 vertices and 0 textures\n"
             "\t\tGame Object \"Light\" contain 0 childs and 2 components.\n"
             "\t\t\tTransform is at (0, 0, 0) with scale (1, 1, 1) "
             "rotated to (0, 0, 0)\n"
             "\t\t\tLight with color: (0, 0, 0, 0)\n"
             "\t\tGame Object \"Main Camera\" contain 0 childs and 2 "
             "components.\n"
             "\t\t\tTransform is at (0, 0, 0) with scale (1, 1, 1) "
             "rotated to (0, 0, 0)\n"
             "\t\t\tCamera\n");

    std::cout << inspection;
  }
}