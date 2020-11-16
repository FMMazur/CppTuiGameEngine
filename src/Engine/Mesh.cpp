#include "Mesh.hpp"

Mesh::Mesh()
    : Component()
    , m_vertices(std::vector<Vertex>())
    , m_textures(std::vector<Texture>())
{}

Mesh::Mesh(GameObject* parent)
    : Component()
    , m_vertices(std::vector<Vertex>())
    , m_textures(std::vector<Texture>())
{}

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<Texture> textures)
    : Component()
    , m_vertices(vertices)
    , m_textures(textures)
{}

Mesh::Mesh(GameObject* parent, std::vector<Vertex> vertices,
           std::vector<Texture> textures)
    : Component(parent)
    , m_vertices(vertices)
    , m_textures(textures)
{}

Mesh::Mesh(GameObject* parent, std::vector<Vertex>& vertices,
           std::vector<Texture>& textures)
    : Component(parent)
    , m_vertices(vertices)
    , m_textures(textures)
{}

Mesh::~Mesh() {}

std::string Mesh::inspect()
{
  std::stringstream ss;

  ss << "Mesh with " << this->m_vertices.size() << " vertices and "
     << this->m_textures.size() << " textures";

  return ss.str();
}

std::string Mesh::class_name() { return "Mesh"; }

std::vector<Vertex>& Mesh::vertices() { return this->m_vertices; }

std::vector<Texture>& Mesh::textures() { return this->m_textures; }

Mesh& Mesh::vertices(std::vector<Vertex> vertices)
{
  this->m_vertices = vertices;
  return *this;
}

Mesh& Mesh::textures(std::vector<Texture> textures)
{
  this->m_textures = textures;
  return *this;
}
