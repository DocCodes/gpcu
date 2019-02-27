/**
*  @file      colors.h
*  @brief     Interface for the methods that color stdout and stderr.
*
*  @author    Evan Elias Young
*  @date      2019-02-26
*  @date      2019-02-27
*  @copyright Copyright 2019 Evan Elias Young. All rights reserved.
*/

#ifndef GPCU_COLORS_H_
#define GPCU_COLORS_H_

#include "stdafx.h"

namespace gpcu
{
namespace colors
{
enum Support : std::uint32_t
{
  none = 1,
  basic = 16,
  color = 256,
  full = 16777216
};

enum Ansi : std::uint8_t
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

Support getSupport();
std::string wrapAnsi16(const std::uint8_t &col, const int &off);
std::string wrapAnsi256(const std::uint32_t &col, const int &off);

namespace wrap
{
std::string wrapper(const std::string &txt, const uint32_t &col, const int &off, const int &term);
std::string bold(const std::string &txt);
std::string dim(const std::string &txt);
std::string italic(const std::string &txt);
std::string underline(const std::string &txt);
std::string inverse(const std::string &txt);
std::string hidden(const std::string &txt);
std::string strikethrough(const std::string &txt);
std::string black(const std::string &txt);
std::string red(const std::string &txt);
std::string green(const std::string &txt);
std::string yellow(const std::string &txt);
std::string blue(const std::string &txt);
std::string magenta(const std::string &txt);
std::string cyan(const std::string &txt);
std::string white(const std::string &txt);
std::string bgBlack(const std::string &txt);
std::string bgRed(const std::string &txt);
std::string bgGreen(const std::string &txt);
std::string bgYellow(const std::string &txt);
std::string bgBlue(const std::string &txt);
std::string bgMagenta(const std::string &txt);
std::string bgCyan(const std::string &txt);
std::string bgWhite(const std::string &txt);
std::string blackBright(const std::string &txt);
std::string redBright(const std::string &txt);
std::string greenBright(const std::string &txt);
std::string yellowBright(const std::string &txt);
std::string blueBright(const std::string &txt);
std::string magentaBright(const std::string &txt);
std::string cyanBright(const std::string &txt);
std::string whiteBright(const std::string &txt);
std::string bgBlackBright(const std::string &txt);
std::string bgRedBright(const std::string &txt);
std::string bgGreenBright(const std::string &txt);
std::string bgYellowBright(const std::string &txt);
std::string bgBlueBright(const std::string &txt);
std::string bgMagentaBright(const std::string &txt);
std::string bgCyanBright(const std::string &txt);
std::string bgWhiteBright(const std::string &txt);
} // namespace wrap
} // namespace colors
} // namespace gpcu

#endif // GPCU_COLORS_H_
