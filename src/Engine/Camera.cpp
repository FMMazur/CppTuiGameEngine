#include "./Camera.hpp"
#include <sstream>

Camera::Camera()
    : Component()
{}

Camera::Camera(GameObject* parent)
    : Component(parent)
{}

Camera::~Camera() {}

std::string Camera::inspect()
{
  std::stringstream ss;
  ss << this->class_name();

  return ss.str();
}

std::string Camera::class_name() { return "Camera"; }
