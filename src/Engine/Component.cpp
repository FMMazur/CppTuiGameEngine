#include "Component.hpp"

Component::Component(uint64_t id, GameObject* parent)
    : id(id)
    , parent(parent)
{ }
Component::~Component() { }

uint64_t Component::get_id() { return this->id; }

uint64_t Component::create_id()
{
  static uint64_t id = 0;

  return id++;
}