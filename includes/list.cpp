/**
*  @file      list.h
*  @brief     Implementation for the list class.
*
*  @author    Evan Elias Young
*  @date      2019-02-26
*  @date      2019-02-26
*  @copyright Copyright 2019 Evan Elias Young. All rights reserved.
*/

#ifndef GPCU_LIST_H_
#define GPCU_LIST_H_

#include "stdafx.h"
#include "list.h"

namespace gpcu
{
/**
* @brief Represents a C#-like array of elements.
* @since 2.4.1-46 (0x020401002E)
*/
template <class T>
class List
{
private:
  /** @brief The underlying collection of elements */
  std::vector<T> elems;

public:
  std::size_t Capacity();
  std::size_t Count();
  void Add(const T &e);
  void Empty();
  bool Contains(const T &e);
  std::size_t IndexOf(const T &e);
  std::size_t IndexOf(const T &e, const std::size_t &j);
  void Insert(const T &e, const std::size_t &i);
  bool Remove(const T &e);
  bool RemoveAt(const std::size_t &i);
  std::string Join(const std::string &s);
  void Sort();
  void Swap(const std::size_t &i, const std::size_t &j);
  T &operator[](const std::size_t &i);
  bool operator==(const List<T> &l);
};

/**
* @brief Returns the total number of elements that can be in the list.
* @since 2.4.1-46 (0x020401002E)
*/
template <class T>
std::size_t List<T>::Capacity()
{
  return elems.capacity();
}

/**
* @brief Returns the current number of elements contained in the list.
* @since 2.4.1-46 (0x020401002E)
*/
template <class T>
std::size_t List<T>::Count()
{
  return elems.size();
}

/**
* @brief Appends one element to the back of the list.
* @since 2.4.1-46 (0x020401002E)
* @param e The element to add to the list.
*/
template <class T>
void List<T>::Add(const T &e)
{
  elems.push_back(e);
}

/**
* @brief Completely empties out the list.
* @since 2.4.1-46 (0x020401002E)
*/
template <class T>
void List<T>::Empty()
{
  elems.empty();
}

/**
* @brief  Searches the list and returns whether or not it contains the element.
* @since  2.4.1-46 (0x020401002E)
* @param  e The element to search for.
* @return   True if the list containes e, false otherwise.
*/
template <class T>
bool List<T>::Contains(const T &e)
{
  for (std::size_t i = 0; i < this->Count(); i++)
  {
    if (elems[i] == e)
    {
      return true;
    }
  }
  return false;
}

/**
* @brief  Returns the position of the element in the list.
* @since  2.4.1-46 (0x020401002E)
* @param  e The element to search for.
* @return   The index of the element, -1 if not found.
*/
template <class T>
std::size_t List<T>::IndexOf(const T &e)
{
  for (std::size_t i = 0; i < this->Count(); i++)
  {
    if (elems[i] == e)
    {
      return i;
    }
  }
  return -1;
}

/**
* @brief  Returns the position of the element in the list after a certain position.
* @since  2.4.1-46 (0x020401002E)
* @param  e The element to search for.
* @param  j The index to start at.
* @return   The index of the element after the given index.
*/
template <class T>
std::size_t List<T>::IndexOf(const T &e, const std::size_t &j)
{
  for (std::size_t i = j; i < this->Count(); i++)
  {
    if (elems[i] == e)
    {
      return i;
    }
  }
  return -1;
}

/**
* @brief Inserts an element into the list at the given position.
* @since 2.4.1-46 (0x020401002E)
* @param e The element to insert.
* @param i The index to insert.
*/
template <class T>
void List<T>::Insert(const T &e, const std::size_t &i)
{
  if (i < 0 || i > this->Count())
  {
    throw std::out_of_range("i must be 0-" + this->Count());
  }
  else
  {
    elems.insert(i, 1, e);
  }
}

/**
* @brief  Removes the first element that matches the given element.
* @since  2.4.1-46 (0x020401002E)
* @param  e The element to match and remove.
* @return   True if the element was removed, false otherwise.
*/
template <class T>
bool List<T>::Remove(const T &e)
{
  if (!this->Contains(e))
  {
    return false;
  }
  this->RemoveAt(this->IndexOf(e));
  return true;
}

/**
* @brief  Removes an element at a given index.
* @since  2.4.1-46 (0x020401002E)
* @param  i The index to remove.
* @return   True if the element was removed, false otherwise.
*/
template <class T>
bool List<T>::RemoveAt(const std::size_t &i)
{
  if (i >= this->Count())
  {
    return false;
  }
  elems.erase(elems.begin() + i);
  return true;
}

/**
* @brief  Joins the elements in the list with a delimiter.
* @since  2.5.2-49 (0x0205020031)
* @param  s The delimiter to join upon.
* @return  The joint elements.
*/
template <class T>
std::string List<T>::Join(const std::string &s)
{
  std::unique_ptr<std::stringstream> ss(new std::stringstream());

  (*ss) << elems[0];
  for (std::size_t i = 1; i < this->Count(); i++)
  {
    (*ss) << s << elems[i];
  }

  return (*ss).str();
}

/**
* @brief Sorts the elements in the list.
* @since 2.5.2-49 (0x0205020031)
*/
template <class T>
void List<T>::Sort()
{
  for (std::size_t k = 0; k < this->Count() / 2; k++)
  {
    std::unique_ptr<int> i(new int(-1));
    std::unique_ptr<T> pivot(new T(elems[this->Count() - 1]));

    for (std::size_t j = 0; j < this->Count() - 1; j++)
    {
      if (elems[j] <= (*pivot))
      {
        this->Swap(++(*i), j);
      }
    }
    this->Swap(++(*i), this->Count() - 1);
  }
}

/**
* @brief Swaps two elements in the array with given indexes.
* @since 2.5.2-49 (0x0205020031)
* @param i The index to swap.
* @param j The index to swap.
*/
template <class T>
void List<T>::Swap(const std::size_t &i, const std::size_t &j)
{
  std::unique_ptr<T> tmp(new T(elems[i]));
  elems[i] = elems[j];
  elems[j] = (*tmp);
}

/**
* @brief  An override for the [] operator.
* @since  2.5.2-49 (0x0205020031)
* @param  i The index to return.
* @return   The element in the list at the given index.
*/
template <class T>
T &List<T>::operator[](const std::size_t &i)
{
  return elems[i];
}

/**
* @brief  An override for the == operator.
* @since  2.5.2-49 (0x0205020031)
* @param  l The other list to compare to.
* @return   True if the lists match, false otherwise.
*/
template <class T>
bool List<T>::operator==(const List<T> &l)
{
  if (this->Count() != l.Count())
  {
    return false;
  }
  for (std::size_t i = 0; i < this->Count(); i++)
  {
    if (elems[i] != l[i])
    {
      return false;
    }
  }
  return true;
}
} // namespace gpcu

#endif // GPCU_LIST_H_
