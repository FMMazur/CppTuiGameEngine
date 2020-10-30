#ifndef __COMPONENT_H__
#define __COMPONENT_H__

#include <memory>
#include <string>

#include "GameObject.hpp"

class Component
{
private:
public:
  Component() = delete;
  Component(uint64_t id, GameObject* parent);

  virtual ~Component() = 0;

  virtual std::string inspect() = 0;
  virtual std::string class_name() = 0;

  virtual bool operator==(const Component& rhs) = 0;
  virtual bool operator!=(const Component& rhs) = 0;

  uint64_t get_id();

protected:
  uint64_t id;
  GameObject* parent;

  uint64_t create_id();
};

#endif // __COMPONENT_H__