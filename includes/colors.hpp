//  colors.hpp
//  gpcu
//
//  Created by Evan Elias Young on 2019-01-17.
//  Copyright 2019 Evan Elias Young. All rights reserved.

#ifndef GPCU_COLORS_HPP_  // include guard
#define GPCU_COLORS_HPP_

namespace gpcu {
  std::basic_string<char> getEnvVar(std::basic_string<char> key) {
    char const* val = std::getenv(key.c_str());
    return val == NULL ? std::basic_string<char>() : std::basic_string<char>(val);
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
      std::basic_string<char> term = getEnvVar("TERM");
      std::basic_string<char> colorTerm = getEnvVar("COLORTERM");
      std::basic_string<char> termProgram = getEnvVar("TERM_PROGRAM");

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

    std::basic_string<char> wrapAnsi16(int col, int off) {
      return "\033[" + std::to_string(30 + col + off) + "m";
    }

    std::basic_string<char> wrapAnsi256(int col, int off) {
      return "\033[" + std::to_string(38 + off) + ";5;" + std::to_string(col) + "m";
    }

    namespace wrap {
      std::basic_string<char> wrapper(std::basic_string<char> txt, int col, int off, int term) {
        Support supportLevel = getSupport();
        bool isColor = true;
        if ((col < 10 && off == -30) && (term >= 22 && term <= 28)) {
          isColor = false;
        }

        if ((supportLevel > Support::none) && (supportLevel == Support::basic || !isColor)) {
          return wrapAnsi16(col, off) + txt + wrapAnsi16(term, -30);
        }
        if (supportLevel >= Support::color && !isColor) {
          return wrapAnsi256(col, off - 39) + txt + wrapAnsi16(term, -30);
        }
        return txt;
      }

      std::basic_string<char> bold(std::basic_string<char> txt) { return wrapper(txt, 1, -30, 22); }
      std::basic_string<char> dim(std::basic_string<char> txt) { return wrapper(txt, 2, -30, 22); }
      std::basic_string<char> italic(std::basic_string<char> txt) { return wrapper(txt, 3, -30, 23); }
      std::basic_string<char> underline(std::basic_string<char> txt) { return wrapper(txt, 4, -30, 24); }
      std::basic_string<char> inverse(std::basic_string<char> txt) { return wrapper(txt, 7, -30, 27); }
      std::basic_string<char> hidden(std::basic_string<char> txt) { return wrapper(txt, 8, -30, 28); }
      std::basic_string<char> strikethrough(std::basic_string<char> txt) { return wrapper(txt, 9, -30, 29); }
      std::basic_string<char> black(std::basic_string<char> txt) { return wrapper(txt, Ansi::black, 0, 39); }
      std::basic_string<char> red(std::basic_string<char> txt) { return wrapper(txt, Ansi::red, 0, 39); }
      std::basic_string<char> green(std::basic_string<char> txt) { return wrapper(txt, Ansi::green, 0, 39); }
      std::basic_string<char> yellow(std::basic_string<char> txt) { return wrapper(txt, Ansi::yellow, 0, 39); }
      std::basic_string<char> blue(std::basic_string<char> txt) { return wrapper(txt, Ansi::blue, 0, 39); }
      std::basic_string<char> magenta(std::basic_string<char> txt) { return wrapper(txt, Ansi::magenta, 0, 39); }
      std::basic_string<char> cyan(std::basic_string<char> txt) { return wrapper(txt, Ansi::cyan, 0, 39); }
      std::basic_string<char> white(std::basic_string<char> txt) { return wrapper(txt, Ansi::white, 0, 39); }
      std::basic_string<char> bgBlack(std::basic_string<char> txt) { return wrapper(txt, Ansi::black, 10, 49); }
      std::basic_string<char> bgRed(std::basic_string<char> txt) { return wrapper(txt, Ansi::red, 10, 49); }
      std::basic_string<char> bgGreen(std::basic_string<char> txt) { return wrapper(txt, Ansi::green, 10, 49); }
      std::basic_string<char> bgYellow(std::basic_string<char> txt) { return wrapper(txt, Ansi::yellow, 10, 49); }
      std::basic_string<char> bgBlue(std::basic_string<char> txt) { return wrapper(txt, Ansi::blue, 10, 49); }
      std::basic_string<char> bgMagenta(std::basic_string<char> txt) { return wrapper(txt, Ansi::magenta, 10, 49); }
      std::basic_string<char> bgCyan(std::basic_string<char> txt) { return wrapper(txt, Ansi::cyan, 10, 49); }
      std::basic_string<char> bgWhite(std::basic_string<char> txt) { return wrapper(txt, Ansi::white, 10, 49); }
      std::basic_string<char> blackBright(std::basic_string<char> txt) { return wrapper(txt, Ansi::black, 60, 39); }
      std::basic_string<char> redBright(std::basic_string<char> txt) { return wrapper(txt, Ansi::red, 60, 39); }
      std::basic_string<char> greenBright(std::basic_string<char> txt) { return wrapper(txt, Ansi::green, 60, 39); }
      std::basic_string<char> yellowBright(std::basic_string<char> txt) { return wrapper(txt, Ansi::yellow, 60, 39); }
      std::basic_string<char> blueBright(std::basic_string<char> txt) { return wrapper(txt, Ansi::blue, 60, 39); }
      std::basic_string<char> magentaBright(std::basic_string<char> txt) { return wrapper(txt, Ansi::magenta, 60, 39); }
      std::basic_string<char> cyanBright(std::basic_string<char> txt) { return wrapper(txt, Ansi::cyan, 60, 39); }
      std::basic_string<char> whiteBright(std::basic_string<char> txt) { return wrapper(txt, Ansi::white, 60, 39); }
      std::basic_string<char> bgBlackBright(std::basic_string<char> txt) { return wrapper(txt, Ansi::black, 70, 49); }
      std::basic_string<char> bgRedBright(std::basic_string<char> txt) { return wrapper(txt, Ansi::red, 70, 49); }
      std::basic_string<char> bgGreenBright(std::basic_string<char> txt) { return wrapper(txt, Ansi::green, 70, 49); }
      std::basic_string<char> bgYellowBright(std::basic_string<char> txt) { return wrapper(txt, Ansi::yellow, 70, 49); }
      std::basic_string<char> bgBlueBright(std::basic_string<char> txt) { return wrapper(txt, Ansi::blue, 70, 49); }
      std::basic_string<char> bgMagentaBright(std::basic_string<char> txt) { return wrapper(txt, Ansi::magenta, 70, 49); }
      std::basic_string<char> bgCyanBright(std::basic_string<char> txt) { return wrapper(txt, Ansi::cyan, 70, 49); }
      std::basic_string<char> bgWhiteBright(std::basic_string<char> txt) { return wrapper(txt, Ansi::white, 70, 49); }
    }  // namespace wrap
  }  // namespace colors
}  // namespace gpcu

#endif  // GPCU_COLORS_HPP_
