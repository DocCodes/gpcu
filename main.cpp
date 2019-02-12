/**
*  @file      main.cpp
*  @brief     The main entry point for testing and running demos.
*
*  @author    Evan Elias Young
*  @date      2019-01-13
*  @date      2019-02-12
*  @copyright Copyright 2019 Evan Elias Young. All rights reserved.
*/

#include <ctype.h>
#include <stdlib.h>

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>

#include "includes/all.hpp"
#include "tests/all.hpp"

void printVersions() {
  std::cout << "GPCU Version ";
  std::cout << ((GPCU_VERSION_ & 0xFF00000000) >> 32) << '.';
  std::cout << ((GPCU_VERSION_ & 0x00FF000000) >> 24) << '.';
  std::cout << ((GPCU_VERSION_ & 0x0000FF0000) >> 16) << '-';
  std::cout << ((GPCU_VERSION_ & 0x000000FFFF) >> 0) << std::endl;
  std::cout << "     Color   ";
  std::cout << ((GPCU_COLOR_HPP_ & 0xFF00000000) >> 32) << '.';
  std::cout << ((GPCU_COLOR_HPP_ & 0x00FF000000) >> 24) << '.';
  std::cout << ((GPCU_COLOR_HPP_ & 0x0000FF0000) >> 16) << '-';
  std::cout << ((GPCU_COLOR_HPP_ & 0x000000FFFF) >> 0) << std::endl;
  std::cout << "     Colors  ";
  std::cout << ((GPCU_COLORS_HPP_ & 0xFF00000000) >> 32) << '.';
  std::cout << ((GPCU_COLORS_HPP_ & 0x00FF000000) >> 24) << '.';
  std::cout << ((GPCU_COLORS_HPP_ & 0x0000FF0000) >> 16) << '-';
  std::cout << ((GPCU_COLORS_HPP_ & 0x000000FFFF) >> 0) << std::endl;
  std::cout << "     Console ";
  std::cout << ((GPCU_CONSOLE_HPP_ & 0xFF00000000) >> 32) << '.';
  std::cout << ((GPCU_CONSOLE_HPP_ & 0x00FF000000) >> 24) << '.';
  std::cout << ((GPCU_CONSOLE_HPP_ & 0x0000FF0000) >> 16) << '-';
  std::cout << ((GPCU_CONSOLE_HPP_ & 0x000000FFFF) >> 0) << std::endl;
  std::cout << "     Join    ";
  std::cout << ((GPCU_JOIN_HPP_ & 0xFF00000000) >> 32) << '.';
  std::cout << ((GPCU_JOIN_HPP_ & 0x00FF000000) >> 24) << '.';
  std::cout << ((GPCU_JOIN_HPP_ & 0x0000FF0000) >> 16) << '-';
  std::cout << ((GPCU_JOIN_HPP_ & 0x000000FFFF) >> 0) << std::endl;
  std::cout << "     List    ";
  std::cout << ((GPCU_LIST_HPP_ & 0xFF00000000) >> 32) << '.';
  std::cout << ((GPCU_LIST_HPP_ & 0x00FF000000) >> 24) << '.';
  std::cout << ((GPCU_LIST_HPP_ & 0x0000FF0000) >> 16) << '-';
  std::cout << ((GPCU_LIST_HPP_ & 0x000000FFFF) >> 0) << std::endl;
  std::cout << "     OS      ";
  std::cout << ((GPCU_OS_HPP_ & 0xFF00000000) >> 32) << '.';
  std::cout << ((GPCU_OS_HPP_ & 0x00FF000000) >> 24) << '.';
  std::cout << ((GPCU_OS_HPP_ & 0x0000FF0000) >> 16) << '-';
  std::cout << ((GPCU_OS_HPP_ & 0x000000FFFF) >> 0) << std::endl;
  std::cout << "     Pause   ";
  std::cout << ((GPCU_PAUSE_HPP_ & 0xFF00000000) >> 32) << '.';
  std::cout << ((GPCU_PAUSE_HPP_ & 0x00FF000000) >> 24) << '.';
  std::cout << ((GPCU_PAUSE_HPP_ & 0x0000FF0000) >> 16) << '-';
  std::cout << ((GPCU_PAUSE_HPP_ & 0x000000FFFF) >> 0) << std::endl;
  std::cout << "     String  ";
  std::cout << ((GPCU_STRING_HPP_ & 0xFF00000000) >> 32) << '.';
  std::cout << ((GPCU_STRING_HPP_ & 0x00FF000000) >> 24) << '.';
  std::cout << ((GPCU_STRING_HPP_ & 0x0000FF0000) >> 16) << '-';
  std::cout << ((GPCU_STRING_HPP_ & 0x000000FFFF) >> 0) << std::endl;
}

int main(int argc, const char* argv[]) {
  int passing = 0;
  int total = 0;
  int* passingPtr = &passing;
  int* totalPtr = &total;

  printVersions();

  test_colors(passingPtr, totalPtr);
  test_join(passingPtr, totalPtr);
  test_string(passingPtr, totalPtr);

  std::cout << (*passingPtr) << "/" << (*totalPtr) << " total tests passing" << std::endl;

  gpcu::pause();
  return 0;
}
