#ifndef __GAMEOBJECTLIST_H__
#define __GAMEOBJECTLIST_H__

#include <string>

#include "List.hpp"

class GameObject;
class GameObjectList : public List<GameObject>
{
public:
  GameObjectList() { }
  ~GameObjectList() { }

  bool remove(const std::string& gameObjectName);
  bool remove(uint64_t gameObjectId);

  GameObject* get(const std::string& gameObjectName);
  GameObject* get(uint64_t gameObjectId);

  bool contains(const std::string& gameObjectName) const;
  bool contains(uint64_t gameObjectId) const;
};

#endif // __GAMEOBJECTLIST_H__