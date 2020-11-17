#include "SceneList.hpp"

bool SceneList::remove(const std::string& sceneName)
{
  Node<Scene*>** temp = &this->m_head;

  for (Node<Scene*>* prev = nullptr; *temp != nullptr;
       prev = *temp, *temp = prev->next())
    if ((*temp)->value()->name() == sceneName) {
      Node<Scene*>* node = *temp;

      if (node == this->m_tail)
        this->m_tail = prev;
      *temp = node->next();
      delete node;
      this->m_counter--;
      return true;
    }
  return false;
}

bool SceneList::remove(Scene* scene)
{
  Node<Scene*>** temp = &this->m_head;

  for (Node<Scene*>* prev = nullptr; *temp != nullptr;
       prev = *temp, temp = prev->next_pointer())
    if ((*temp)->value() == scene) {
      Node<Scene*>* node = *temp;

      if (node == this->m_tail)
        this->m_tail = prev;
      *temp = node->next();
      delete node;
      this->m_counter--;
      return true;
    }
  return false;
}

bool SceneList::remove(uint64_t sceneId)
{
  Node<Scene*>** temp = &this->m_head;

  for (Node<Scene*>* prev = nullptr; *temp != nullptr;
       prev = *temp, *temp = prev->next())
    if ((*temp)->value()->id() == sceneId) {
      Node<Scene*>* node = *temp;

      if (node == this->m_tail)
        this->m_tail = prev;
      *temp = node->next();
      delete node;

      this->m_counter--;
      return true;
    }
  return false;
}

Scene* SceneList::get(const std::string& sceneName)
{
  for (Node<Scene*>* node = this->m_head; node != nullptr;
       node = node->next()) {
    if (node->value()->name() == sceneName)
      return node->value();
  }

  return nullptr;
}

Scene* SceneList::get(uint64_t sceneId)
{
  if (sceneId == 0)
    return this->m_head->value();
  if (sceneId == this->m_counter - 1)
    return this->m_tail->value();

  for (Node<Scene*>* node = this->m_head; node != nullptr;
       node = node->next()) {
    if (node->value()->id() == sceneId)
      return node->value();
  }

  return nullptr;
}

bool SceneList::contains(const std::string& sceneName) const
{
  for (Node<Scene*>* node = this->m_head; node != nullptr; node = node->next())
    if (node->value()->name() == sceneName)
      return true;
  return false;
}

bool SceneList::contains(uint64_t sceneId) const
{
  for (Node<Scene*>* node = this->m_head; node != nullptr; node = node->next())
    if (node->value()->id() == sceneId)
      return true;
  return false;
}
