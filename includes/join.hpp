//  join.hpp
//  gpcu
//
//  Created by Evan Elias Young on 2019-01-17.
//  Copyright 2019 Evan Elias Young. All rights reserved.

#ifndef GPCU_JOIN_HPP_  // include guard
#define GPCU_JOIN_HPP_

namespace gpcu {
  std::basic_string<char> join(int a[], size_t size, std::basic_string<char> delim) {
    std::stringstream ss;
    size_t i = 0;

    ss << a[i++];
    while (i < size) {
      ss << delim << a[i++];
    }

    return ss.str();
  }

  std::string join(char a[], size_t size, std::string delim) {
    std::stringstream ss;
    size_t i = 0;

    ss << a[i++];
    while (i < size) {
      ss << delim << a[i++];
    }

    return ss.str();
  }

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
