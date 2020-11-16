#ifndef __CAMERA_H__
#define __CAMERA_H__

#include "Component.hpp"
#include "GameObject.hpp"

class Camera : public Component
{
public:
  Camera();
  Camera(GameObject* parent);
  ~Camera();

  virtual std::string inspect();
  virtual std::string class_name();

private:
};

#endif // __CAMERA_H__