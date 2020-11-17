#ifndef __COLOR_H__
#define __COLOR_H__

#include <cstdint>
#include <optional>
#include <sstream>

struct Color
{
  Color()
      : Color(0, 0, 0, 0)
  {}

  Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
      : r(r)
      , g(g)
      , b(b)
      , a(a)
  {}
  ~Color() {}

  bool operator==(const Color& rhs)
  {
    return this->r == rhs.r && this->g == rhs.g && this->b == rhs.b
        && this->a == rhs.a;
  }

  std::optional<uint8_t> operator[](std::size_t pos)
  {
    if (pos == 0) {
      return r;
    }

    if (pos == 1) {
      return g;
    }

    if (pos == 2) {
      return b;
    }

    if (pos == 3) {
      return a;
    }

    return std::nullopt;
  }

  std::string inspect()
  {
    std::stringstream ss;

    ss << "(" << std::to_string(this->r) << ", " << std::to_string(this->g)
       << ", " << std::to_string(this->b) << ", " << std::to_string(this->a)
       << ")";

    return ss.str();
  }

  uint8_t r, g, b, a;
};

#endif // __COLOR_H__