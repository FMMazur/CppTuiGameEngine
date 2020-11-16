#include "Scene.hpp"

Scene::Scene(const char* name)
    : Scene(std::string(name))
{}

Scene::Scene(const std::string& name)
    : m_id(create_id())
    , m_name(name)
{}

Scene::~Scene() {}

Comparator Scene::compare(const Scene& scene)
{
  Comparator status = Comparator::PARCIAL;
  Comparator allStatus[]
      = { Comparator::NOT_EQUAL, Comparator::NOT_EQUAL, Comparator::NOT_EQUAL };
  if (this->m_name == scene.m_name)
    allStatus[0] = Comparator::EQUAL;
  if (this->m_id == scene.m_id)
    allStatus[1] = Comparator::EQUAL;
  if (&this->m_objects == &scene.m_objects) // TODO: update
    allStatus[2] = Comparator::EQUAL;

  if (allStatus[0] == Comparator::EQUAL && allStatus[1] == Comparator::EQUAL
      && allStatus[2] == Comparator::EQUAL)
    status = Comparator::EQUAL;
  else if (allStatus[0] == Comparator::NOT_EQUAL
           && allStatus[1] == Comparator::NOT_EQUAL
           && allStatus[2] == Comparator::NOT_EQUAL)
    status = Comparator::NOT_EQUAL;

  return status;
}

bool Scene::operator==(const Scene& rhs) const
{
  return this->m_name == rhs.m_name /* && this->m_id == rhs.m_id
      && this->m_objects == rhs.m_objects */
      ;
}

bool Scene::operator!=(const Scene& rhs) const { return !(*this == rhs); }

uint64_t Scene::id() { return this->m_id; }

const std::string& Scene::name() { return this->m_name; }

const GameObjectList& Scene::objects() { return this->m_objects; }

void Scene::set_name(const std::string& name) { this->m_name = name; }

uint64_t Scene::create_id()
{
  static uint64_t counter = 0;

  return counter++;
}
