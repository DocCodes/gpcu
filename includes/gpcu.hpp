//  gpcu.hpp
//  gpcu
//
//  Created by Evan Elias Young on 2019-01-18.
//  Copyright 2019 Evan Elias Young. All rights reserved.

#ifndef GPCU_HPP_  // include guard
#define GPCU_HPP_

#include <ctype.h>
#include <stdlib.h>

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <regex>

namespace gpcu {
  std::string getEnvVar(std::string key) {
    char const* val = std::getenv(key.c_str());
    return val == NULL ? std::string() : std::string(val);
  }

  namespace colors {
    enum Support {
      none = 1,
      basic = 16,
      color = 256,
      full = 16777216
    };

    enum Ansi {
      black,
      red,
      green,
      yellow,
      blue,
      magenta,
      cyan,
      white
    };

    Support getSupport() {
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

    std::string wrapAnsi16(int col, int off) {
      return "\033[" + std::to_string(30 + col + off) + "m";
    }

    namespace wrap {
      std::string wrapper(std::string txt, int col, int off, int term) {
        if (getSupport() >= Support::basic) {
          return wrapAnsi16(col, off) + txt + wrapAnsi16(term, -30);
        }
        return txt;
      }

      std::string bold(std::string txt) { return wrapper(txt, 1, -30, 22); }
      std::string dim(std::string txt) { return wrapper(txt, 2, -30, 22); }
      std::string italic(std::string txt) { return wrapper(txt, 3, -30, 23); }
      std::string underline(std::string txt) { return wrapper(txt, 4, -30, 24); }
      std::string inverse(std::string txt) { return wrapper(txt, 7, -30, 27); }
      std::string hidden(std::string txt) { return wrapper(txt, 8, -30, 28); }
      std::string strikethrough(std::string txt) { return wrapper(txt, 9, -30, 29); }
      std::string black(std::string txt) { return wrapper(txt, Ansi::black, 0, 39); }
      std::string red(std::string txt) { return wrapper(txt, Ansi::red, 0, 39); }
      std::string green(std::string txt) { return wrapper(txt, Ansi::green, 0, 39); }
      std::string yellow(std::string txt) { return wrapper(txt, Ansi::yellow, 0, 39); }
      std::string blue(std::string txt) { return wrapper(txt, Ansi::blue, 0, 39); }
      std::string magenta(std::string txt) { return wrapper(txt, Ansi::magenta, 0, 39); }
      std::string cyan(std::string txt) { return wrapper(txt, Ansi::cyan, 0, 39); }
      std::string white(std::string txt) { return wrapper(txt, Ansi::white, 0, 39); }
      std::string bgBlack(std::string txt) { return wrapper(txt, Ansi::black, 10, 49); }
      std::string bgRed(std::string txt) { return wrapper(txt, Ansi::red, 10, 49); }
      std::string bgGreen(std::string txt) { return wrapper(txt, Ansi::green, 10, 49); }
      std::string bgYellow(std::string txt) { return wrapper(txt, Ansi::yellow, 10, 49); }
      std::string bgBlue(std::string txt) { return wrapper(txt, Ansi::blue, 10, 49); }
      std::string bgMagenta(std::string txt) { return wrapper(txt, Ansi::magenta, 10, 49); }
      std::string bgCyan(std::string txt) { return wrapper(txt, Ansi::cyan, 10, 49); }
      std::string bgWhite(std::string txt) { return wrapper(txt, Ansi::white, 10, 49); }
      std::string blackBright(std::string txt) { return wrapper(txt, Ansi::black, 60, 39); }
      std::string redBright(std::string txt) { return wrapper(txt, Ansi::red, 60, 39); }
      std::string greenBright(std::string txt) { return wrapper(txt, Ansi::green, 60, 39); }
      std::string yellowBright(std::string txt) { return wrapper(txt, Ansi::yellow, 60, 39); }
      std::string blueBright(std::string txt) { return wrapper(txt, Ansi::blue, 60, 39); }
      std::string magentaBright(std::string txt) { return wrapper(txt, Ansi::magenta, 60, 39); }
      std::string cyanBright(std::string txt) { return wrapper(txt, Ansi::cyan, 60, 39); }
      std::string whiteBright(std::string txt) { return wrapper(txt, Ansi::white, 60, 39); }
      std::string bgBlackBright(std::string txt) { return wrapper(txt, Ansi::black, 70, 49); }
      std::string bgRedBright(std::string txt) { return wrapper(txt, Ansi::red, 70, 49); }
      std::string bgGreenBright(std::string txt) { return wrapper(txt, Ansi::green, 70, 49); }
      std::string bgYellowBright(std::string txt) { return wrapper(txt, Ansi::yellow, 70, 49); }
      std::string bgBlueBright(std::string txt) { return wrapper(txt, Ansi::blue, 70, 49); }
      std::string bgMagentaBright(std::string txt) { return wrapper(txt, Ansi::magenta, 70, 49); }
      std::string bgCyanBright(std::string txt) { return wrapper(txt, Ansi::cyan, 70, 49); }
      std::string bgWhiteBright(std::string txt) { return wrapper(txt, Ansi::white, 70, 49); }
    }  // namespace wrap
  }  // namespace colors

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

  void pause() {
    std::cout << "Press the enter key to continue . . ." << std::endl;
    std::cin.get();
  }

  void pause(std::string msg) {
    std::cout << msg << std::endl;
    std::cin.get();
  }

  namespace string {
    void upper(std::string* s) {
      std::transform((*s).begin(), (*s).end(), (*s).begin(), ::toupper);
    }
    void lower(std::string* s) {
      std::transform((*s).begin(), (*s).end(), (*s).begin(), ::tolower);
    }
  }  // namespace string
}  // namespace gpcu

#endif  // GPCU_HPP_
