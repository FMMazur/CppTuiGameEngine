#include "SceneList.hpp"

bool SceneList::remove(const std::string& sceneName)
{
  Node<Scene>** pp = &this->head;

  for (Node<Scene>* prev = nullptr; *pp != nullptr;
       prev = *pp, *pp = prev->next())
    if ((*pp)->value()->name() == sceneName) {
      Node<Scene>* node = *pp;

      if (node == this->tail)
        this->tail = prev;
      *pp = node->next();
      delete node;
      this->count--;
      return true;
    }
  return false;
}

Scene* SceneList::get(const std::string& sceneName)
{
  for (Node<Scene>* node = this->head; node != nullptr; node = node->next()) {
    if (node->value()->name() == sceneName)
      return node->value();
  }

  return nullptr;
}

bool SceneList::contains(const std::string& sceneName) const
{
  for (Node<Scene>* node = this->head; node != nullptr; node = node->next())
    if (node->value()->name() == sceneName)
      return true;
  return false;
}
