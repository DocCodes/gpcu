/**
*  @file      list.hpp
*  @brief     Adds a list class to the project.
*
*  @author    Evan Elias Young
*  @date      2019-02-04
*  @date      2019-02-12
*  @copyright Copyright 2019 Evan Elias Young. All rights reserved.
*/

#ifndef GPCU_LIST_HPP_
#define GPCU_LIST_HPP_  0x0100000000

#include <stdlib.h>

#include <exception>
#include <sstream>
#include <string>
#include <vector>

namespace gpcu {
  template <class T>
  class List {
   private:
    std::vector<T> elems;
   public:
    std::size_t Capacity();
    std::size_t Count();
    void Add(const T&);
    void Empty();
    bool Contains(const T&);
    std::size_t IndexOf(const T&);
    std::size_t IndexOf(const T&, const std::size_t&);
    void Insert(const T&, const std::size_t&);
    bool Remove(const T&);
    bool RemoveAt(const std::size_t&);
    std::string Join(const std::string&);
    void Sort();
    void Swap(const std::size_t&, const std::size_t&);
    T& operator[](const std::size_t&);
    bool operator==(const List<T>&);
  };

  template <class T>
  std::size_t List<T>::Capacity() {
    return elems.capacity();
  }

  template <class T>
  std::size_t List<T>::Count() {
    return elems.size();
  }

  template <class T>
  void List<T>::Add(const T& e) {
    elems.push_back(e);
  }

  template <class T>
  void List<T>::Empty() {
    elems.empty();
  }

  template <class T>
  bool List<T>::Contains(const T& e) {
    for (size_t i = 0; i < this->Count(); i++) {
      if (elems[i] == e) {
        return true;
      }
    }
    return false;
  }

  template <class T>
  std::size_t List<T>::IndexOf(const T& e) {
    for (size_t i = 0; i < this->Count(); i++) {
      if (elems[i] == e) {
        return i;
      }
    }
    return -1;
  }

  template <class T>
  std::size_t List<T>::IndexOf(const T& e, const std::size_t& j) {
    for (size_t i = j; i < this->Count(); i++) {
      if (elems[i] == e) {
        return i;
      }
    }
    return -1;
  }

  template <class T>
  void List<T>::Insert(const T& e, const std::size_t& i) {
    if (i < 0 || i > this->Count()) {
      throw std::out_of_range("i must be 0-" + this->Count());
    } else {
      elems.insert(i, 1, e);
    }
  }

  template <class T>
  bool List<T>::Remove(const T& e) {
    if (!this->Contains(e)) {
      return false;
    }
    this->RemoveAt(this->IndexOf(e));
    return true;
  }

  template <class T>
  bool List<T>::RemoveAt(const std::size_t& i) {
    if (i >= this->Count()) {
      return false;
    }
    elems.erase(elems.begin() + i);
    return true;
  }

  template <class T>
  std::string List<T>::Join(const std::string& s) {
    std::stringstream ss;

    ss << elems[0];
    for (std::size_t i = 1; i < this->Count(); i++) {
      ss << s << elems[i];
    }

    return ss.str();
  }

  template <class T>
  void List<T>::Sort() {
    for (size_t k = 0; k < this->Count() / 2; k++) {
      int i = -1;
      T pivot = elems[this->Count() - 1];

      for (std::size_t j = 0; j < this->Count() - 1; j++) {
        if (elems[j] <= pivot) {
          this->Swap(++i, j);
        }
      }
      this->Swap(++i, this->Count() - 1);
    }
  }

  template <class T>
  void List<T>::Swap(const std::size_t& i, const std::size_t& j) {
    T tmp = elems[i];
    elems[i] = elems[j];
    elems[j] = tmp;
  }

  template <class T>
  T& List<T>::operator[](const std::size_t& i) {
    return elems[i];
  }

  template <class T>
  bool List<T>::operator==(const List<T>& l) {
    if (this->Count() != l.Count()) { return false; }
    for (size_t i = 0; i < this->Count(); i++) {
      if (elems[i] != l[i]) { return false; }
    }
    return true;
  }
}  // namespace gpcu

#endif  // GPCU_LIST_HPP_
