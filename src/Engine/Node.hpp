#ifndef __NODE_H__
#define __NODE_H__

template<typename T>
class Node
{
public:
  Node(T* value);
  ~Node();

  T* value() { return this->m_value; }
  Node<T>* next() { return this->m_next; }
  Node<T>* next() const { return &this->m_next; }

  Node<T>** next_pointer() { return &this->m_next; }

  Node<T>* next(Node<T>* value)
  {
    this->m_next = value;
    return this->m_next;
  }

protected:
  T* m_value;
  Node<T>* m_next;
};

#include "Node.tpp"
#endif // __NODE_H__