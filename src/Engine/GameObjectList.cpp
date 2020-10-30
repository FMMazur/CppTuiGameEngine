#include "GameObjectList.hpp"
#include "GameObject.hpp"

bool GameObjectList::remove(const std::string& gameObjectName) { return false; }

bool GameObjectList::remove(uint64_t gameObjectId) { return false; }

GameObject* GameObjectList::get(const std::string& gameObjectName)
{
  return nullptr;
}

GameObject* GameObjectList::get(uint64_t gameObjectId) { return nullptr; }

bool GameObjectList::contains(const std::string& gameObjectName) const
{
  return false;
}

bool GameObjectList::contains(uint64_t gameObjectId) const { return false; }
