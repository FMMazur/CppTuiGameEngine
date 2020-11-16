#ifndef __VECTOR3_H__
#define __VECTOR3_H__

template<typename T>
class Vector3
{
public:
  Vector3();
  Vector3(T xyz);
  Vector3(T x, T y, T z);
  Vector3(const Vector3<T>& v);
  ~Vector3();

  bool operator==(const Vector3<T>& vec3);
  bool operator!=(const Vector3<T>& vec3);

  void operator+=(const Vector3<T>& vec3);
  void operator-=(const Vector3<T>& vec3);
  void operator%=(const Vector3<T>& vec3);

  void operator+=(const T number);
  void operator-=(const T number);
  void operator*=(const T number);
  void operator/=(const T number);

  Vector3<T>& operator=(const Vector3<T>& vec3);
  Vector3<T> operator+(const Vector3<T>& vec3) const;
  Vector3<T> operator-(const Vector3<T>& vec3) const;
  Vector3<T> operator%(const Vector3<T>& vec3) const;
  T operator*(const Vector3<T>& vec3) const;

  Vector3<T> operator+(const T number) const;
  Vector3<T> operator-(const T number) const;
  Vector3<T> operator*(const T number) const;
  Vector3<T> operator/(const T number) const;

  Vector3<T>& operator++();
  Vector3<T>& operator--();

  Vector3<T> operator++(int);
  Vector3<T> operator--(int);

  Vector3<T> cross(const Vector3<T>& vec3) const;
  Vector3<T> normalized();

  T dot(const Vector3<T>& vec3);
  T distance(const Vector3<T>& vec3);
  T magnitude();

  void normalize();

  std::string inspect();

  static Vector3<T> one();

public:
  T x, y, z;
};

using Vector3f = Vector3<float>;
using Vector3i = Vector3<int>;

#include "Vector3.tpp"

#endif // __VECTOR3_H__