#include "Scene.hpp"

Scene::Scene(const char* name)
    : m_name(name)
{ }

Scene::Scene(const std::string& name)
    : m_name(name)
{ }

Scene::~Scene() { }

bool Scene::operator==(const Scene& rhs)
{
  if (this->m_name == rhs.m_name)
    return true;

  return false;
}

bool Scene::operator!=(const Scene& rhs) { return !(*this == rhs); }

const std::string& Scene::name() { return this->m_name; }

const GameObjectList& Scene::objects() { return this->m_objects; }

void Scene::set_name(const std::string& name) { this->m_name = name; }
