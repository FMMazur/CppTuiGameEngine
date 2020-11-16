#include "GameObject.hpp"

GameObject::GameObject() {}

GameObject::~GameObject() {}

bool GameObject::operator==(const GameObject& rhs) const
{
  //TODO: implements other checks
  return this->m_name == rhs.m_name;
}

bool GameObject::operator!=(const GameObject& rhs) const
{
  return !(*this == rhs);
}

Comparator GameObject::compare(const GameObject& scene)
{
  return Comparator::NOT_EQUAL;
}

const std::string& GameObject::name() { return this->m_name; }

void GameObject::set_name(const std::string& name) { this->m_name = name; }
