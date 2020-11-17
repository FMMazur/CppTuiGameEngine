#include "Game.hpp"

Game::Game(const std::string& name)
    : m_name(name)
{
  this->m_scenes.add(new Scene("Main Scene"));
}

Game::~Game() {}

Game& Game::add(Scene* scene)
{
  this->m_scenes.add(scene);
  return *this;
}

Game& Game::remove(const std::string& sceneName)
{
  this->m_scenes.remove(sceneName);
  return *this;
}

Game& Game::clear()
{
  this->m_scenes.clear();
  return *this;
}

Scene* Game::get(const std::string& sceneName)
{
  return this->m_scenes.get(sceneName);
}

std::string Game::inspect()
{
  std::stringstream ss;

  ss << this->m_name << " constains " << this->m_scenes.size() << " scenes";

  return ss.str();
}

std::string Game::inspection()
{
  std::stringstream game_inspection;
  game_inspection << this->inspect() << std::endl;
  this->scenes().iterate(
      [&](Scene* scene) { scene->inspection(game_inspection, 1); });

  return game_inspection.str();
}

std::string Game::name() { return this->m_name; }

SceneList& Game::scenes() { return this->m_scenes; }
