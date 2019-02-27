/**
*  @file      colors.cpp
*  @brief     Implementation for the tests for the colors section of GPCU.
*
*  @author    Evan Elias Young
*  @date      2019-02-27
*  @date      2019-02-27
*  @copyright Copyright 2019 Evan Elias Young. All rights reserved.
*/

#include "../includes/stdafx.h"
#include "../includes/colors.h"
#include "colors.h"

void test_colors_support()
{
  std::cout << "  " << gpcu::colors::wrap::green("+") << " ";
  std::cout << "Colors Supported: " << gpcu::colors::getSupport();
  std::cout << std::endl;
}

void test_colors_other()
{
  std::cout << "  " << gpcu::colors::wrap::green("+") << " ";
  std::cout << gpcu::colors::wrap::bold("BBBBBB") << "   ";
  std::cout << gpcu::colors::wrap::dim("DDDDDD") << "   ";
  std::cout << gpcu::colors::wrap::italic("IIIIII") << "   ";
  std::cout << gpcu::colors::wrap::underline("UUUUUU") << "   ";
  std::cout << gpcu::colors::wrap::inverse("IIIIII") << "   ";
  std::cout << gpcu::colors::wrap::hidden("HHHHHH") << "   ";
  std::cout << gpcu::colors::wrap::strikethrough("SSSSSS") << "   ";
  std::cout << std::endl;
}

void test_colors_color()
{
  std::cout << "  " << gpcu::colors::wrap::green("+") << " ";
  std::cout << gpcu::colors::wrap::black("BBBBBB") << "   ";
  std::cout << gpcu::colors::wrap::red("RRRRRR") << "   ";
  std::cout << gpcu::colors::wrap::green("GGGGGG") << "   ";
  std::cout << gpcu::colors::wrap::yellow("YYYYYY") << "   ";
  std::cout << gpcu::colors::wrap::blue("BBBBBB") << "   ";
  std::cout << gpcu::colors::wrap::magenta("MMMMMM") << "   ";
  std::cout << gpcu::colors::wrap::cyan("CCCCCC") << "   ";
  std::cout << gpcu::colors::wrap::white("WWWWWW") << "   ";
  std::cout << std::endl;
}

void test_colors_bright()
{
  std::cout << "  " << gpcu::colors::wrap::green("+") << " ";
  std::cout << gpcu::colors::wrap::blackBright("BBBBBB") << "   ";
  std::cout << gpcu::colors::wrap::redBright("RRRRRR") << "   ";
  std::cout << gpcu::colors::wrap::greenBright("GGGGGG") << "   ";
  std::cout << gpcu::colors::wrap::yellowBright("YYYYYY") << "   ";
  std::cout << gpcu::colors::wrap::blueBright("BBBBBB") << "   ";
  std::cout << gpcu::colors::wrap::magentaBright("MMMMMM") << "   ";
  std::cout << gpcu::colors::wrap::cyanBright("CCCCCC") << "   ";
  std::cout << gpcu::colors::wrap::whiteBright("WWWWWW") << "   ";
  std::cout << std::endl;
}

void test_colors_bg()
{
  std::cout << "  " << gpcu::colors::wrap::green("+") << " ";
  std::cout << gpcu::colors::wrap::bgBlack("BBBBBB") << "   ";
  std::cout << gpcu::colors::wrap::bgRed("RRRRRR") << "   ";
  std::cout << gpcu::colors::wrap::bgGreen("GGGGGG") << "   ";
  std::cout << gpcu::colors::wrap::bgYellow("YYYYYY") << "   ";
  std::cout << gpcu::colors::wrap::bgBlue("BBBBBB") << "   ";
  std::cout << gpcu::colors::wrap::bgMagenta("MMMMMM") << "   ";
  std::cout << gpcu::colors::wrap::bgCyan("CCCCCC") << "   ";
  std::cout << gpcu::colors::wrap::bgWhite("WWWWWW") << "   ";
  std::cout << std::endl;
}

void test_colors_bgbright()
{
  std::cout << "  " << gpcu::colors::wrap::green("+") << " ";
  std::cout << gpcu::colors::wrap::bgBlackBright("BBBBBB") << "   ";
  std::cout << gpcu::colors::wrap::bgRedBright("RRRRRR") << "   ";
  std::cout << gpcu::colors::wrap::bgGreenBright("GGGGGG") << "   ";
  std::cout << gpcu::colors::wrap::bgYellowBright("YYYYYY") << "   ";
  std::cout << gpcu::colors::wrap::bgBlueBright("BBBBBB") << "   ";
  std::cout << gpcu::colors::wrap::bgMagentaBright("MMMMMM") << "   ";
  std::cout << gpcu::colors::wrap::bgCyanBright("CCCCCC") << "   ";
  std::cout << gpcu::colors::wrap::bgWhiteBright("WWWWWW") << "   ";
  std::cout << std::endl;
}

void test_colors_256()
{
  std::cout << "  " << gpcu::colors::wrap::green("+") << " ";

  for (std::size_t i = 0; i < 216; i++)
  {
    if (i % 36 == 0 && i != 0)
    {
      std::cout << std::endl;
      std::cout << "  " << gpcu::colors::wrap::green("+") << " ";
    }
    if (i % 6 == 0 && i % 36 != 0)
    {
      std::cout << "   ";
    }
    std::cout << gpcu::colors::wrap::wrapper("\u2588", i + 16, 0, 39);

    if ((i + 1) % 36 == 0 && (i + 1) / 36 <= 4)
    {
      std::cout << "            ";
      for (std::size_t x = 0; x < 6; x++)
      {
        std::cout << gpcu::colors::wrap::wrapper("\u2588", ((i + 1) / 36) * 6 + x + 226, 0, 39);
      }
    }
  }
  std::cout << std::endl;
}

bool test_colors(int *passing, int *total)
{
  std::unique_ptr<int> localPassing(new int(12));
  std::unique_ptr<int> localTotal(new int(12));
  std::cout << "Colors" << std::endl;

  test_colors_support();
  test_colors_other();
  test_colors_color();
  test_colors_bright();
  test_colors_bg();
  test_colors_bgbright();
  test_colors_256();

  std::cout << (*localPassing) << "/" << (*localTotal) << " tests passing" << std::endl
            << std::endl;
  (*passing) += (*localPassing);
  (*total) += (*localTotal);
  return true;
}