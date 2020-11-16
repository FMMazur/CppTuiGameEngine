#include "Vector2.hpp"

#include <cmath>
#include <sstream>

template<typename T>
Vector2<T>::Vector2()
    : x(0)
    , y(0)
{}

template<typename T>
Vector2<T>::Vector2(T xy)
    : x(xy)
    , y(xy)
{}

template<typename T>
Vector2<T>::Vector2(T x, T y)
    : x(x)
    , y(y)
{}

template<typename T>
Vector2<T>::Vector2(const Vector2& vec2)
{
  this->x = vec2.x;
  this->y = vec2.y;
}

template<typename T>
Vector2<T>::~Vector2()
{}

template<typename T>
Vector2<T>& Vector2<T>::operator=(const Vector2<T>& vec2)
{
  this->x = vec2.x;
  this->y = vec2.y;

  return *this;
}

template<typename T>
void Vector2<T>::operator+=(const Vector2<T>& vec2)
{
  this->x += vec2.x;
  this->y += vec2.y;
}

template<typename T>
void Vector2<T>::operator-=(const Vector2<T>& vec2)
{
  this->x -= vec2.x;
  this->y -= vec2.y;
}

template<typename T>
void Vector2<T>::operator+=(const T number)
{
  this->x += number;
  this->y += number;
}

template<typename T>
void Vector2<T>::operator-=(const T number)
{
  this->x -= number;
  this->y -= number;
}

template<typename T>
void Vector2<T>::operator%=(const Vector2<T>& vec2)
{
  *this = this->cross(vec2);
}

template<typename T>
void Vector2<T>::operator*=(const T number)
{
  this->x *= number;
  this->y *= number;
}

template<typename T>
void Vector2<T>::operator/=(const T number)
{

  this->x /= number;
  this->y /= number;
}

template<typename T>
Vector2<T> Vector2<T>::operator+(const Vector2<T>& vec2) const
{
  return Vector2<T>(this->x + vec2.x, this->y + vec2.y);
}

template<typename T>
Vector2<T> Vector2<T>::operator-(const Vector2<T>& vec2) const
{
  return Vector2<T>(this->x - vec2.x, this->y - vec2.y);
}

template<typename T>
Vector2<T> Vector2<T>::operator%(const Vector2<T>& vec2) const
{
  return Vector2<T>(this->y * vec2.x - this->z * vec2.y,
                    this->z * vec2.x - this->x * vec2.z);
}

template<typename T>
T Vector2<T>::operator*(const Vector2<T>& vec2) const
{
  return this->x * vec2.x + this->y * vec2.y + this->z * vec2.z;
}

template<typename T>
Vector2<T>& Vector2<T>::operator++()
{
  this->x++;
  this->y++;
  this->z++;

  return *this;
}

template<typename T>
Vector2<T>& Vector2<T>::operator--()
{
  this->x--;
  this->y--;
  this->z--;

  return *this;
}

template<typename T>
Vector2<T> Vector2<T>::operator++(int)
{
  Vector2<T> vec2(*this);
  return ++vec2;
}
template<typename T>
Vector2<T> Vector2<T>::operator--(int)
{
  Vector2<T> vec2(*this);
  return --vec2;
}

template<typename T>
Vector2<T> Vector2<T>::normalized()
{
  Vector2<T> vec2(*this);
  vec2.normalize();

  return vec2;
}

template<typename T>
T Vector2<T>::cross(const Vector2<T>& vec2) const
{
  return Vector2<T>(this->x * vec2.y - this->y * vec2.x);
}

template<typename T>
T Vector2<T>::dot(const Vector2<T>& vec2)
{
  return this->x * vec2.x + this->y * vec2.y;
}

template<typename T>
T Vector2<T>::distance(const Vector2<T>& vec2)
{
  return Vector2<T>(this->x - vec2.x, this->y - vec2.y).magnitude();
}

template<typename T>
T Vector2<T>::magnitude()
{
  return static_cast<T>(std::sqrt(this->x * this->x + this->y * this->y));
}

template<typename T>
void Vector2<T>::normalize()
{
  float magnitude = static_cast<float>(this->magnitude());

  if (magnitude > 0.0f) {
    *this /= magnitude;
  }
}

template<typename T>
std::string Vector2<T>::inspect()
{
  std::stringstream ss;
  ss << "(" << this->x << ", " << this->y << ")";

  return ss.str();
}

template<typename T>
Vector2<T> Vector2<T>::one()
{
  auto one = static_cast<T>(1);
  return Vector2<T>(one, one, one);
}
