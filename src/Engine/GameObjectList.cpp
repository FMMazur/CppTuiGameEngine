#include "GameObjectList.hpp"

#include "GameObject.hpp"
#include "Scene.hpp"

GameObjectList& GameObjectList::add(Scene* sceneParent, GameObject* value)
{
  if (!this->contains(value->name())) {
    value->parent(sceneParent);
    this->addValue(value);
  }

  return *this;
}

GameObjectList& GameObjectList::add(GameObject* gameObjectParent,
                                    GameObject* value)
{
  if (!this->contains(value->name())) {
    value->parent(gameObjectParent);
    this->addValue(value);
  }

  return *this;
}

bool GameObjectList::remove(const std::string& gameObjectName)
{
  Node<GameObject*>** pp = &this->m_head;

  for (Node<GameObject*>* prev = nullptr; *pp != nullptr;
       prev = *pp, pp = prev->next_pointer())
    if ((*pp)->value()->name() == gameObjectName) {
      Node<GameObject*>* node = *pp;

      if (node == this->m_tail)
        this->m_tail = prev;
      *pp = node->next();
      delete node;
      this->m_counter--;
      return true;
    }
  return false;
}

bool GameObjectList::remove(uint64_t gameObjectId)
{
  Node<GameObject*>** pp = &this->m_head;

  for (Node<GameObject*>* prev = nullptr; *pp != nullptr;
       prev = *pp, pp = prev->next_pointer())
    if ((*pp)->value()->id() == gameObjectId) {
      Node<GameObject*>* node = *pp;

      if (node == this->m_tail)
        this->m_tail = prev;
      *pp = node->next();
      delete node;
      this->m_counter--;
      return true;
    }
  return false;
}

bool GameObjectList::remove(GameObject* gameObject)
{
  return this->remove(gameObject->id());
}

GameObject* GameObjectList::get(const std::string& gameObjectName)
{
  for (Node<GameObject*>* node = this->m_head; node != nullptr;
       node = node->next()) {
    if (node->value()->name() == gameObjectName)
      return node->value();
  }

  return nullptr;
}

GameObject* GameObjectList::get(uint64_t gameObjectId)
{
  if (gameObjectId == 0)
    return this->m_head->value();
  if (gameObjectId == this->m_counter - 1)
    return this->m_tail->value();

  for (Node<GameObject*>* node = this->m_head; node != nullptr;
       node = node->next()) {
    if (node->value()->id() == gameObjectId)
      return node->value();
  }

  return nullptr;
}

bool GameObjectList::contains(const std::string& gameObjectName) const
{
  for (Node<GameObject*>* node = this->m_head; node != nullptr;
       node = node->next())
    if (node->value()->name() == gameObjectName)
      return true;
  return false;
}

bool GameObjectList::contains(uint64_t gameObjectId) const
{
  for (Node<GameObject*>* node = this->m_head; node != nullptr;
       node = node->next())
    if (node->value()->id() == gameObjectId)
      return true;
  return false;
}

bool GameObjectList::contains(GameObject* value) const
{
  return this->contains(value->id());
}
