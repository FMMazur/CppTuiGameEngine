#ifndef __SCENE_H__
#define __SCENE_H__

#include <string>

#include "GameObjectList.hpp"

class Scene
{
public:
  Scene(const char* name);
  Scene(const std::string& name);
  Scene() = delete;
  Scene(const Scene&) = delete;
  ~Scene();

  Scene& operator=(const Scene&) = default;

  bool operator==(const Scene& rhs);
  bool operator!=(const Scene& rhs);

  const std::string& name();
  const GameObjectList& objects();

  void set_name(const std::string& name);

private:
  std::string m_name;
  GameObjectList m_objects;
};

#endif // __SCENE_H__