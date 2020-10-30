#include <iostream>

#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>

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

  std::cout << screen.ToString();

  return 0;
}
