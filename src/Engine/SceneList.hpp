#ifndef __SCENELIST_H__
#define __SCENELIST_H__

#include <string>

#include "List.hpp"
#include "Scene.hpp"

class SceneList : public List<Scene>
{
public:
  SceneList() {}
  ~SceneList() {}

  bool remove(const std::string& sceneName);
  bool remove(Scene* scene);
  bool remove(uint64_t sceneId);

  Scene* get(const std::string& sceneName);
  Scene* get(uint64_t sceneId);

  bool contains(const std::string& sceneName) const;
  bool contains(uint64_t sceneId) const;
};

#endif // __SCENELIST_H__