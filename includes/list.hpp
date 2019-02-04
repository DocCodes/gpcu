/**
*  @file      list.hpp
*  @brief     Adds a list class to the project.
*
*  @author    Evan Elias Young
*  @date      2019-02-04
*  @date      2019-02-04
*  @copyright Copyright 2019 Evan Elias Young. All rights reserved.
*/

#include <exception>
#include <vector>

template <class T>
class List {
private:
  std::vector<T> elems;
public:
  std::vector::size_type Capacity();
  std::vector::size_type Count();
  void Add();
  void Empty();
  bool Contains();
  int IndexOf(T e);
  int IndexOf(T, int);
  void Insert(T, int);
  bool Remove(T);
  bool RemoveAt(int);
};

std::vector::size_type List<T>::Capacity() {
  return elems.capacity()
}

std::vector::size_type List<T>::Count() {
  return elems.size()
}

void List<T>::Add(T e) {
  elems.push_back(e);
}

void List<T>::Empty() {
  elems.empty();
}

bool List<T>::Contains(T e) {
  for (size_t i = 0; i < elems.size(); i++) {
    if (elems[i] == e) {
      return true;
    }
  }
  return false;
}

int List<T>::IndexOf(T e) {
  for (size_t i = 0; i < elems.size(); i++) {
    if (elems[i] == e) {
      return i;
    }
  }
  return -1;
}

int List<T>::IndexOf(T e, int j) {
  for (size_t i = j; i < elems.size(); i++) {
    if (elems[i] == e) {
      return i;
    }
  }
  return -1;
}

void List<T>::Insert(T e, int i) {
  if (i < 0 || i > elems.size()) {
    throw std::out_of_range("i must be 0-" + elems.size());
  } else {
    elems.insert(i, 1, e);
  }
}

bool List<T>::Remove(T e) {
  if (!List<T>.contains(e)) {
    return false;
  }
  List<T>.RemoveAt(List<T>.IndexOf(e));
  return true;
}

bool List<T>::RemoveAt(int i) {
  if (i > elems.size()) {
    return false;
  }
  elems.erase(elems.begin() + i);
  return true;
}
