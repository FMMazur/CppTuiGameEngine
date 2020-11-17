#include "Transform.hpp"

#include <sstream>

Transform::Transform()
    : Component()
    , m_position()
    , m_scale(Vector3f::one())
    , m_rotation()
{}

Transform::Transform(Vector3f position)
    : Component()
    , m_position(position)
    , m_scale(Vector3f::one())
    , m_rotation()
{}

Transform::Transform(Vector3f position, Vector3f rotation)
    : Component()
    , m_position(position)
    , m_scale(Vector3f::one())
    , m_rotation(rotation)
{}

Transform::Transform(Vector3f position, Vector3f rotation, Vector3f scale)
    : Component()
    , m_position(position)
    , m_scale(scale)
    , m_rotation(rotation)
{}

Transform::Transform(GameObject* parent)
    : Component(parent)
    , m_position()
    , m_scale(Vector3f::one())
    , m_rotation()
{}

Transform::Transform(GameObject* parent, Vector3f position)
    : Component(parent)
    , m_position(position)
    , m_scale(Vector3f::one())
    , m_rotation()
{}

Transform::Transform(GameObject* parent, Vector3f position, Vector3f rotation)
    : Component(parent)
    , m_position(position)
    , m_scale(Vector3f::one())
    , m_rotation(rotation)
{}

Transform::Transform(GameObject* parent, Vector3f position, Vector3f rotation,
                     Vector3f scale)
    : Component(parent)
    , m_position(position)
    , m_scale(scale)
    , m_rotation(rotation)
{}

Transform::~Transform() {}

std::string Transform::inspect()
{
  std::stringstream ss;
  ss << this->class_name() << " is at " << this->m_position.inspect()
     << " with scale " << this->m_scale.inspect() << " rotated to "
     << this->m_rotation.inspect();

  return ss.str();
}

std::string Transform::class_name() { return "Transform"; }
