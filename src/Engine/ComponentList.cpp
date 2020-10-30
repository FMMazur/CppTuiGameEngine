#include "ComponentList.hpp"

bool ComponentList::remove(const std::string& componentName)
{
  Node<Component>** pp = &this->head;

  for (Node<Component>* prev = nullptr; *pp != nullptr;
       prev = *pp, *pp = prev->next())
    if ((*pp)->value()->class_name() == componentName) {
      Node<Component>* node = *pp;

      if (node == this->tail)
        this->tail = prev;
      *pp = node->next();
      delete node;
      this->count--;
      return true;
    }
  return false;
}

bool ComponentList::remove(uint64_t componentId)
{
  Node<Component>** pp = &this->head;

  for (Node<Component>* prev = nullptr; *pp != nullptr;
       prev = *pp, *pp = prev->next())
    if ((*pp)->value()->get_id() == componentId) {
      Node<Component>* node = *pp;

      if (node == this->tail)
        this->tail = prev;
      *pp = node->next();
      delete node;
      this->count--;
      return true;
    }
  return false;
}

Component* ComponentList::get(const std::string& componentName)
{
  for (Node<Component>* node = this->head; node != nullptr;
       node = node->next()) {
    if (node->value()->class_name() == componentName)
      return node->value();
  }

  return nullptr;
}

Component* ComponentList::get(uint64_t componentId)
{
  for (Node<Component>* node = this->head; node != nullptr;
       node = node->next()) {
    if (node->value()->get_id() == componentId)
      return node->value();
  }

  return nullptr;
}

bool ComponentList::contains(const std::string& componentName) const
{
  for (Node<Component>* node = this->head; node != nullptr; node = node->next())
    if (node->value()->class_name() == componentName)
      return true;
  return false;
}

bool ComponentList::contains(uint64_t componentId) const
{
  for (Node<Component>* node = this->head; node != nullptr; node = node->next())
    if (node->value()->get_id() == componentId)
      return true;
  return false;
}
