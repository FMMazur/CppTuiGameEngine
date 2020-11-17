#ifndef __SCENE_H__
#define __SCENE_H__

#include <string>

#include "Comparator.hpp"
#include "GameObjectList.hpp"
class Scene
{
public:
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

  Scene& add(GameObject* gameObject);

  GameObject* get_object(const std::string& gameObjectName);
  GameObject* get_object(uint64_t gameObjectId);

  Scene& remove(GameObject* gameObject);
  bool remove(const std::string& gameObjectName);

  Scene& clear_objects(); // Remove all objects

  uint64_t id();
  const std::string& name();
  GameObjectList& objects();

  void name(const std::string& name);

  std::string inspect();

protected:
  std::string m_name;
  GameObjectList m_objects;

  uint64_t m_id;
  uint64_t create_id();
};

#endif // __SCENE_H__