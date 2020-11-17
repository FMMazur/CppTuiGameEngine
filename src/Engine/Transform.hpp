#ifndef __TRANSFORM_H__
#define __TRANSFORM_H__

#include <cstdint>
#include <string>

#include "Component.hpp"
#include "Vector3.hpp"

class Transform : public Component
{
public:
  Transform();
  Transform(Vector3f position);
  Transform(Vector3f position, Vector3f rotation);
  Transform(Vector3f position, Vector3f rotation, Vector3f scale);

  Transform(GameObject* parent);
  Transform(GameObject* parent, Vector3f position);
  Transform(GameObject* parent, Vector3f position, Vector3f rotation);
  Transform(GameObject* parent, Vector3f position, Vector3f rotation,
            Vector3f scale);
  ~Transform();

  std::string inspect();
  std::string class_name();

protected:
  Vector3f m_position;
  Vector3f m_scale;
  Vector3f m_rotation;
};

#endif // __TRANSFORM_H__