//  gpcu.hpp
//  gpcu
//
//  Created by Evan Young on 2019-01-13.
//  Copyright 2019 Evan Elias Young. All rights reserved.

#ifndef GPCU_GPCU_HPP_  // include guard
#define GPCU_GPCU_HPP_

#include <iostream>
#include <sstream>
#include <string>
#include <regex>
#include <iomanip>

namespace gpcu {
  enum ColorSupport { none, basic, color, full };

  std::string getEnvVar(std::string key) {
    char const* val = std::getenv(key.c_str());
    return val == NULL ? std::string() : std::string(val);
  }

  ColorSupport getColorSupport() {
    std::string term = getEnvVar("TERM");
    std::string colorTerm = getEnvVar("COLORTERM");
    std::string termProgram = getEnvVar("TERM_PROGRAM");

    if (!term.empty()) {
      if (term == "dumb") {
        return none;
      }
      if (std::regex_match(term, std::regex("/-256(color)?$"))) {
        return color;
      }
      if (std::regex_match(term, std::regex("/-16m(color)?$"))) {
        return full;
      }
      if (std::regex_match(term, std::regex("/^screen|^xterm|^vt100|^vt220|^rxvt|color|ansi|cygwin|linux/"))) {
        return basic;
      }
    }
    if (!colorTerm.empty()) {
      if (colorTerm == "truecolor") {
        return full;
      }
      return basic;
    }
    if (!termProgram.empty()) {
      return color;
    }

    return none;
  }

  // <region> Pause
  void pause() {
    std::cout << "Press the enter key to continue . . ." << std::endl;
    std::cin.get();
  }

  void pause(std::string msg) {
    std::cout << msg << std::endl;
    std::cin.get();
  }
  // </region>

  // <region> Join
  std::string join(int a[], size_t size, std::string delim) {
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
  // </region>

  // <region> Average
  double average(int a[], size_t size) {
    double avg = 0;
    for (size_t i = 0; i < size; i++) {
      avg += a[i];
    }
    return avg / size;
  }
  double average(bool a[], size_t size) {
    double avg = 0;
    for (size_t i = 0; i < size; i++) {
      avg += a[i];
    }
    return avg / size;
  }
  double average(float a[], size_t size) {
    double avg = 0;
    for (size_t i = 0; i < size; i++) {
      avg += a[i];
    }
    return avg / size;
  }
  double average(double a[], size_t size) {
    double avg = 0;
    for (size_t i = 0; i < size; i++) {
      avg += a[i];
    }
    return avg / size;
  }
}  // namespace gpcu
// </region>

#endif  // GPCU_GPCU_HPP_
