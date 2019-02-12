/**
*  @file      os.hpp
*  @brief     Adds general OS interaction and information.
*
*  @author    Evan Elias Young
*  @date      2019-01-18
*  @date      2019-02-12
*  @copyright Copyright 2019 Evan Elias Young. All rights reserved.
*/

#ifndef GPCU_OS_HPP_
#define GPCU_OS_HPP_  0x0100000000

#include <stdint.h>
#include <stdlib.h>

#include <fstream>
#include <regex>
#include <string>

#include "join.hpp"

namespace gpcu {
  enum class OperatingSystemFamily : unsigned int8_t {
    other,
    DOS,
    win,
    darwin,
    linux,
    solaris
  };

  enum class OperatingSystem : unsigned int16_t {
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

  /**
  * @brief Gets an environment variable.
  * @param  key The key of the environment variable.
  * @return     The environment variable's value.
  */
  std::string getEnvVar(const std::string& key) {
    char const* val = std::getenv(key.c_str());
    return val == NULL ? std::string() : std::string(val);
  }

  /**
  * @brief Gets the family of the operating system.
  * @return The family of the operating system.
  */
  gpcu::OperatingSystemFamily getOSFamily() {
    #if defined(MSDOS) || defined(__MSDOS__) || defined(_MSDOS) || defined(__DOS__)
    return gpcu::OperatingSystemFamily::DOS;
    #elif defined(__linux__)
    return gpcu::OperatingSystemFamily::linux;
    #elif defined(macintosh) || defined(Macintosh) || defined(__APPLE__)
    return gpcu::OperatingSystemFamily::darwin;
    #elif defined(sun) || defined(__sun) || defined(__SVR4) || defined(__svr4__)
    return gpcu::OperatingSystemFamily::solaris;
    #elif defined(_WIN16) || defined(__TOS_WIN__) || defined(_WIN32) || defined(__WIN32__) || defined(__WINDOWS__) || defined(_WIN64)
    return gpcu::OperatingSystemFamily::win;
    #else
    return gpcu::OperatingSystemFamily::other;
    #endif
  }

  /**
  * @brief Gets the operating system currently running.
  * @return The operating system.
  */
  gpcu::OperatingSystem getOS() {
    #if defined(MSDOS) || defined(__MSDOS__) || defined(_MSDOS) || defined(__DOS__)
    return gpcu::OperatingSystem::DOS;
    #elif defined(__linux__)
    return gpcu::OperatingSystem::linux;
    #elif defined(macintosh) || defined(Macintosh)
    return gpcu::OperatingSystem::macOS9;
    #elif defined(__APPLE__)
    return gpcu::OperatingSystem::macOSX;
    #elif defined(sun) || defined(__sun)
    #if defined(__SVR4) || defined(__svr4__)
    return gpcu::OperatingSystem::solaris;
    #else
    return gpcu::OperatingSystem::sunOS;
    #endif
    #elif defined(_WIN16) || defined(__TOS_WIN__)
    return gpcu::OperatingSystem::win16;
    #elif defined(_WIN32) || defined(__WIN32__) || defined(__WINDOWS__)
    return gpcu::OperatingSystem::win32;
    #elif defined(_WIN64)
    return gpcu::OperatingSystem::win64;
    #else
    return gpcu::OperatingSystem::other;
    #endif
  }

  /**
  * @brief Joins a path depending on the operating system.
  * @param  a    The array of paths.
  * @param  size The size of the array of paths.
  * @return The joined path.
  */
  std::string joinPath(const std::string a[], const std::size_t& size) {
    gpcu::OperatingSystemFamily osFamily = gpcu::getOSFamily();
    std::string pathSep = "/";

    if (osFamily == gpcu::OperatingSystemFamily::win || osFamily == gpcu::OperatingSystemFamily::DOS) {
      pathSep = "\\";
    }

    return gpcu::join(a, size, pathSep);
  }

  /**
  * @brief Gets the temporary directory depending on the operating system.
  * @return The temporary directory.
  */
  std::string getTempDir() {
    gpcu::OperatingSystemFamily osFamily = gpcu::getOSFamily();
    gpcu::OperatingSystem os = gpcu::getOS();
    std::string tempDir = std::string();

    if (os == gpcu::OperatingSystem::other) { return tempDir; }
    if (tempDir.empty()) { tempDir = gpcu::getEnvVar("TMP"); }
    if (tempDir.empty()) { tempDir = gpcu::getEnvVar("TEMP"); }
    if (tempDir.empty()) { tempDir = gpcu::getEnvVar("TMPDIR"); }
    if (tempDir.empty()) { tempDir = gpcu::getEnvVar("TEMPDIR"); }
    if (tempDir.empty()) {
      if (!(osFamily == gpcu::OperatingSystemFamily::win || osFamily == gpcu::OperatingSystemFamily::DOS)) {
        tempDir = "/tmp";
      }
    }

    return tempDir;
  }

  /**
  * @brief Gets the path to a temporary file.
  * @return The path to the temporary file.
  */
  std::string getTempFile() {
    std::string tempJoin[2] = { gpcu::getTempDir(), "gpcu.txt" };
    return gpcu::joinPath(tempJoin, 2);
  }

  /**
  * @brief Gets the version of the operating system.
  * @return The version of the operating system.
  */
  std::string getOSVer() {
    gpcu::OperatingSystemFamily osFamily = gpcu::getOSFamily();
    std::string verPath = gpcu::getTempFile();
    std::string ver = std::string();
    std::ifstream verFile(verPath);
    std::stringstream buffer;

    if (osFamily == gpcu::OperatingSystemFamily::DOS || osFamily == gpcu::OperatingSystemFamily::win) {
      std::system(("ver > " + verPath).c_str());
      buffer << verFile.rdbuf();
      ver = buffer.str();
      ver = std::regex_replace(ver, std::regex("\\]?[^\\]]+(\\[|$)"), "");
      ver = ver.substr(8, ver.length() - 8);
    }

    if (osFamily == gpcu::OperatingSystemFamily::darwin) {
      std::system(("sw_vers -productVersion > " + verPath).c_str());
      buffer << verFile.rdbuf();
      ver = buffer.str();
    }

    if (osFamily == gpcu::OperatingSystemFamily::linux) {
      std::system(("lsb_release -r" + verPath).c_str());
      buffer << verFile.rdbuf();
      ver = buffer.str();
      ver = ver.substr(9, ver.length() - 9);
    }

    if (osFamily == gpcu::OperatingSystemFamily::solaris) {
      std::system(("uname -r" + verPath).c_str());
      buffer << verFile.rdbuf();
      ver = buffer.str();
    }

    return ver;
  }
}  // namespace gpcu

#endif  // GPCU_OS_HPP_
