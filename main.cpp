/**
*  @file      main.cpp
*  @brief     The main entry point for testing and running demos.
*
*  @author    Evan Elias Young
*  @date      2019-01-13
*  @date      2019-02-26
*  @copyright Copyright 2019 Evan Elias Young. All rights reserved.
*/

#include "includes/stdafx.h"
#include "includes/all.h"
#include "tests/all.h"

void printVersion()
{
  std::cout << "GPCU Version ";
  std::cout << ((GPCU_VERSION_ & 0xFF00000000) >> (8 * 4)) << '.';
  std::cout << ((GPCU_VERSION_ & 0x00FF000000) >> (6 * 4)) << '.';
  std::cout << ((GPCU_VERSION_ & 0x0000FF0000) >> (4 * 4)) << '-';
  std::cout << ((GPCU_VERSION_ & 0x000000FFFF) >> (0 * 4)) << std::endl;
}

int main(int argc, const char *argv[])
{
  std::unique_ptr<int> passing(new int(0));
  std::unique_ptr<int> total(new int(0));

  printVersion();

  test_colors(passing.get(), total.get());
  test_string(passing.get(), total.get());

  std::cout << (*passing) << "/" << (*total) << " total tests passing" << std::endl;

  gpcu::pause();
  return EXIT_OK;
}
