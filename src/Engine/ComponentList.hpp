#ifndef __COMPONENTLIST_H__
#define __COMPONENTLIST_H__

#include <string>

#include "Component.hpp"
#include "List.hpp"

class GameObject;
class ComponentList : public List<Component*>
{
public:
  ComponentList() {}
  ~ComponentList();

  void clear();

  ComponentList& add(GameObject* gameObject, Component* value);

  bool remove(const std::string& componentName);
  bool remove(uint64_t componentId);
  bool remove(Component* component);

  Component* get(const std::string& componentName);
  Component* get(uint64_t componentId);

  bool contains(const std::string& componentName) const;
  bool contains(uint64_t componentId) const;
  bool contains(Component* value) const;
};

#endif // __COMPONENTLIST_H__