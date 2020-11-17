#ifndef __COMPONENT_H__
#define __COMPONENT_H__

#include <string>

class GameObject;
class Component
{
private:
public:
  Component();
  Component(const std::string& name);
  Component(GameObject* parent);
  Component(GameObject* parent, const std::string& name);

  virtual ~Component();

  virtual bool operator==(Component& rhs);
  virtual bool operator!=(Component& rhs);

  virtual std::string inspect() = 0;
  virtual std::string class_name() = 0;

  virtual GameObject* parent();
  virtual Component& parent(GameObject* parent);

  virtual std::string name();
  virtual Component& name(std::string name);

  uint64_t id();

protected:
  uint64_t m_id;
  std::string m_name;
  GameObject* m_parent;

private:
  uint64_t create_id();
};

#endif // __COMPONENT_H__