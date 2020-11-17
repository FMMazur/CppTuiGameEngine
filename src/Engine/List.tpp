#include "List.hpp"

#include <sstream>

template<typename T>
List<T>::List()
    : m_head(nullptr)
    , m_tail(nullptr)
    , m_counter(0)
{}

template<typename T>
List<T>::~List()
{
  if (this->m_counter)
    this->clear();
}

template<typename T>
void List<T>::clear()
{
  while (this->m_head != nullptr) {
    Node<T>* node = this->m_head;

    this->m_head = node->next();
    delete node;

    --this->m_counter;
  }

  this->m_tail = nullptr;
}

template<typename T>
List<T>& List<T>::add(const T& value)
{
  if (!this->contains(value))
    this->addValue(value);

  return *this;
}

template<typename T>
void List<T>::addValue(const T& value)
{
  Node<T>* node = new Node<T>(value);

  if (this->m_tail == nullptr)
    this->m_head = node;
  else {
    this->m_tail->next(node);
  }
  this->m_tail = node;
  this->m_counter++;
}

template<typename T>
T* List<T>::get(int index) const
{
  if (index >= 0 && index < this->m_counter)
    return nullptr;

  Node<int>* node = this->m_head;

  for (int i = 0; i < index; ++i)
    node = node->next;
  return node->value;
}

template<typename T>
bool List<T>::remove(const T& value)
{
  Node<T>** pp = &this->m_head;

  for (Node<T>* prev = nullptr; *pp != nullptr;
       prev = *pp, pp = prev->next_pointer())
    if ((*pp)->value() == value) {
      Node<T>* node = *pp;

      if (node == this->m_tail)
        this->m_tail = prev;
      *pp = node->next();
      delete node;
      this->m_counter--;
      return true;
    }
  return false;
}

template<typename T>
template<typename F>
T* List<T>::get(F index)
{
  Node<F>* node = this->m_head;

  for (int i = 0; i < index; ++i)
    node = node->next();
  return node->value();
}

template<typename T>
bool List<T>::contains(const T& value)
{
  for (Node<T>* node = this->m_head; node != nullptr; node = node->next())
    if (node->value() == value)
      return true;
  return false;
}

template<typename T>
template<typename Function, typename... Args>
void List<T>::iterate(Function function, Args... args)
{
  for (Node<T>* node = this->m_head; node != nullptr; node = node->next())
    function(node->value(), args...);
}

template<typename T>
bool List<T>::operator==(const List<T>& rhs) const
{
  Node<T>* tmp1 = this->m_head;
  Node<T>* tmp2 = rhs.m_head;

  while (tmp1 && tmp2) {
    if (tmp1->value() != tmp2->value())
      return false;

    tmp1 = tmp1->next();
    tmp2 = tmp2->next();
  }

  if (tmp1 || tmp2)
    return false;

  return true;
}

template<typename T>
std::string List<T>::inspect()
{
  std::stringstream ss;
  ss << "List contains " << this->m_counter << " items";

  return ss.str();
}