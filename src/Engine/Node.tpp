#include "Node.hpp"

#include <type_traits>

template<typename T>
Node<T>::Node(const T& value)
    : m_value(value)
    , m_next(nullptr)
{}

template<typename T>
Node<T>::~Node()
{
  if constexpr (std::is_pointer_v<T>) {
    if (m_value) {
      delete m_value;
    }
  }

  m_next = nullptr;
}