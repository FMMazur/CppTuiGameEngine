#include "Component.hpp"
#include "GameObject.hpp"

Component::Component()
    : m_id(create_id())
    , m_parent(nullptr)
{}

Component::Component(GameObject* parent)
    : m_id(create_id())
    , m_parent(parent)
{
  //TODO: add component to parent
}
Component::~Component()
{
  m_id = 0;
  m_parent = nullptr;
}

bool Component::operator==(Component& rhs)
{
  return this->m_parent == rhs.m_parent && this->m_id == rhs.m_id
      && this->class_name() == rhs.class_name();
}

bool Component::operator!=(Component& rhs) { return !(*this == rhs); }

GameObject* Component::parent() { return this->m_parent; }

Component& Component::parent(GameObject& parent)
{
  this->m_parent = &parent;
  return *this;
}

uint64_t Component::id() { return this->m_id; }

uint64_t Component::create_id()
{
  static uint64_t id = 0;

  return id++;
}
