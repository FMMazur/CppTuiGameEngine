#ifndef __GAMEOBJECT_H__
#define __GAMEOBJECT_H__

#include <string>
#include <variant>

#include "Comparator.hpp"
#include "ComponentList.hpp"
#include "GameObjectList.hpp"
#include "Scene.hpp"

using GameObjectParent = std::variant<GameObject*, Scene*>;

class GameObject
{
public:
  GameObject() = delete;
  GameObject(GameObjectParent parent);
  GameObject(std::string name);
  GameObject(std::string name, GameObjectParent parent);
  ~GameObject();

  Comparator compare(const GameObject& scene);

  bool operator==(const GameObject& rhs) const;
  bool operator!=(const GameObject& rhs) const;

  const std::string& name();
  GameObject* parent_object();
  Scene* parent_scene();

  GameObject& add(GameObject* gameObject);
  GameObject& add(Component* component);

  GameObject& clear();
  GameObject& clear_childs();
  GameObject& clear_components();

  GameObject& get_child(const std::string& gameObjectName);
  Component& get_component(const std::string& componentName);

  bool remove_child(const std::string& childName);
  bool remove_component(const std::string& componentName);

  GameObject& remove(GameObject* gameObject);
  GameObject& remove(Component* component);

  void name(const std::string& name);
  void parent(GameObject* parent);
  void parent(Scene* parent);

  GameObjectList& childs();
  ComponentList& components();

  virtual std::string inspect();
  virtual void inspection(std::stringstream& ss, size_t tabs = 0);

  uint64_t id();

protected:
  uint64_t m_id;
  std::string m_name;
  GameObjectParent m_parent;

  GameObjectList m_childs;
  ComponentList m_components;

private:
  uint64_t create_id();
};

#endif // __GAMEOBJECT_H__