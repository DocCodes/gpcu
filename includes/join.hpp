//  join.hpp
//  gpcu
//
//  Created by Evan Elias Young on 2019-01-17.
//  Copyright 2019 Evan Elias Young. All rights reserved.

#ifndef GPCU_JOIN_HPP_  // include guard
#define GPCU_JOIN_HPP_

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

namespace gpcu {
  /**
   * Joins an array of integers.
   * @param  a     The array of integers to join.
   * @param  size  The length of the array.
   * @param  delim The joining character.
   * @return       The joint string.
   */
  std::string join(int a[], size_t size, std::string delim) {
    std::stringstream ss;
    size_t i = 0;

    ss << a[i++];
    while (i < size) {
      ss << delim << a[i++];
    }

    return ss.str();
  }

  /**
   * Joins an array of chars.
   * @param  a     The array of chars to join.
   * @param  size  The length of the array.
   * @param  delim The joining character.
   * @return       The joint string.
   */
  std::string join(char a[], size_t size, std::string delim) {
    std::stringstream ss;
    size_t i = 0;

    ss << a[i++];
    while (i < size) {
      ss << delim << a[i++];
    }

    return ss.str();
  }

  /**
   * Joins an array of bools.
   * @param  a     The array of bools to join.
   * @param  size  The length of the array.
   * @param  delim The joining character.
   * @return       The joint string.
   */
  std::string join(bool a[], size_t size, std::string delim) {
    std::stringstream ss;
    size_t i = 0;

    ss << std::boolalpha;
    ss << a[i++];
    while (i < size) {
      ss << delim << a[i++];
    }

    return ss.str();
  }

  /**
   * Joins an array of floats.
   * @param  a     The array of floats to join.
   * @param  size  The length of the array.
   * @param  delim The joining character.
   * @return       The joint string.
   */
  std::string join(float a[], size_t size, std::string delim, int prec = 2) {
    std::stringstream ss;
    size_t i = 0;

    ss << std::fixed << std::setprecision(prec);
    ss << a[i++];
    while (i < size) {
      ss << delim << a[i++];
    }

    return ss.str();
  }

  /**
   * Joins an array of doubles.
   * @param  a     The array of doubles to join.
   * @param  size  The length of the array.
   * @param  delim The joining character.
   * @return       The joint string.
   */
  std::string join(double a[], size_t size, std::string delim, int prec = 2) {
    std::stringstream ss;
    size_t i = 0;

    ss << std::fixed << std::setprecision(prec);
    ss << a[i++];
    while (i < size) {
      ss << delim << a[i++];
    }

    return ss.str();
  }

  /**
   * Joins an array of strings.
   * @param  a     The array of strings to join.
   * @param  size  The length of the array.
   * @param  delim The joining character.
   * @return       The joint string.
   */
  std::string join(std::string a[], size_t size, std::string delim) {
    std::stringstream ss;
    size_t i = 0;

    ss << a[i++];
    while (i < size) {
      ss << delim << a[i++];
    }

    return ss.str();
  }
}  // namespace gpcu
// </region>

#endif  // GPCU_JOIN_HPP_
