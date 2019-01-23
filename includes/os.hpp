//  os.hpp
//  gpcu
//
//  Created by Evan Elias Young on 2019-01-18.
//  Copyright 2019 Evan Elias Young. All rights reserved.

#ifndef GPCU_OS_HPP_  // include guard
#define GPCU_OS_HPP_

#include <stdlib.h>

#include <fstream>
#include <string>

#include "join.hpp"
#include "string.hpp"

namespace gpcu {
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
}  // namespace gpcu

#endif  // GPCU_OS_HPP_
