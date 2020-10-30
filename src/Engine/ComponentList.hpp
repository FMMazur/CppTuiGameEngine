#ifndef __COMPONENTLIST_H__
#define __COMPONENTLIST_H__

#include <string>

#include "Component.hpp"
#include "List.hpp"

class ComponentList : public List<Component>
{
public:
  ComponentList() { }
  ~ComponentList() { }

  bool remove(const std::string& componentName);
  bool remove(uint64_t componentId);

  Component* get(const std::string& componentName);
  Component* get(uint64_t componentId);

  bool contains(const std::string& componentName) const;
  bool contains(uint64_t componentId) const;
};

#endif // __COMPONENTLIST_H__