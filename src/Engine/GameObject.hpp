#ifndef __GAMEOBJECT_H__
#define __GAMEOBJECT_H__

#include <string>

#include "Comparator.hpp"

class GameObject
{
public:
  GameObject();
  ~GameObject();

  Comparator compare(const GameObject& scene);

  bool operator==(const GameObject& rhs) const;
  bool operator!=(const GameObject& rhs) const;

  const std::string& name();

  void set_name(const std::string& name);

private:
  std::string m_name;
};

#endif // __GAMEOBJECT_H__