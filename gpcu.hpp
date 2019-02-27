//  gpcu.hpp
//  gpcu
//
//  Created by Evan Elias Young on 2019-02-01.
//  Copyright 2019 Evan Elias Young. All rights reserved.

#ifndef GPCU_HPP_
#define GPCU_HPP_

#define GPCU_VERSION_ 0x020401002D

#include <ctype.h>
#include <math.h>
#include <stdlib.h>

#include <algorithm>
#include <exception>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>

namespace gpcu
{
/**
* @brief Represents an RGB color
*/
class Color
{
private:
  /** @brief The red value of the color */
  int red;
  /** @brief The green value of the color */
  int green;
  /** @brief The blue value of the color */
  int blue;
  /** @brief The luminance value of the color */
  int luminance;
  /** @brief The alpha value of the color */
  int alpha;
  /** @brief The hue value of the color */
  int hue;
  /** @brief The saturation value of the color */
  int saturation;
  /** @brief The lightness value of the color */
  int lightness;
  /** @brief The value of the color */
  int value;
  /** @brief The hex value of the color */
  std::string hex;
  void recalcHex();
  void recalcRGB();
  void recalcHSVL();
  void recalcLuminance();

public:
  Color(int, int, int);
  Color(std::string);
  int getRed();
  void setRed(int);
  int getGreen();
  void setGreen(int);
  int getBlue();
  void setBlue(int);
  int getLuminance();
  int getAlpha();
  void setAlpha(int);
  int getHue();
  void setHue(int);
  int getSaturation();
  void setSaturation(int);
  int getLightness();
  void setLightness(int);
  int getValue();
  void setValue(int);
  std::string getHex();
  void setHex(std::string);
};

/**
* @brief Represents an RGB color declared declared by such.
* @param r The red value.
* @param g The green value.
* @param b The blue value.
*/
Color::Color(int r, int g, int b)
{
  red = r;
  green = g;
  blue = b;
  recalcHex();
  recalcHSVL();
  recalcLuminance();
}

/**
* @brief Represents an RGB color declared by hex.
* @param h The hex value.
*/
Color::Color(std::string h)
{
  setHex(h);
}

/**
* @brief Recalculates the hex value for the color object.
*/
void Color::recalcHex()
{
  std::stringstream ss;
  ss << std::setfill('0') << std::setw(2) << std::hex << red << green << blue;
  hex = ss.str();
}

/**
* @brief Recalculates the RGB values for the color object.
*/
void Color::recalcRGB()
{
  std::stringstream ss;
  ss << hex.substr(0, 2);
  ss >> std::hex >> red;
  std::stringstream().swap(ss);
  ss << hex.substr(2, 2);
  ss >> std::hex >> green;
  std::stringstream().swap(ss);
  ss << hex.substr(4, 2);
  ss >> std::hex >> blue;
}

/**
* @brief Recalculates the HSVL values for the color object.
*/
void Color::recalcHSVL()
{
  double min;
  double max;
  double d;
  double r;
  double g;
  double b;

  r = red;
  g = green;
  b = blue;
  r /= 255;
  g /= 255;
  b /= 255;

  min = r < g ? r : g;
  min = min < b ? min : b;
  max = r > g ? r : g;
  max = max > b ? max : b;

  value = ::round(max * 100);
  lightness = ::round((max + min) * 50);
  d = max - min;
  if (d < 0.00001)
  {
    saturation = 0;
    hue = 0;
    return;
  }
  if (max > 0.0)
  {
    saturation = ::round(d / max) * 100;
  }
  else
  {
    saturation = 0;
    hue = 0;
    return;
  }
  hue = r >= max
            ? ::round((g - b) / d * 60)
            : g >= max
                  ? ::round((2 + (b - r) / d) * 60)
                  : ::round((4 + (r - g) / d) * 60);

  if (hue < 0)
  {
    hue += 360;
  }
}

/**
* @brief Recalculates the luminance value for the color object.
*/
void Color::recalcLuminance()
{
  luminance = ::round((red * 0.2126) + (green * 0.7152) + (blue * 0.0722));
}

/**
* @brief Gets the red value.
* @return The red value.
*/
int Color::getRed()
{
  return red;
}

/**
* @brief Sets the red value.
* @param newRed The new red value.
*/
void Color::setRed(int newRed)
{
  if (newRed < 0 || newRed > 255)
  {
    throw std::out_of_range("newRed must be 0-255");
  }
  red = newRed;

  recalcRGB();
  recalcHex();
  recalcHSVL();
  recalcLuminance();
}

/**
* @brief Gets the green value.
* @return The green value.
*/
int Color::getGreen()
{
  return green;
}

/**
* @brief Sets the green value.
* @param newGreen The new green value.
*/
void Color::setGreen(int newGreen)
{
  if (newGreen < 0 || newGreen > 255)
  {
    throw std::out_of_range("newGreen must be 0-255");
  }
  green = newGreen;

  recalcRGB();
  recalcHex();
  recalcHSVL();
  recalcLuminance();
}

/**
* @brief Gets the blue value.
* @return The blue value.
*/
int Color::getBlue()
{
  return blue;
}

/**
* @brief Sets the blue value.
* @param newBlue The new blue value.
*/
void Color::setBlue(int newBlue)
{
  if (newBlue < 0 || newBlue > 255)
  {
    throw std::out_of_range("newBlue must be 0-255");
  }
  blue = newBlue;

  recalcRGB();
  recalcHex();
  recalcHSVL();
  recalcLuminance();
}

/**
* @brief Gets the luminance value.
* @return The luminance value.
*/
int Color::getLuminance()
{
  return luminance;
}

/**
* @brief Gets the alpha value.
* @return The alpha value.
*/
int Color::getAlpha()
{
  return alpha;
}

/**
* @brief Sets the alpha value.
* @param newAlpha The new alpha value.
*/
void Color::setAlpha(int newAlpha)
{
  if (newAlpha < 0 || newAlpha > 255)
  {
    throw std::out_of_range("newAlpha must be 0-255");
  }
  alpha = newAlpha;
}

/**
* @brief Gets the hue value.
* @return The hue value.
*/
int Color::getHue()
{
  return hue;
}

/**
* @brief Sets the hue value.
* @param newHue The new hue value.
*/
void Color::setHue(int newHue)
{
  if (newHue < 0 || newHue > 360)
  {
    throw std::out_of_range("newHue must be 0-360");
  }
  hue = newHue;

  recalcRGB();
  recalcHex();
  recalcLuminance();
}

/**
* @brief Gets the saturation value.
* @return The saturation value.
*/
int Color::getSaturation()
{
  return saturation;
}

/**
* @brief Sets the saturation value.
* @param newSaturation The new saturation value.
*/
void Color::setSaturation(int newSaturation)
{
  if (newSaturation < 0 || newSaturation > 100)
  {
    throw std::out_of_range("newSaturation must be 0-100");
  }
  saturation = newSaturation;

  recalcRGB();
  recalcHex();
  recalcLuminance();
}

/**
* @brief Gets the lightness value.
* @return The lightness value.
*/
int Color::getLightness()
{
  return lightness;
}

/**
* @brief Sets the lightness value.
* @param newLightness The new lightness value.
*/
void Color::setLightness(int newLightness)
{
  if (newLightness < 0 || newLightness > 100)
  {
    throw std::out_of_range("newLightness must be 0-100");
  }
  lightness = newLightness;

  recalcRGB();
  recalcHex();
  recalcHSVL();
}

/**
* @brief Gets the value.
* @return The value.
*/
int Color::getValue()
{
  return value;
}

/**
* @brief Sets the value.
* @param newValue The new value.
*/
void Color::setValue(int newValue)
{
  if (newValue < 0 || newValue > 100)
  {
    throw std::out_of_range("newValue must be 0-100");
  }
  value = newValue;

  recalcRGB();
  recalcHex();
  recalcLuminance();
}

/**
* @brief Gets the luminance value.
* @return The hex value.
*/
std::string Color::getHex()
{
  return hex;
}

/**
* @brief Sets the blue value.
* @param newHex The new hex value.
*/
void Color::setHex(std::string newHex)
{
  if (!std::regex_match(newHex, std::regex("^#?([[:xdigit:]]{3,4}|[[:xdigit:]]{6}|[[:xdigit:]]{8})$")))
  {
    throw std::invalid_argument("invalid value for hex variable");
  }
  newHex = std::regex_replace(newHex, std::regex("#"), "");
  if (newHex.length() <= 4)
  {
    newHex.insert(0, 1, newHex[0]);
    newHex.insert(2, 1, newHex[2]);
    newHex.insert(4, 1, newHex[4]);
    if (newHex.length() == 7)
    {
      newHex.insert(6, 1, newHex[6]);
    }
  }

  hex = newHex;

  recalcRGB();
  recalcHSVL();
  recalcLuminance();
}

namespace colors
{
/** @brief Support levels for console colors */
enum Support : unsigned int
{
  none = 1,
  basic = 16,
  color = 256,
  full = 16777216
};

/** @brief Colors for consoles */
enum Ansi : unsigned short
{
  black,
  red,
  green,
  yellow,
  blue,
  magenta,
  cyan,
  white
};

/**
* @brief Gets the color support levels of the current console
* @return The number of colors supported by the current console.
*/
gpcu::colors::Support getSupport()
{
  gpcu::OperatingSystem os = gpcu::getOS();
  std::string term = gpcu::getEnvVar("TERM");
  std::string colorTerm = gpcu::getEnvVar("COLORTERM");
  std::string termProgram = gpcu::getEnvVar("TERM_PROGRAM");

  if (term == "dumb")
  {
    return none;
  }
  if (os == gpcu::OperatingSystem::win32 || os == gpcu::OperatingSystem::win64)
  {
    std::string osVer = gpcu::getOSVer();
    if (std::stof(osVer.substr(0, 2)) >= 10)
    {
      if (std::stof(osVer.substr(5, osVer.length() - 5)) >= 10586)
      {
        return std::stof(osVer.substr(5, osVer.length() - 5)) >= 14931 ? full : color;
      }
    }
  }
  if (std::regex_match(term, std::regex("/-256(color)?$")))
  {
    return color;
  }
  if (std::regex_match(term, std::regex("/-16m(color)?$")))
  {
    return full;
  }
  if (std::regex_match(term, std::regex("/^screen|^xterm|^vt100|^vt220|^rxvt|color|ansi|cygwin|linux/")))
  {
    return basic;
  }
  if (!colorTerm.empty())
  {
    if (colorTerm == "truecolor")
    {
      return full;
    }
    return basic;
  }
  if (!termProgram.empty())
  {
    return color;
  }

  return none;
}

/**
* @brief Wraps a color and an offset into an Ansi-16 sequence.
* @param  col The color to wrap.
* @param  off The offset value.
* @return     The wrapped Ansi sequence.
*/
std::string wrapAnsi16(int col, int off)
{
  return "\033[" + std::to_string(30 + col + off) + "m";
}

/**
* @brief Wraps a color and an offset into an Ansi-256 sequence.
* @param  col The color to wrap.
* @param  off The offset value.
* @return     The wrapped Ansi sequence.
*/
std::string wrapAnsi256(int col, int off)
{
  return "\033[" + std::to_string(38 + (off % 60)) + ";5;" + std::to_string(off >= 60 ? col + 8 : col) + "m";
}

namespace wrap
{
/**
* Handles all the wrapping for text before returning to the console.
* @param  txt  The text to wrap in the color/format.
* @param  col  The color/format to wrap.
* @param  off  The offset value.
* @param  term The terminator value.
* @return      The complete wrapped Ansi sequence with the terminator.
*/
std::string wrapper(std::string txt, int col, int off, int term)
{
  gpcu::colors::Support supportLevel = getSupport();
  bool isColor = true;
  if ((col < 10 && off == -30) && (term >= 22 && term <= 29))
  {
    isColor = false;
  }

  if (supportLevel == gpcu::colors::Support::basic || !isColor)
  {
    return wrapAnsi16(col, off) + txt + wrapAnsi16(term, -30);
  }
  if (supportLevel >= gpcu::colors::Support::color && isColor)
  {
    return wrapAnsi256(col, off) + txt + wrapAnsi16(term, -30);
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
} // namespace wrap
} // namespace colors

namespace console
{
/**
* @brief Emits a beep noise through the console.
*/
void beep()
{
  std::cout << '\a';
}

/**
* @brief Clears the console screen.
*/
void clear()
{
  std::cout << std::string(100, '\n');
}

/**
* @brief Gets a line of input from stdin.
* @return The line of input without the newline character.
*/
std::string getline()
{
  std::string temp;
  std::getline(std::cin, temp);
  return temp;
}

/**
* @brief Gets a line of input from stdin after outputting to the stdout.
* @param  s The string to send to stdout.
* @return   The line of input without the newline character.
*/
std::string getline(std::string s)
{
  std::string temp;
  std::cout << s;
  std::getline(std::cin, temp);
  return temp;
}

/**
* @brief Writes a line of output to stdout without the newline character.
* @param s The string to send to stdout.
*/
void write(std::string s)
{
  std::cout << s;
}

/**
* @brief Writes a line of output to stdout with the newline character.
* @param s The string to send to stdout.
*/
void writeline(std::string s)
{
  std::cout << s << std::endl;
}
} // namespace console

/**
* @brief Joins an array of integers.
* @param  a     The array of integers to join.
* @param  size  The length of the array.
* @param  delim The joining character.
* @return       The joint string.
*/
std::string join(int a[], std::size_t size, std::string delim)
{
  std::stringstream ss;
  std::size_t i = 0;

  ss << a[i++];
  while (i < size)
  {
    ss << delim << a[i++];
  }

  return ss.str();
}

/**
* @brief Joins an array of chars.
* @param  a     The array of chars to join.
* @param  size  The length of the array.
* @param  delim The joining character.
* @return       The joint string.
*/
std::string join(char a[], std::size_t size, std::string delim)
{
  std::stringstream ss;
  std::size_t i = 0;

  ss << a[i++];
  while (i < size)
  {
    ss << delim << a[i++];
  }

  return ss.str();
}

/**
* @brief Joins an array of bools.
* @param  a     The array of bools to join.
* @param  size  The length of the array.
* @param  delim The joining character.
* @return       The joint string.
*/
std::string join(bool a[], std::size_t size, std::string delim)
{
  std::stringstream ss;
  std::size_t i = 0;

  ss << std::boolalpha;
  ss << a[i++];
  while (i < size)
  {
    ss << delim << a[i++];
  }

  return ss.str();
}

/**
* @brief Joins an array of floats.
* @param  a     The array of floats to join.
* @param  size  The length of the array.
* @param  delim The joining character.
* @return       The joint string.
*/
std::string join(float a[], std::size_t size, std::string delim, int prec = 2)
{
  std::stringstream ss;
  std::size_t i = 0;

  ss << std::fixed << std::setprecision(prec);
  ss << a[i++];
  while (i < size)
  {
    ss << delim << a[i++];
  }

  return ss.str();
}

/**
* @brief Joins an array of doubles.
* @param  a     The array of doubles to join.
* @param  size  The length of the array.
* @param  delim The joining character.
* @return       The joint string.
*/
std::string join(double a[], std::size_t size, std::string delim, int prec = 2)
{
  std::stringstream ss;
  std::size_t i = 0;

  ss << std::fixed << std::setprecision(prec);
  ss << a[i++];
  while (i < size)
  {
    ss << delim << a[i++];
  }

  return ss.str();
}

/**
* @brief Joins an array of strings.
* @param  a     The array of strings to join.
* @param  size  The length of the array.
* @param  delim The joining character.
* @return       The joint string.
*/
std::string join(std::string a[], std::size_t size, std::string delim)
{
  std::stringstream ss;
  std::size_t i = 0;

  ss << a[i++];
  while (i < size)
  {
    ss << delim << a[i++];
  }

  return ss.str();
}

enum class OperatingSystemFamily : unsigned short
{
  other,
  DOS,
  win,
  darwin,
  linux,
  solaris
};

enum class OperatingSystem : unsigned short
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

/**
* @brief Gets an environment variable.
* @param  key The key of the environment variable.
* @return     The environment variable's value.
*/
std::string getEnvVar(std::string key)
{
  char const *val = std::getenv(key.c_str());
  return val == NULL ? std::string() : std::string(val);
}

/**
* @brief Gets the family of the operating system.
* @return The family of the operating system.
*/
gpcu::OperatingSystemFamily getOSFamily()
{
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
gpcu::OperatingSystem getOS()
{
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
std::string joinPath(std::string a[], std::size_t size)
{
  gpcu::OperatingSystemFamily osFamily = gpcu::getOSFamily();
  std::string pathSep = "/";

  if (osFamily == gpcu::OperatingSystemFamily::win || osFamily == gpcu::OperatingSystemFamily::DOS)
  {
    pathSep = "\\";
  }

  return gpcu::join(a, size, pathSep);
}

/**
* @brief Gets the temporary directory depending on the operating system.
* @return The temporary directory.
*/
std::string getTempDir()
{
  gpcu::OperatingSystemFamily osFamily = gpcu::getOSFamily();
  gpcu::OperatingSystem os = gpcu::getOS();
  std::string tempDir = std::string();

  if (os == gpcu::OperatingSystem::other)
  {
    return tempDir;
  }
  if (tempDir.empty())
  {
    tempDir = gpcu::getEnvVar("TMP");
  }
  if (tempDir.empty())
  {
    tempDir = gpcu::getEnvVar("TEMP");
  }
  if (tempDir.empty())
  {
    tempDir = gpcu::getEnvVar("TMPDIR");
  }
  if (tempDir.empty())
  {
    tempDir = gpcu::getEnvVar("TEMPDIR");
  }
  if (tempDir.empty())
  {
    if (!(osFamily == gpcu::OperatingSystemFamily::win || osFamily == gpcu::OperatingSystemFamily::DOS))
    {
      tempDir = "/tmp";
    }
  }

  return tempDir;
}

/**
* @brief Gets the path to a temporary file.
* @return The path to the temporary file.
*/
std::string getTempFile()
{
  std::string tempJoin[2] = {gpcu::getTempDir(), "gpcu.txt"};
  return gpcu::joinPath(tempJoin, 2);
}

/**
* @brief Gets the version of the operating system.
* @return The version of the operating system.
*/
std::string getOSVer()
{
  gpcu::OperatingSystemFamily osFamily = gpcu::getOSFamily();
  std::string verPath = gpcu::getTempFile();
  std::string ver = std::string();
  std::ifstream verFile(verPath);
  std::stringstream buffer;

  if (osFamily == gpcu::OperatingSystemFamily::DOS || osFamily == gpcu::OperatingSystemFamily::win)
  {
    std::system(("ver > " + verPath).c_str());
    buffer << verFile.rdbuf();
    ver = buffer.str();
    ver = std::regex_replace(ver, std::regex("\\]?[^\\]]+(\\[|$)"), "");
    ver = ver.substr(8, ver.length() - 8);
  }

  if (osFamily == gpcu::OperatingSystemFamily::darwin)
  {
    std::system(("sw_vers -productVersion > " + verPath).c_str());
    buffer << verFile.rdbuf();
    ver = buffer.str();
  }

  if (osFamily == gpcu::OperatingSystemFamily::linux)
  {
    std::system(("lsb_release -r" + verPath).c_str());
    buffer << verFile.rdbuf();
    ver = buffer.str();
    ver = ver.substr(9, ver.length() - 9);
  }

  if (osFamily == gpcu::OperatingSystemFamily::solaris)
  {
    std::system(("uname -r" + verPath).c_str());
    buffer << verFile.rdbuf();
    ver = buffer.str();
  }

  return ver;
}

/**
* @brief Pauses the program until the newline character is received.
*/
void pause()
{
  std::cout << "Press the enter key to continue . . ." << std::endl;
  std::cin.get();
}

/**
* @brief Pauses the program with a message until the newline character is received.
* @param msg The message to prompt.
*/
void pause(std::string msg)
{
  std::cout << msg << std::endl;
  std::cin.get();
}

namespace string
{
/**
* @brief Transforms a string to uppercase.
* @param s The string to make uppercase.
*/
void upper(std::string *s)
{
  std::transform((*s).begin(), (*s).end(), (*s).begin(), ::toupper);
}

/**
* @brief Transforms a string to lowercase.
* @param s The string to make lowercase.
*/
void lower(std::string *s)
{
  std::transform((*s).begin(), (*s).end(), (*s).begin(), ::tolower);
}

/**
* @brief Trims away whitespace from the left edge of a string.
* @param  s     The string to trim.
* @param  chars The characters to trim away.
* @return       The string without the trimmed characters.
*/
std::string ltrim(std::string s, const std::string chars = "\t\n\v\f\r ")
{
  s.erase(0, s.find_first_not_of(chars));
  return s;
}

/**
* @brief Trims away whitespace from the right edge of a string.
* @param  s     The string to trim.
* @param  chars The characters to trim away.
* @return       The string without the trimmed characters.
*/
std::string rtrim(std::string s, const std::string chars = "\t\n\v\f\r ")
{
  s.erase(s.find_last_not_of(chars) + 1);
  return s;
}

/**
* @brief Trims away whitespace from both edges of a string.
* @param  s     The string to trim.
* @param  chars The characters to trim away.
* @return       The string without the trimmed characters.
*/
std::string trim(std::string s, const std::string chars = "\t\n\v\f\r ")
{
  return ltrim(rtrim(s, chars), chars);
}

/**
* @brief Counts the occurrences of a string in a string.
* @param  s     The string from which to count occurrences.
* @param  delim The string to count.
* @return       The number of occurrences of a string within a string.
*/
std::size_t count(std::string s, std::string delim)
{
  std::string::size_type ocLast = s.find_last_of(delim);
  std::string::size_type n = 0;
  std::size_t cnt = 0;

  if (ocLast == std::string::npos)
  {
    return 0;
  }
  while (n < ocLast)
  {
    ++cnt;
    n = s.find(delim, n) + delim.length();
  }
  return cnt;
}

/**
* @brief Counts the occurrences of a character in a string.
* @param  s     The string from which to count occurrences.
* @param  delim The character to count.
* @return       The number of occurrences of a character within a string.
*/
std::size_t count(std::string s, char delim)
{
  std::string::size_type ocLast = s.find_last_of(delim);
  std::string::size_type n = 0;
  std::size_t cnt = 0;

  if (ocLast == std::string::npos)
  {
    return 0;
  }
  while (n < ocLast)
  {
    ++cnt;
    n = s.find(delim, n) + 1;
  }
  return cnt;
}

/**
* Splits a string into a collection of smaller parts.
* @param  a     The array of parts.
* @param  s     The string to split.
* @param  delim The characters to split on.
* @param  size  The length of the array.
* @return       Whether or not the split was successful.
*/
bool split(std::string *a, std::string s, std::string delim, std::size_t size)
{
  std::string::size_type beg = 0;
  std::string::size_type end = s.find(delim, beg + 1);
  if (gpcu::string::count(s, delim) + 1 != size)
  {
    return false;
  }

  for (size_t i = 0; i < size; i++)
  {
    a[i] = s.substr(beg, end - beg);
    beg = s.find(delim, end) + delim.length();
    end = s.find(delim, beg);
  }

  return true;
}

/**
* Splits a string into a collection of smaller parts.
* @param  a     The array of parts.
* @param  s     The string to split.
* @param  delim The character to split on.
* @param  size  The length of the array.
* @return       Whether or not the split was successful.
*/
bool split(std::string *a, std::string s, char delim, std::size_t size)
{
  std::string::size_type beg = 0;
  std::string::size_type end = s.find(delim, beg + 1);
  if (gpcu::string::count(s, delim) + 1 != size)
  {
    return false;
  }

  for (size_t i = 0; i < size; i++)
  {
    a[i] = s.substr(beg, end - beg);
    beg = s.find(delim, end) + 1;
    end = s.find(delim, beg);
  }

  return true;
}
} // namespace string
} // namespace gpcu

#endif // GPCU_HPP_
