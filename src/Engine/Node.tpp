#include "Node.hpp"

template<typename T>
Node<T>::Node(T* value)
{
  this->m_value = value;
  this->m_next = nullptr;
}