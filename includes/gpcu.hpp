//  gpcu.hpp
//  gpcu
//
//  Created by Evan Elias Young on 2019-01-22.
//  Copyright 2019 Evan Elias Young. All rights reserved.

#ifndef GPCU_HPP_  // include guard
#define GPCU_HPP_

#include <ctype.h>
#include <stdlib.h>

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>

namespace gpcu {
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

    gpcu::colors::Support getSupport() {
      gpcu::OperatingSystem os = gpcu::getOS();
      std::string term = gpcu::getEnvVar("TERM");
      std::string colorTerm = gpcu::getEnvVar("COLORTERM");
      std::string termProgram = gpcu::getEnvVar("TERM_PROGRAM");

      if (term == "dumb") {
        return none;
      }
      if (os == win32 || os == win64) {
        std::string osVer = gpcu::getOSVer();
        if (std::stof(osVer.substr(0, 2)) >= 10) {
          if (std::stof(osVer.substr(5, osVer.length() - 5)) >= 10586) {
            return std::stof(osVer.substr(5, osVer.length() - 5)) >= 14931 ? full : color;
          }
        }
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

    std::string wrapAnsi256(int col, int off) {
      return "\033[" + std::to_string(38 + off) + ";5;" + std::to_string(col) + "m";
    }

    namespace wrap {
      std::string wrapper(std::string txt, int col, int off, int term) {
        gpcu::colors::Support supportLevel = getSupport();
        bool isColor = true;
        if ((col < 10 && off == -30) && (term >= 22 && term <= 28)) {
          isColor = false;
        }

        if (supportLevel == gpcu::colors::Support::none) {
          return txt;
        }

        if (supportLevel == gpcu::colors::Support::basic || !isColor) {
          return wrapAnsi16(col, off) + txt + wrapAnsi16(term, -30);
        }
        if (supportLevel >= gpcu::colors::Support::color && !isColor) {
          return wrapAnsi256(col, off - 39) + txt + wrapAnsi16(term, -30);
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
      std::string black(std::string txt) { return wrapper(txt, gpcu::colors::Ansi::black, 0, 39); }
      std::string red(std::string txt) { return wrapper(txt, gpcu::colors::Ansi::red, 0, 39); }
      std::string green(std::string txt) { return wrapper(txt, gpcu::colors::Ansi::green, 0, 39); }
      std::string yellow(std::string txt) { return wrapper(txt, gpcu::colors::Ansi::yellow, 0, 39); }
      std::string blue(std::string txt) { return wrapper(txt, gpcu::colors::Ansi::blue, 0, 39); }
      std::string magenta(std::string txt) { return wrapper(txt, gpcu::colors::Ansi::magenta, 0, 39); }
      std::string cyan(std::string txt) { return wrapper(txt, gpcu::colors::Ansi::cyan, 0, 39); }
      std::string white(std::string txt) { return wrapper(txt, gpcu::colors::Ansi::white, 0, 39); }
      std::string bgBlack(std::string txt) { return wrapper(txt, gpcu::colors::Ansi::black, 10, 49); }
      std::string bgRed(std::string txt) { return wrapper(txt, gpcu::colors::Ansi::red, 10, 49); }
      std::string bgGreen(std::string txt) { return wrapper(txt, gpcu::colors::Ansi::green, 10, 49); }
      std::string bgYellow(std::string txt) { return wrapper(txt, gpcu::colors::Ansi::yellow, 10, 49); }
      std::string bgBlue(std::string txt) { return wrapper(txt, gpcu::colors::Ansi::blue, 10, 49); }
      std::string bgMagenta(std::string txt) { return wrapper(txt, gpcu::colors::Ansi::magenta, 10, 49); }
      std::string bgCyan(std::string txt) { return wrapper(txt, gpcu::colors::Ansi::cyan, 10, 49); }
      std::string bgWhite(std::string txt) { return wrapper(txt, gpcu::colors::Ansi::white, 10, 49); }
      std::string blackBright(std::string txt) { return wrapper(txt, gpcu::colors::Ansi::black, 60, 39); }
      std::string redBright(std::string txt) { return wrapper(txt, gpcu::colors::Ansi::red, 60, 39); }
      std::string greenBright(std::string txt) { return wrapper(txt, gpcu::colors::Ansi::green, 60, 39); }
      std::string yellowBright(std::string txt) { return wrapper(txt, gpcu::colors::Ansi::yellow, 60, 39); }
      std::string blueBright(std::string txt) { return wrapper(txt, gpcu::colors::Ansi::blue, 60, 39); }
      std::string magentaBright(std::string txt) { return wrapper(txt, gpcu::colors::Ansi::magenta, 60, 39); }
      std::string cyanBright(std::string txt) { return wrapper(txt, gpcu::colors::Ansi::cyan, 60, 39); }
      std::string whiteBright(std::string txt) { return wrapper(txt, gpcu::colors::Ansi::white, 60, 39); }
      std::string bgBlackBright(std::string txt) { return wrapper(txt, gpcu::colors::Ansi::black, 70, 49); }
      std::string bgRedBright(std::string txt) { return wrapper(txt, gpcu::colors::Ansi::red, 70, 49); }
      std::string bgGreenBright(std::string txt) { return wrapper(txt, gpcu::colors::Ansi::green, 70, 49); }
      std::string bgYellowBright(std::string txt) { return wrapper(txt, gpcu::colors::Ansi::yellow, 70, 49); }
      std::string bgBlueBright(std::string txt) { return wrapper(txt, gpcu::colors::Ansi::blue, 70, 49); }
      std::string bgMagentaBright(std::string txt) { return wrapper(txt, gpcu::colors::Ansi::magenta, 70, 49); }
      std::string bgCyanBright(std::string txt) { return wrapper(txt, gpcu::colors::Ansi::cyan, 70, 49); }
      std::string bgWhiteBright(std::string txt) { return wrapper(txt, gpcu::colors::Ansi::white, 70, 49); }
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

  enum OperatingSystem {
    other,
    DOS,
    linux,
    macOS9,
    macOSX,
    solaris,
    sunOS,
    win16,
    win32,
    win64
  };

  std::string getEnvVar(std::string key) {
    char const* val = std::getenv(key.c_str());
    return val == NULL ? std::string() : std::string(val);
  }

  gpcu::OperatingSystem getOS() {
    #if defined(MSDOS) || defined(__MSDOS__) || defined(_MSDOS) || defined(__DOS__)
    return DOS;
    #elif defined(__linux__)
    return linux;
    #elif defined(macintosh) || defined(Macintosh)
    return macOS9;
    #elif defined(__APPLE__)
    return macOSX;
    #elif defined(sun) || defined(__sun)
    #if defined(__SVR4) || defined(__svr4__)
    return solaris;
    #else
    return sunOS;
    #endif
    #elif defined(_WIN16) || defined(__TOS_WIN__)
    return win16;
    #elif defined(_WIN32) || defined(__WIN32__) || defined(__WINDOWS__)
    return win32;
    #elif defined(_WIN64)
    return win64;
    #else
    return other;
    #endif
  }

  std::string joinPath(std::string a[], size_t size) {
    gpcu::OperatingSystem os = getOS();
    std::string pathSep = "/";

    if (os == DOS || os == win16 || os == win32 || os == win64) {
      pathSep = "\\";
    }

    return gpcu::join(a, size, pathSep);
  }

  std::string getTempDir() {
    gpcu::OperatingSystem os = getOS();
    std::string tempDir = std::string();

    if (os == other) { return tempDir; }
    if (tempDir.empty()) { tempDir = gpcu::getEnvVar("TMP"); }
    if (tempDir.empty()) { tempDir = gpcu::getEnvVar("TEMP"); }
    if (tempDir.empty()) { tempDir = gpcu::getEnvVar("TMPDIR"); }
    if (tempDir.empty()) { tempDir = gpcu::getEnvVar("TEMPDIR"); }
    if (tempDir.empty()) {
      if (!(os == other || os == DOS || os == win16 || os == win32 || os == win64)) {
        tempDir = "/tmp";
      }
    }

    return tempDir;
  }

  std::string getTempFile() {
    std::string tempJoin[2] = { gpcu::getTempDir(), "gpcu.txt" };
    return gpcu::joinPath(tempJoin, 2);
  }

  std::string getOSVer() {
    gpcu::OperatingSystem os = getOS();
    std::string verPath = getTempFile();
    std::string ver = std::string();
    std::ifstream verFile(verPath);
    std::stringstream buffer;

    if (os == DOS || os == win16 || os == win32 || os == win64) {
      std::system(("ver > " + verPath).c_str());
      buffer << verFile.rdbuf();
      ver = buffer.str();
      ver = std::regex_replace(ver, std::regex("\\]?[^\\]]+(\\[|$)"), "");
      ver = ver.substr(8, ver.length() - 8);
    }

    return ver;
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

    std::string& ltrim(std::string& s, const std::string& chars = "\t\n\v\f\r ") {
      s.erase(0, s.find_first_not_of(chars));
      return s;
    }

    std::string& rtrim(std::string& s, const std::string& chars = "\t\n\v\f\r ") {
      s.erase(s.find_last_not_of(chars) + 1);
      return s;
    }

    std::string& trim(std::string& s, const std::string& chars = "\t\n\v\f\r ") {
      return ltrim(rtrim(s, chars), chars);
    }
  }  // namespace string
}  // namespace gpcu

#endif  // GPCU_HPP_
