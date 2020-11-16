#ifndef __VERTEX_H__
#define __VERTEX_H__

#include "Vector2.hpp"
#include "Vector3.hpp"

class Vertex
{
public:
  Vertex(Vector3f position, Vector3f normal, Vector2f texture_coord) {}
  ~Vertex() {}

  Vector3f position() { return this->m_position; }
  Vector3f normal() { return this->m_normal; }
  Vector2f texture_coord() { return this->m_texture_coord; }

  void set_position(Vector3f position) { this->m_position = position; }
  void set_normal(Vector3f normal) { this->m_normal = normal; }
  void set_texture_coord(Vector2f texture_coord)
  {
    this->m_texture_coord = texture_coord;
  }

private:
  Vector3f m_position;
  Vector3f m_normal;
  Vector2f m_texture_coord;
};

#endif // __VERTEX_H__