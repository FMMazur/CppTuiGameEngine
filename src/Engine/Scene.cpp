#include "Scene.hpp"

#include <sstream>

#include "Camera.hpp"
#include "GameObject.hpp"
#include "Light.hpp"
#include "Mesh.hpp"

Scene::Scene(const std::string& name)
    : m_id(create_id())
    , m_name(name)
    , m_objects()
{
  GameObject* cube = new GameObject("Cube", this);
  GameObject* light = new GameObject("Light", this);
  GameObject* camera = new GameObject("Main Camera", this);

  cube->add(new Mesh());
  light->add(new Light3f());
  camera->add(new Camera());
}

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
  return this->m_name == rhs.m_name && this->m_id == rhs.m_id
      && this->m_objects == rhs.m_objects;
}

bool Scene::operator!=(const Scene& rhs) const { return !(*this == rhs); }

Scene& Scene::add(GameObject* gameObject)
{
  this->m_objects.add(this, gameObject);
  return *this;
}

GameObject* Scene::get_object(const std::string& gameObjectName)
{
  return this->m_objects.get(gameObjectName);
}

GameObject* Scene::get_object(uint64_t gameObjectId)
{
  return this->m_objects.get(gameObjectId);
}

Scene& Scene::remove(GameObject* gameObject)
{
  this->m_objects.remove(gameObject);
  return *this;
}

bool Scene::remove(const std::string& gameObjectName)
{
  return this->m_objects.remove(gameObjectName);
}

Scene& Scene::clear_objects()
{
  this->m_objects.clear();
  return *this;
}

uint64_t Scene::id() { return this->m_id; }

const std::string& Scene::name() { return this->m_name; }

GameObjectList& Scene::objects() { return this->m_objects; }

void Scene::name(const std::string& name) { this->m_name = name; }

std::string Scene::inspect()
{
  std::stringstream ss;
  ss << "Scene \"" << this->m_name << "\" contain " << this->m_objects.size()
     << " objects.";

  return ss.str();
}

void Scene::inspection(std::stringstream& ss, size_t tabs)
{
  if (tabs)
    for (size_t i = 0; i < tabs; i++) {
      ss << "\t";
    }

  ss << this->inspect() << std::endl;

  this->objects().iterate(
      [&](GameObject* go) { go->inspection(ss, tabs + 1); });
}

uint64_t Scene::create_id()
{
  static uint64_t counter = 0;

  return counter++;
}
