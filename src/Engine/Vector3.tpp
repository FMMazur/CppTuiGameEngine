#include "Vector3.hpp"

#include <cmath>
#include <sstream>

template<typename T>
Vector3<T>::Vector3()
    : x(0)
    , y(0)
    , z(0)
{}

template<typename T>
Vector3<T>::Vector3(T xyz)
    : x(xyz)
    , y(xyz)
    , z(xyz)
{}

template<typename T>
Vector3<T>::Vector3(T x, T y, T z)
    : x(x)
    , y(y)
    , z(z)
{}

template<typename T>
Vector3<T>::Vector3(const Vector3& vec3)
{
  this->x = vec3.x;
  this->y = vec3.y;
  this->z = vec3.z;
}

template<typename T>
Vector3<T>::~Vector3()
{}

template<typename T>
bool Vector3<T>::operator==(const Vector3<T>& vec3)
{
  return this->x == vec.x && this->y == vec.y && this->z == vec.z;
}

template<typename T>
bool Vector3<T>::operator!=(const Vector3<T>& vec3)
{
  return !(*this == vec3);
}

template<typename T>
Vector3<T>& Vector3<T>::operator=(const Vector3<T>& vec3)
{
  this->x = vec3.x;
  this->y = vec3.y;
  this->z = vec3.z;

  return *this;
}

template<typename T>
void Vector3<T>::operator+=(const Vector3<T>& vec3)
{
  this->x += vec3.x;
  this->y += vec3.y;
  this->z += vec3.z;
}

template<typename T>
void Vector3<T>::operator-=(const Vector3<T>& vec3)
{
  this->x -= vec3.x;
  this->y -= vec3.y;
  this->z -= vec3.z;
}

template<typename T>
void Vector3<T>::operator+=(const T number)
{
  this->x += number;
  this->y += number;
  this->z += number;
}

template<typename T>
void Vector3<T>::operator-=(const T number)
{
  this->x -= number;
  this->y -= number;
  this->z -= number;
}

template<typename T>
void Vector3<T>::operator%=(const Vector3<T>& vec3)
{
  *this = this->cross(vec3);
}

template<typename T>
void Vector3<T>::operator*=(const T number)
{
  this->x *= number;
  this->y *= number;
  this->z *= number;
}

template<typename T>
void Vector3<T>::operator/=(const T number)
{

  this->x /= number;
  this->y /= number;
  this->z /= number;
}

template<typename T>
Vector3<T> Vector3<T>::operator+(const Vector3<T>& vec3) const
{
  return Vector3<T>(this->x + vec3.x, this->y + vec3.y, this->z + vec3.z);
}

template<typename T>
Vector3<T> Vector3<T>::operator-(const Vector3<T>& vec3) const
{
  return Vector3<T>(this->x - vec3.x, this->y - vec3.y, this->z - vec3.z);
}

template<typename T>
Vector3<T> Vector3<T>::operator%(const Vector3<T>& vec3) const
{
  return Vector3<T>(this->y * vec3.z - this->z * vec3.y,
                    this->z * vec3.x - this->x * vec3.z,
                    this->x * vec3.y - this->y * vec3.x);
}

template<typename T>
T Vector3<T>::operator*(const Vector3<T>& vec3) const
{
  return this->x * vec3.x + this->y * vec3.y + this->z * vec3.z;
}

template<typename T>
Vector3<T>& Vector3<T>::operator++()
{
  this->x++;
  this->y++;
  this->z++;

  return *this;
}

template<typename T>
Vector3<T>& Vector3<T>::operator--()
{
  this->x--;
  this->y--;
  this->z--;

  return *this;
}

template<typename T>
Vector3<T> Vector3<T>::operator++(int)
{
  Vector3<T> vec3(*this);
  return ++vec3;
}
template<typename T>
Vector3<T> Vector3<T>::operator--(int)
{
  Vector3<T> vec3(*this);
  return --vec3;
}

template<typename T>
Vector3<T> Vector3<T>::cross(const Vector3<T>& vec3) const
{
  return Vector3<T>(this->y * vec3.z - this->z * vec3.y,
                    this->z * vec3.x - this->x * vec3.z,
                    this->x * vec3.y - this->y * vec3.x);
}

template<typename T>
Vector3<T> Vector3<T>::normalized()
{
  Vector3<T> vec3(*this);
  vec3.normalize();

  return vec3;
}

template<typename T>
T Vector3<T>::dot(const Vector3<T>& vec3)
{
  return this->x * vec3.x + this->y * vec3.y + this->z * vec3.z;
}

template<typename T>
T Vector3<T>::distance(const Vector3<T>& vec3)
{
  return Vector3<T>(this->x - vec3.x, this->y - vec3.y, this->z - vec3.z)
      .magnitude();
}

template<typename T>
T Vector3<T>::magnitude()
{
  return static_cast<T>(
      std::sqrt(this->x * this->x + this->y * this->y + this->z * this->z));
}

template<typename T>
void Vector3<T>::normalize()
{
  float magnitude = static_cast<float>(this->magnitude());

  if (magnitude > 0.0f) {

    float oneOverMag = 1.0f / magnitude;

    this->x = this->x * oneOverMag;
    this->y = this->y * oneOverMag;
    this->z = this->z * oneOverMag;
  }
}

template<typename T>
std::string Vector3<T>::inspect()
{
  std::stringstream ss;
  ss << "(" << this->x << ", " << this->y << ", " << this->z << ")";

  return ss.str();
}

template<typename T>
Vector3<T> Vector3<T>::one()
{
  auto one = static_cast<T>(1);
  return Vector3<T>(one, one, one);
}
