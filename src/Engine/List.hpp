#ifndef __LIST_H__
#define __LIST_H__

#include <iostream>
#include <string>

#include "Node.hpp"

template<typename T>
class List
{
public:
  List();
  // List(const List&) = delete;
  ~List();

  // List& operator=(const List&) = delete;

  void clear();
  List<T>& add(T* value);
  void addValue(T* value);
  int size() const { return this->count; }

  T* get(int) const;

  template<typename F>
  bool remove(F);
  template<typename F>
  T* get(F);
  template<typename F>
  bool contains(F) const;
  template<typename Func, typename... Args>
  List<T>& iterate(Func, Args...) const;

  bool operator==(const List<T>& rhs) const;

protected:
  Node<T>* m_head;
  Node<T>* m_tail;
  uint64_t m_counter;
};

#include "List.tpp"

#endif // __LIST_H__