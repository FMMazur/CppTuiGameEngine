#include "Light.hpp"

#include <sstream>

template<class VectorType>
Light<VectorType>::Light()
    : Component()
    , m_color(Color())
{}

template<class VectorType>
Light<VectorType>::Light(GameObject* parent)
    : Component(parent)
    , m_color(Color())
{}

template<class VectorType>
Light<VectorType>::Light(Color color)
    : Component()
    , m_color(color)
{}

template<class VectorType>
Light<VectorType>::Light(GameObject* parent, Color color)
    : Component(parent)
    , m_color(color)
{}

template<class VectorType>
Light<VectorType>::Light(GameObject* parent, Color& color)
    : Component(parent)
    , m_color(color)
{}

template<class VectorType>
Light<VectorType>::~Light()
{}

template<class VectorType>
std::string Light<VectorType>::inspect()
{
  std::stringstream ss;
  ss << this->class_name() << " with color: " << this->m_color.inspect();

  return ss.str();
}

template<class VectorType>
std::string Light<VectorType>::class_name()
{
  return "Light";
}

template<class VectorType>
Color Light<VectorType>::color()
{
  return this->m_color;
}

template<class VectorType>
VectorType Light<VectorType>::ambient()
{
  return this->m_ambient;
}

template<class VectorType>
VectorType Light<VectorType>::diffuse()
{
  return this->m_diffuse;
}

template<class VectorType>
VectorType Light<VectorType>::specular()
{
  return this->m_specular;
}

template<class VectorType>
Light<VectorType>& Light<VectorType>::ambient(VectorType ambient)
{
  this->m_ambient = ambient;
  return *this;
}

template<class VectorType>
Light<VectorType>& Light<VectorType>::diffuse(VectorType diffuse)
{
  this->m_diffuse = diffuse;
  return *this;
}

template<class VectorType>
Light<VectorType>& Light<VectorType>::specular(VectorType specular)
{
  this->m_specular = specular;
  return *this;
}
