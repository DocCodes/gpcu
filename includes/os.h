/**
*  @file      os.h
*  @brief     Interface for general OS interaction and information.
*
*  @author    Evan Elias Young
*  @date      2019-02-26
*  @date      2019-02-26
*  @copyright Copyright 2019 Evan Elias Young. All rights reserved.
*/

#ifndef GPCU_OS_H_
#define GPCU_OS_H_

#include "stdafx.h"

namespace gpcu
{
enum class OperatingSystemFamily : uint8_t
{
    other,
    DOS,
    win,
    darwin,
    linux,
    solaris
};

enum class OperatingSystem : uint8_t
{
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

std::string getEnvVar(const std::string &key);
OperatingSystemFamily getOSFamily();
OperatingSystem getOS();
std::string joinPath(const std::vector<std::string> &a);
std::string joinPath(const std::string &a, const std::string &b);
std::string getTempDir();
std::string getTempFile();
std::string getOSVer();
} // namespace gpcu

#endif // GPCU_OS_H_
