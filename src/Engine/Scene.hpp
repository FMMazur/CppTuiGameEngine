#ifndef __SCENE_H__
#define __SCENE_H__

#include <string>

#include "Comparator.hpp"
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

  Comparator compare(const Scene& scene);

  bool operator==(const Scene& rhs);
  bool operator!=(const Scene& rhs);

  bool operator==(const Scene& rhs) const;
  bool operator!=(const Scene& rhs) const;

  uint64_t id();
  const std::string& name();
  const GameObjectList& objects();

  void set_name(const std::string& name);

private:
  std::string m_name;
  GameObjectList m_objects;

  uint64_t m_id;
  uint64_t create_id();
};

#endif // __SCENE_H__