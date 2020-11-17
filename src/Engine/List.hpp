#ifndef __LIST_H__
#define __LIST_H__

#include <iostream>
#include <sstream>
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

  virtual void clear();
  List<T>& add(const T& value);
  void addValue(const T& value);
  int size() const { return this->m_counter; }

  T* get(int) const;

  virtual bool remove(const T& value);

  template<typename F>
  T* get(F);
  template<typename Func = void(T*, ...), typename... Args>
  void iterate(Func, Args...);

  virtual bool contains(const T& value);
  bool operator==(const List<T>& rhs) const;

  virtual std::string inspect();

protected:
  Node<T>* m_head;
  Node<T>* m_tail;

  uint64_t m_counter;
};

#include "List.tpp"

#endif // __LIST_H__