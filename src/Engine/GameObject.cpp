#include "GameObject.hpp"

#include <sstream>

#include "Transform.hpp"

GameObject::GameObject(std::string name)
    : m_id(create_id())
    , m_name(name)
    , m_parent()
    , m_childs()
    , m_components()
{
  this->m_components.add(this, new Transform());
}

GameObject::GameObject(std::string name, GameObjectParent parent)
    : m_id(create_id())
    , m_name(name)
    , m_parent(parent)
    , m_childs()
    , m_components()
{
  std::visit(
      [&](auto&& parent) {
        using T = std::decay_t<decltype(parent)>;
        if constexpr (std::is_same_v<
                          T, GameObject*> || std::is_same_v<T, Scene*>) {
          parent->add(this);
        }
      },
      this->m_parent);
  this->m_components.add(this, new Transform());
}

GameObject::~GameObject() {}

bool GameObject::operator==(const GameObject& rhs) const
{
  //TODO: implements other checks
  return this->m_name == rhs.m_name && this->m_childs == rhs.m_childs
      && this->m_components == rhs.m_components;
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
GameObject* GameObject::parent_object()
{
  GameObject* _parent = nullptr;
  std::visit(
      [&](auto&& parent) {
        using T = std::decay_t<decltype(parent)>;
        if constexpr (std::is_same_v<T, GameObject*>) {
          _parent = parent;
        }
      },
      this->m_parent);

  return _parent;
}

Scene* GameObject::parent_scene()
{
  Scene* _parent = nullptr;
  std::visit(
      [&](auto&& parent) {
        using T = std::decay_t<decltype(parent)>;
        if constexpr (std::is_same_v<T, Scene*>) {
          _parent = parent;
        }
      },
      this->m_parent);

  return _parent;
}

GameObject& GameObject::add(GameObject* gameObject)
{
  this->m_childs.add(this, gameObject);
  return *this;
}

GameObject& GameObject::add(Component* component)
{
  this->m_components.add(this, component);
  return *this;
}

GameObject& GameObject::clear()
{
  this->m_childs.clear();
  this->m_components.clear();
  return *this;
}

GameObject& GameObject::clear_childs()
{
  this->m_childs.clear();
  return *this;
}

GameObject& GameObject::clear_components()
{
  this->m_components.clear();
  return *this;
}

GameObject& GameObject::get_child(const std::string& gameObjectName)
{
  return *this->m_childs.get(gameObjectName);
}

Component& GameObject::get_component(const std::string& componentName)
{
  return *this->m_components.get(componentName);
}

bool GameObject::remove_child(const std::string& childName)
{
  return this->m_childs.remove(childName);
}

bool GameObject::remove_component(const std::string& componentName)
{
  return this->m_components.remove(componentName);
}

GameObject& GameObject::remove(GameObject* gameObject)
{
  this->m_childs.remove(gameObject);
  return *this;
}

GameObject& GameObject::remove(Component* component)
{
  this->m_components.remove(component);
  return *this;
}

void GameObject::name(const std::string& name) { this->m_name = name; }

void GameObject::parent(GameObject* parent) { this->m_parent = parent; }
void GameObject::parent(Scene* parent) { this->m_parent = parent; }

GameObjectList& GameObject::childs() { return this->m_childs; }

ComponentList& GameObject::components() { return this->m_components; }

std::string GameObject::inspect()
{
  std::stringstream ss;
  ss << "Game Object \"" << this->m_name << "\" contain "
     << this->m_childs.size() << " childs and " << this->m_components.size()
     << " components.";

  return ss.str();
}

void GameObject::inspection(std::stringstream& ss, size_t tabs)
{
  if (tabs)
    for (size_t i = 0; i < tabs; i++) {
      ss << "\t";
    }

  ss << this->inspect() << std::endl;

  this->m_childs.iterate([&](GameObject* go) { go->inspection(ss, tabs + 1); });
  this->m_components.iterate(
      [&](Component* component) { component->inspection(ss, tabs + 1); });
}

uint64_t GameObject::id() { return this->m_id; }

uint64_t GameObject::create_id()
{
  static uint64_t id = 0;

  return id++;
}