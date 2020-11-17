#ifndef __GAME_H__
#define __GAME_H__

#include <string>

#include "Scene.hpp"
#include "SceneList.hpp"

class Game
{
public:
  Game(const std::string& name);
  virtual ~Game();

  Game& add(Scene* scene);
  Game& remove(const std::string& sceneName);
  Game& clear();

  Scene* get(const std::string& sceneName);

  virtual std::string inspect();
  virtual std::string inspection();

  std::string name();
  void name(std::string name);

  SceneList& scenes();

protected:
  std::string m_name;
  SceneList m_scenes;
};

#endif // __GAME_H__