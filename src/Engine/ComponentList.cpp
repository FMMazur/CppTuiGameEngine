#include "ComponentList.hpp"
#include "GameObject.hpp"

constexpr auto CANT_REMOVE = "Transform";

ComponentList& ComponentList::add(GameObject* gameObject, Component* value)
{
  if (!this->contains(value->class_name())) {
    value->parent(gameObject);
    this->addValue(value);
  }

  return *this;
}

bool ComponentList::remove(const std::string& componentName)
{
  if (componentName == CANT_REMOVE) {
    return false;
  }

  Node<Component*>** pp = &this->m_head;

  for (Node<Component*>* prev = nullptr; *pp != nullptr;
       prev = *pp, pp = prev->next_pointer())
    if ((*pp)->value()->class_name() == componentName) {
      Node<Component*>* node = *pp;

      if (node == this->m_tail)
        this->m_tail = prev;
      *pp = node->next();
      delete node;
      this->m_counter--;
      return true;
    }
  return false;
}

bool ComponentList::remove(uint64_t componentId)
{
  Node<Component*>** pp = &this->m_head;

  for (Node<Component*>* prev = nullptr; *pp != nullptr;
       prev = *pp, pp = prev->next_pointer()) {
    Component* now = (*pp)->value();
    if (now->id() == componentId && now->class_name() != "Transform") {
      Node<Component*>* node = *pp;

      if (node == this->m_tail)
        this->m_tail = prev;
      *pp = node->next();
      delete node;
      this->m_counter--;
      return true;
    }
  }
  return false;
}

bool ComponentList::remove(Component* component)
{
  return this->remove(component->class_name());
}

Component* ComponentList::get(const std::string& componentName)
{
  for (Node<Component*>* node = this->m_head; node != nullptr;
       node = node->next()) {
    if (node->value()->class_name() == componentName)
      return node->value();
  }

  return nullptr;
}

Component* ComponentList::get(uint64_t componentId)
{
  if (componentId == 0)
    return this->m_head->value();
  if (componentId == this->m_counter - 1)
    return this->m_tail->value();

  for (Node<Component*>* node = this->m_head; node != nullptr;
       node = node->next()) {
    if (node->value()->id() == componentId)
      return node->value();
  }

  return nullptr;
}

bool ComponentList::contains(const std::string& componentName) const
{
  for (Node<Component*>* node = this->m_head; node != nullptr;
       node = node->next())
    if (node->value()->class_name() == componentName)
      return true;
  return false;
}

bool ComponentList::contains(uint64_t componentId) const
{
  for (Node<Component*>* node = this->m_head; node != nullptr;
       node = node->next())
    if (node->value()->id() == componentId)
      return true;
  return false;
}

bool ComponentList::contains(Component* value) const
{
  return this->contains(value->id());
}

void ComponentList::clear()
{
  Node<Component*>* component = this->m_head->next();
  this->m_head->next(nullptr);

  while (component != nullptr) {
    Node<Component*>* node = component;

    component = node->next();
    delete node;
    --this->m_counter;
  }

  this->m_tail = this->m_head;
}

ComponentList::~ComponentList()
{ //
  List::clear();
}
