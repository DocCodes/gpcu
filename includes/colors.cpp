/**
*  @file      colors.cpp
*  @brief     Implementation for the methods that color stdout and stderr.
*
*  @author    Evan Elias Young
*  @date      2019-02-26
*  @date      2019-02-27
*  @copyright Copyright 2019 Evan Elias Young. All rights reserved.
*/

#include "stdafx.h"
#include "colors.h"
#include "os.h"

namespace gpcu
{
namespace colors
{
/**
* @brief  Gets the color support levels of the current console.
* @since  2.2.0-37 (0x0202000025)
* @return The number of colors supported by the current console.
*/
gpcu::colors::Support getSupport()
{
  OperatingSystem os = gpcu::getOS();
  std::string term = gpcu::getEnvVar("TERM");
  std::string colorTerm = gpcu::getEnvVar("COLORTERM");
  std::string termProgram = gpcu::getEnvVar("TERM_PROGRAM");

  if (term == "dumb")
  {
    return none;
  }
  if (os == OperatingSystem::win32 || os == OperatingSystem::win64)
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
* @brief  Wraps a color and an offset into an Ansi-16 sequence.
* @since  2.2.0-37 (0x0202000025)
* @param  col The color to wrap.
* @param  off The offset value.
* @return     The wrapped Ansi sequence.
*/
std::string wrapAnsi16(const std::uint8_t &col, const int &off)
{
  return "\033[" + std::to_string(30 + col + off) + "m";
}

/**
* @brief  Wraps a color and an offset into an Ansi-256 sequence.
* @since  2.2.0-37 (0x0202000025)
* @param  col The color to wrap.
* @param  off The offset value.
* @return     The wrapped Ansi sequence.
*/
std::string wrapAnsi256(const std::uint32_t &col, const int &off)
{
  return "\033[" + std::to_string(38 + (off % 60)) + ";5;" + std::to_string(off >= 60 ? col + 8 : col) + "m";
}

namespace wrap
{
/**
* @brief  Handles all the wrapping for text before returning to the console.
* @param  txt  The text to wrap in the color/format.
* @param  col  The color/format to wrap.
* @param  off  The offset value.
* @param  term The terminator value.
* @return      The complete wrapped Ansi sequence with the terminator.
*/
std::string wrapper(const std::string &txt, const uint32_t &col, const int &off, const int &term)
{
  colors::Support supportLevel = getSupport();
  bool isColor = true;
  if ((col < 10 && off == -30) && (term >= 22 && term <= 29))
  {
    isColor = false;
  }

  if (supportLevel == colors::Support::basic || !isColor)
  {
    return wrapAnsi16(col, off) + txt + wrapAnsi16(term, -30);
  }
  if (supportLevel >= colors::Support::color && isColor)
  {
    return wrapAnsi256(col, off) + txt + wrapAnsi16(term, -30);
  }
  return txt;
}

std::string bold(const std::string &txt) { return wrapper(txt, 1, -30, 22); }
std::string dim(const std::string &txt) { return wrapper(txt, 2, -30, 22); }
std::string italic(const std::string &txt) { return wrapper(txt, 3, -30, 23); }
std::string underline(const std::string &txt) { return wrapper(txt, 4, -30, 24); }
std::string inverse(const std::string &txt) { return wrapper(txt, 7, -30, 27); }
std::string hidden(const std::string &txt) { return wrapper(txt, 8, -30, 28); }
std::string strikethrough(const std::string &txt) { return wrapper(txt, 9, -30, 29); }
std::string black(const std::string &txt) { return wrapper(txt, colors::Ansi::black, 0, 39); }
std::string red(const std::string &txt) { return wrapper(txt, colors::Ansi::red, 0, 39); }
std::string green(const std::string &txt) { return wrapper(txt, colors::Ansi::green, 0, 39); }
std::string yellow(const std::string &txt) { return wrapper(txt, colors::Ansi::yellow, 0, 39); }
std::string blue(const std::string &txt) { return wrapper(txt, colors::Ansi::blue, 0, 39); }
std::string magenta(const std::string &txt) { return wrapper(txt, colors::Ansi::magenta, 0, 39); }
std::string cyan(const std::string &txt) { return wrapper(txt, colors::Ansi::cyan, 0, 39); }
std::string white(const std::string &txt) { return wrapper(txt, colors::Ansi::white, 0, 39); }
std::string bgBlack(const std::string &txt) { return wrapper(txt, colors::Ansi::black, 10, 49); }
std::string bgRed(const std::string &txt) { return wrapper(txt, colors::Ansi::red, 10, 49); }
std::string bgGreen(const std::string &txt) { return wrapper(txt, colors::Ansi::green, 10, 49); }
std::string bgYellow(const std::string &txt) { return wrapper(txt, colors::Ansi::yellow, 10, 49); }
std::string bgBlue(const std::string &txt) { return wrapper(txt, colors::Ansi::blue, 10, 49); }
std::string bgMagenta(const std::string &txt) { return wrapper(txt, colors::Ansi::magenta, 10, 49); }
std::string bgCyan(const std::string &txt) { return wrapper(txt, colors::Ansi::cyan, 10, 49); }
std::string bgWhite(const std::string &txt) { return wrapper(txt, colors::Ansi::white, 10, 49); }
std::string blackBright(const std::string &txt) { return wrapper(txt, colors::Ansi::black, 60, 39); }
std::string redBright(const std::string &txt) { return wrapper(txt, colors::Ansi::red, 60, 39); }
std::string greenBright(const std::string &txt) { return wrapper(txt, colors::Ansi::green, 60, 39); }
std::string yellowBright(const std::string &txt) { return wrapper(txt, colors::Ansi::yellow, 60, 39); }
std::string blueBright(const std::string &txt) { return wrapper(txt, colors::Ansi::blue, 60, 39); }
std::string magentaBright(const std::string &txt) { return wrapper(txt, colors::Ansi::magenta, 60, 39); }
std::string cyanBright(const std::string &txt) { return wrapper(txt, colors::Ansi::cyan, 60, 39); }
std::string whiteBright(const std::string &txt) { return wrapper(txt, colors::Ansi::white, 60, 39); }
std::string bgBlackBright(const std::string &txt) { return wrapper(txt, colors::Ansi::black, 70, 49); }
std::string bgRedBright(const std::string &txt) { return wrapper(txt, colors::Ansi::red, 70, 49); }
std::string bgGreenBright(const std::string &txt) { return wrapper(txt, colors::Ansi::green, 70, 49); }
std::string bgYellowBright(const std::string &txt) { return wrapper(txt, colors::Ansi::yellow, 70, 49); }
std::string bgBlueBright(const std::string &txt) { return wrapper(txt, colors::Ansi::blue, 70, 49); }
std::string bgMagentaBright(const std::string &txt) { return wrapper(txt, colors::Ansi::magenta, 70, 49); }
std::string bgCyanBright(const std::string &txt) { return wrapper(txt, colors::Ansi::cyan, 70, 49); }
std::string bgWhiteBright(const std::string &txt) { return wrapper(txt, colors::Ansi::white, 70, 49); }
} // namespace wrap
} // namespace colors
} // namespace gpcu