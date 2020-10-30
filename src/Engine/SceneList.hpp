#ifndef __SCENELIST_H__
#define __SCENELIST_H__

#include <string>

#include "List.hpp"
#include "Scene.hpp"

class SceneList : public List<Scene>
{
public:
  SceneList() { }
  ~SceneList() { }

  bool remove(const std::string& sceneName);
  // void add(Scene* value);

  Scene* get(const std::string& sceneName);
  bool contains(const std::string& sceneName) const;
};

#endif // __SCENELIST_H__