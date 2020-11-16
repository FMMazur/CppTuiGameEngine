#ifndef __MESH_H__
#define __MESH_H__

#include <sstream>
#include <vector>

#include "Component.hpp"
#include "Texture.hpp"
#include "Vertex.hpp"

class Mesh : public Component
{
public:
  Mesh();
  Mesh(GameObject* parent);
  Mesh(std::vector<Vertex> vertices, std::vector<Texture> textures);
  Mesh(GameObject* parent, std::vector<Vertex> vertices,
       std::vector<Texture> textures);
  Mesh(GameObject* parent, std::vector<Vertex>& vertices,
       std::vector<Texture>& textures);
  ~Mesh();

  virtual std::string inspect();
  virtual std::string class_name();

  std::vector<Vertex>& vertices();
  std::vector<Texture>& textures();

  Mesh& vertices(std::vector<Vertex> vertices);
  Mesh& textures(std::vector<Texture> textures);

private:
  std::vector<Vertex> m_vertices;
  std::vector<Texture> m_textures;
};

#endif // __MESH_H__