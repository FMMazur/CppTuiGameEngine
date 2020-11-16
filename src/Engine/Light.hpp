#ifndef __LIGHT_H__
#define __LIGHT_H__

#include "Color.hpp"
#include "Component.hpp"
#include "GameObject.hpp"
#include "Vector2.hpp"
#include "Vector3.hpp"

template<class VectorType>
class Light : public Component
{
public:
  Light();
  Light(GameObject* parent);
  Light(Color color);
  Light(GameObject* parent, Color color);
  Light(GameObject* parent, Color& color);
  ~Light();

  virtual std::string inspect();
  virtual std::string class_name();

  Color color();

  VectorType ambient();
  VectorType diffuse();
  VectorType specular();

  Light<VectorType>& ambient(VectorType ambient);
  Light<VectorType>& diffuse(VectorType diffuse);
  Light<VectorType>& specular(VectorType specular);

private:
  Color m_color;

  VectorType m_ambient;
  VectorType m_diffuse;
  VectorType m_specular;
};

using Light3f = Light<Vector3f>;
// using Light2f = Light<Vector2f>;

#endif // __LIGHT_H__