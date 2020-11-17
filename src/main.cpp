#include <iostream>

#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>

#include "Engine.hpp"

int main(int argc, const char* argv[])
{
  using namespace ftxui;
  auto document = //
      hbox({
          text(L"This text is "),
          text(L"blink") | blink,
          text(L". Do you like it?"),
      });
  auto screen = Screen::Create(Dimension::Full(), Dimension::Fit(document));
  Render(screen, document);

  GameObject* player = new GameObject("player");
  Mesh* mesh = new Mesh(player, std::vector<Vertex>(), std::vector<Texture>());

  {
    auto textures = mesh->textures();
    textures.push_back(Texture());
    std::cout << textures.size() << std::endl;
  }

  std::cout << mesh->textures().size() << std::endl;

  std::cout << screen.ToString();

  return 0;
}
