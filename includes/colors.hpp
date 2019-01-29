/**
*  @file      colors.hpp
*  @brief     Adds methods for coloring stdout.
*
*  @author    Evan Elias Young
*  @date      2019-01-17
*  @date      2019-01-29
*  @copyright Copyright 2019 Evan Elias Young. All rights reserved.
*/

#ifndef GPCU_COLORS_HPP_  // include guard
#define GPCU_COLORS_HPP_

#include <regex>
#include <string>

#include "os.hpp"

namespace gpcu {
  namespace colors {
    /** Support levels for console colors */
    enum Support : unsigned int {
      none = 1,
      basic = 16,
      color = 256,
      full = 16777216
    };

    /** Colors for consoles */
    enum Ansi : unsigned short {
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
    * Gets the color support levels of the current console
    * @return The number of colors supported by the current console.
    */
    gpcu::colors::Support getSupport() {
      gpcu::OperatingSystem os = gpcu::getOS();
      std::string term = gpcu::getEnvVar("TERM");
      std::string colorTerm = gpcu::getEnvVar("COLORTERM");
      std::string termProgram = gpcu::getEnvVar("TERM_PROGRAM");

      if (term == "dumb") {
        return none;
      }
      if (os == gpcu::OperatingSystem::win32 || os == gpcu::OperatingSystem::win64) {
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

    /**
    * Wraps a color and an offset into an Ansi-16 sequence.
    * @param  col The color to wrap.
    * @param  off The offset value.
    * @return     The wrapped Ansi sequence.
    */
    std::string wrapAnsi16(int col, int off) {
      return "\033[" + std::to_string(30 + col + off) + "m";
    }

    /**
    * Wraps a color and an offset into an Ansi-256 sequence.
    * @param  col The color to wrap.
    * @param  off The offset value.
    * @return     The wrapped Ansi sequence.
    */
    std::string wrapAnsi256(int col, int off) {
      return "\033[" + std::to_string(38 + (off % 60)) + ";5;" + std::to_string(off >= 60 ? col + 8 : col) + "m";
    }

    namespace wrap {
      /**
      * Handles all the wrapping for text before returning to the console.
      * @param  txt  The text to wrap in the color/format.
      * @param  col  The color/format to wrap.
      * @param  off  The offset value.
      * @param  term The terminator value.
      * @return      The complete wrapped Ansi sequence with the terminator.
      */
      std::string wrapper(std::string txt, int col, int off, int term) {
        gpcu::colors::Support supportLevel = getSupport();
        bool isColor = true;
        if ((col < 10 && off == -30) && (term >= 22 && term <= 29)) {
          isColor = false;
        }

        if (supportLevel == gpcu::colors::Support::basic || !isColor) {
          return wrapAnsi16(col, off) + txt + wrapAnsi16(term, -30);
        }
        if (supportLevel >= gpcu::colors::Support::color && isColor) {
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
    }  // namespace wrap
  }  // namespace colors
}  // namespace gpcu

#endif  // GPCU_COLORS_HPP_
