/**
*  @file      main.cpp
*  @brief     The main entry point for testing and running demos.
*
*  @author    Evan Elias Young
*  @date      2019-01-13
*  @date      2019-02-19
*  @copyright Copyright 2019 Evan Elias Young. All rights reserved.
*/

#include <cctype>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>

#include "includes/all.hpp"
#include "tests/all.hpp"

void printVersion() {
  std::cout << "GPCU Version ";
  std::cout << ((GPCU_VERSION_ & 0xFF00000000) >> 32) << '.';
  std::cout << ((GPCU_VERSION_ & 0x00FF000000) >> 24) << '.';
  std::cout << ((GPCU_VERSION_ & 0x0000FF0000) >> 16) << '-';
  std::cout << ((GPCU_VERSION_ & 0x000000FFFF) >> 0) << std::endl;
}

int main(int argc, const char* argv[]) {
  int passing = 0;
  int total = 0;
  int* passingPtr = &passing;
  int* totalPtr = &total;

  printVersion();

  test_colors(passingPtr, totalPtr);
  test_join(passingPtr, totalPtr);
  test_string(passingPtr, totalPtr);

  std::cout << (*passingPtr) << "/" << (*totalPtr) << " total tests passing" << std::endl;

  gpcu::pause();
  return 0;
}
