#include "List.hpp"
#include <cassert>

template<typename T>
List<T>::List()
{
  this->m_head = this->m_tail = nullptr;
  this->m_counter = 0;
}

template<typename T>
List<T>::~List()
{
  this->clear();
}

template<typename T>
void List<T>::clear()
{
  while (this->m_head != nullptr) {
    Node<T>* node = this->m_head;

    this->m_head = node->next();
    delete node;
  }
}

template<typename T>
List<T>& List<T>::add(T* value)
{
  this->addValue(value);
  return *this;
}

template<typename T>
void List<T>::addValue(T* value)
{
  Node<T>* node = new Node<T>(value);

  if (this->m_tail == nullptr)
    this->m_head = node;
  else {
    this->m_tail->set_next(node);
  }
  this->m_tail = node;
  this->m_counter++;
}

template<typename T>
T* List<T>::get(int index) const
{
  assert(index >= 0 && index < this->m_counter);

  Node<int>* node = this->m_head;

  for (int i = 0; i < index; ++i)
    node = node->next;
  return node->value;
}

template<typename T>
template<typename F>
bool List<T>::remove(F value)
{
  Node<F>** pp = &this->m_head;

  for (Node<F>* prev = nullptr; *pp != nullptr; prev = *pp, pp = &prev->next)
    if ((*pp)->value() == value) {
      Node<F>* node = *pp;

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
    node = node->next;
  return node->value();
}

template<typename T>
template<typename F>
bool List<T>::contains(F value) const
{
  for (Node<T>* node = this->m_head; node != nullptr; node = node->next)
    if (node->value() == value)
      return true;
  return false;
}

template<typename T>
template<typename Func, typename... Args>
List<T>& List<T>::iterate(Func func, Args... args) const
{
  for (Node<T>* node = this->m_head; node != nullptr; node = node->next)
    func(node->value(), args...);

  return this;
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
