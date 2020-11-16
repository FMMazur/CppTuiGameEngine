#ifndef __VECTOR2_H__
#define __VECTOR2_H__

template<typename T>
class Vector2
{
public:
  Vector2();
  Vector2(T xy);
  Vector2(T x, T y);
  Vector2(const Vector2<T>& v);
  ~Vector2();

  Vector2<T>& operator=(const Vector2<T>& vec2);
  void operator+=(const Vector2<T>& vec2);
  void operator-=(const Vector2<T>& vec2);
  void operator%=(const Vector2<T>& vec2);

  void operator+=(const T number);
  void operator-=(const T number);
  void operator*=(const T number);
  void operator/=(const T number);

  Vector2<T> operator+(const Vector2<T>& vec2) const;
  Vector2<T> operator-(const Vector2<T>& vec2) const;
  Vector2<T> operator%(const Vector2<T>& vec2) const;
  T operator*(const Vector2<T>& vec2) const;

  Vector2<T> operator+(const T number) const;
  Vector2<T> operator-(const T number) const;
  Vector2<T> operator*(const T number) const;
  Vector2<T> operator/(const T number) const;

  Vector2<T>& operator++();
  Vector2<T>& operator--();

  Vector2<T> operator++(int);
  Vector2<T> operator--(int);

  Vector2<T> normalized();

  T cross(const Vector2<T>& vec2) const;
  T dot(const Vector2<T>& vec2);
  T distance(const Vector2<T>& vec2);
  T magnitude();

  void normalize();

  std::string inspect();

  static Vector2<T> one();

public:
  T x, y;
};

using Vector2f = Vector2<float>;
using Vector2i = Vector2<int>;

#include "Vector2.tpp"

#endif // __VECTOR2_H__