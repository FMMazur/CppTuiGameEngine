#ifndef __GAMEOBJECTLIST_H__
#define __GAMEOBJECTLIST_H__

#include <string>

// #include "GameObject.hpp"
#include "List.hpp"

class GameObject;
class Scene;

class GameObjectList : public List<GameObject*>
{
public:
  GameObjectList() {}
  ~GameObjectList() {}

  GameObjectList& add(Scene* scene, GameObject* value);
  GameObjectList& add(GameObject* gameObject, GameObject* value);

  bool remove(const std::string& gameObjectName);
  bool remove(uint64_t gameObjectId);
  bool remove(GameObject* gameObject);

  GameObject* get(const std::string& gameObjectName);
  GameObject* get(uint64_t gameObjectId);

  bool contains(const std::string& gameObjectName) const;
  bool contains(uint64_t gameObjectId) const;
  bool contains(GameObject* value) const;
};

#endif // __GAMEOBJECTLIST_H__