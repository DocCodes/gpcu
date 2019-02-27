/**
*  @file      os.cpp
*  @brief     Implementation for general OS interaction and information.
*
*  @author    Evan Elias Young
*  @date      2019-02-26
*  @date      2019-02-26
*  @copyright Copyright 2019 Evan Elias Young. All rights reserved.
*/

#include "stdafx.h"
#include "os.h"
#include "join.h"

namespace gpcu
{
/**
* @brief  Gets an environment variable.
* @since  2.1.1-28 (0x020101001C)
* @param  key The key of the environment variable.
* @return     The environment variable's value.
*/
std::string getEnvVar(const std::string &key)
{
    char const *val = std::getenv(key.c_str());
    return val == NULL ? std::string() : std::string(val);
}

/**
* @brief  Gets the family of the operating system.
* @since  2.1.2-35 (0x0201020023)
* @return The family of the operating system.
*/
OperatingSystemFamily getOSFamily()
{
#if defined(MSDOS) || defined(__MSDOS__) || defined(_MSDOS) || defined(__DOS__)
    return OperatingSystemFamily::DOS;
#elif defined(__linux__)
    return OperatingSystemFamily::linux;
#elif defined(macintosh) || defined(Macintosh) || defined(__APPLE__)
    return OperatingSystemFamily::darwin;
#elif defined(sun) || defined(__sun) || defined(__SVR4) || defined(__svr4__)
    return OperatingSystemFamily::solaris;
#elif defined(_WIN16) || defined(__TOS_WIN__) || defined(_WIN32) || defined(__WIN32__) || defined(__WINDOWS__) || defined(_WIN64)
    return OperatingSystemFamily::win;
#else
    return OperatingSystemFamily::other;
#endif
}

/**
* @brief  Gets the operating system currently running.
* @since  2.1.1-28 (0x020101001C)
* @return The operating system.
*/
OperatingSystem getOS()
{
#if defined(MSDOS) || defined(__MSDOS__) || defined(_MSDOS) || defined(__DOS__)
    return OperatingSystem::DOS;
#elif defined(__linux__)
    return OperatingSystem::linux;
#elif defined(macintosh) || defined(Macintosh)
    return OperatingSystem::macOS9;
#elif defined(__APPLE__)
    return OperatingSystem::macOSX;
#elif defined(sun) || defined(__sun)
#if defined(__SVR4) || defined(__svr4__)
    return OperatingSystem::solaris;
#else
    return OperatingSystem::sunOS;
#endif
#elif defined(_WIN16) || defined(__TOS_WIN__)
    return OperatingSystem::win16;
#elif defined(_WIN32) || defined(__WIN32__) || defined(__WINDOWS__)
    return OperatingSystem::win32;
#elif defined(_WIN64)
    return OperatingSystem::win64;
#else
    return OperatingSystem::other;
#endif
}

/**
* @brief  Joins a path depending on the operating system.
* @since  2.6.0-53 (0x0201010035)
* @param  a    The vector of paths.
* @return The joined path.
*/
std::string joinPath(const std::vector<std::string> &a)
{
    std::unique_ptr<OperatingSystemFamily> osFamily(new OperatingSystemFamily(getOSFamily()));
    std::unique_ptr<char> pathSep(new char('/'));

    if ((*osFamily) == OperatingSystemFamily::win || (*osFamily) == OperatingSystemFamily::DOS)
    {
        (*pathSep) = '\\';
    }

    return join(a, (*pathSep));
}

/**
* @brief  Joins a path depending on the operating system.
* @since  2.6.0-53 (0x0201010035)
* @param  a    The first path of the path.
* @param  b    The last path of the path.
* @return The joined path.
*/
std::string joinPath(const std::string &a, const std::string &b)
{
    std::unique_ptr<OperatingSystemFamily> osFamily(new OperatingSystemFamily(getOSFamily()));
    std::unique_ptr<char> pathSep(new char('/'));

    if ((*osFamily) == OperatingSystemFamily::win || (*osFamily) == OperatingSystemFamily::DOS)
    {
        (*pathSep) = '\\';
    }

    return a + (*pathSep) + b;
}

/**
* @brief  Gets the temporary directory depending on the operating system.
* @since  2.1.1-28 (0x020101001C)
* @return The temporary directory.
*/
std::string getTempDir()
{
    std::unique_ptr<OperatingSystemFamily> osFamily(new OperatingSystemFamily(getOSFamily()));
    std::unique_ptr<OperatingSystem> os(new OperatingSystem(getOS()));
    std::unique_ptr<std::string> tempDir(new std::string());

    if ((*os) == OperatingSystem::other)
    {
        return (*tempDir);
    }
    if ((*tempDir).empty())
    {
        (*tempDir) = getEnvVar("TMP");
    }
    if ((*tempDir).empty())
    {
        (*tempDir) = getEnvVar("TEMP");
    }
    if ((*tempDir).empty())
    {
        (*tempDir) = getEnvVar("TMPDIR");
    }
    if ((*tempDir).empty())
    {
        (*tempDir) = getEnvVar("TEMPDIR");
    }
    if ((*tempDir).empty())
    {
        if (!((*osFamily) == OperatingSystemFamily::win || (*osFamily) == OperatingSystemFamily::DOS))
        {
            (*tempDir) = "/tmp";
        }
    }

    return (*tempDir);
}

/**
* @brief  Gets the path to a temporary file.
* @since  2.1.1-28 (0x020101001C)
* @return The path to the temporary file.
*/
std::string getTempFile()
{
    return joinPath(getTempDir(), "gpcu.txt");
}

/**
* @brief  Gets the version of the operating system.
* @since  2.1.2-35 (0x0201020023)
* @return The version of the operating system.
*/
std::string getOSVer()
{
    std::unique_ptr<OperatingSystemFamily> osFamily(new OperatingSystemFamily(getOSFamily()));
    std::unique_ptr<std::string> verPath(new std::string(getTempFile()));
    std::unique_ptr<std::string> ver(new std::string());
    std::unique_ptr<std::ifstream> verFile(new std::ifstream(*verPath));
    std::unique_ptr<std::stringstream> buffer(new std::stringstream());

    if ((*osFamily) == OperatingSystemFamily::DOS || (*osFamily) == OperatingSystemFamily::win)
    {
        std::system(("ver > " + (*verPath)).c_str());
        (*buffer) << (*verFile).rdbuf();
        (*ver) = (*buffer).str();
        (*ver) = std::regex_replace((*ver), std::regex("\\]?[^\\]]+(\\[|$)"), "");
        (*ver) = (*ver).substr(8, (*ver).length() - 8);
    }

    if ((*osFamily) == OperatingSystemFamily::darwin)
    {
        std::system(("sw_vers -productVersion > " + (*verPath)).c_str());
        (*buffer) << (*verFile).rdbuf();
        (*ver) = (*buffer).str();
    }

    if ((*osFamily) == OperatingSystemFamily::linux)
    {
        std::system(("lsb_release -r > " + (*verPath)).c_str());
        (*buffer) << (*verFile).rdbuf();
        (*ver) = (*buffer).str();
        (*ver) = (*ver).substr(9, (*ver).length() - 9);
    }

    if ((*osFamily) == OperatingSystemFamily::solaris)
    {
        std::system(("uname -r > " + (*verPath)).c_str());
        (*buffer) << (*verFile).rdbuf();
        (*ver) = (*buffer).str();
    }

    return (*ver);
}
} // namespace gpcu
