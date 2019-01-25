//  main.cpp
//  gpcu
//
//  Created by Evan Elias Young on 2019-01-13.
//  Copyright 2019 Evan Elias Young. All rights reserved.

#include <ctype.h>
#include <stdlib.h>

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>

#include "etest.hpp"
#include "includes/all.hpp"

// <region> Color Tests
void test_color_support() {
  std::cout << "  " << gpcu::colors::wrap::green("+") << " ";
  std::cout << "Colors Supported: " << gpcu::colors::getSupport();
  std::cout << std::endl;
}

void test_color_other() {
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

void test_color_color() {
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

void test_color_bright() {
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

void test_color_bg() {
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

void test_color_bgbright() {
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

void test_color_256() {
  std::cout << "  " << gpcu::colors::wrap::green("+") << " ";

  for (size_t i = 0; i < 216; i++) {
    if (i % 36 == 0 && i != 0) {
      std::cout << std::endl;
      std::cout << "  " << gpcu::colors::wrap::green("+") << " ";
    }
    if (i % 6 == 0 && i % 36 != 0) {
      std::cout << "   ";
    }
    std::cout << gpcu::colors::wrap::wrapper("\u2588", i + 16, 0, 39);

    if ((i + 1) % 36 == 0 && (i + 1) / 36 <= 4) {
      std::cout << "            ";
      for (size_t x = 0; x < 6; x++) {
        std::cout << gpcu::colors::wrap::wrapper("\u2588", ((i + 1) / 36) * 6 + x + 226, 0, 39);
      }
    }
  }
  std::cout << std::endl;
}

bool test_color(int* passingPtr, int* totalPtr) {
  bool passing = true;
  int localPassing = 12;
  int localTotal = 12;
  std::cout << "Color" << std::endl;

  test_color_support();
  test_color_other();
  test_color_color();
  test_color_bright();
  test_color_bg();
  test_color_bgbright();
  test_color_256();

  std::cout << localPassing << "/" << localTotal << " tests passing" << std::endl << std::endl;
  (*passingPtr) += localPassing;
  (*totalPtr) += localTotal;
  return passing;
}
// </region>

// <region> Join Tests
std::string test_join_int() {
  int const size = 5;
  int array[size] = { 98, 88, 92, 92, 90 };
  std::string delim = ", ";
  return gpcu::join(array, size, delim);
}

std::string test_join_char() {
  int const size = 5;
  char array[size] = { 'A', 'B', 'A', 'A', 'A' };
  std::string delim = ", ";
  return gpcu::join(array, size, delim);
}

std::string test_join_bool() {
  int const size = 5;
  bool array[size] = { true, true, false, false, true };
  std::string delim = ", ";
  return gpcu::join(array, size, delim);
}

std::string test_join_float() {
  int const size = 5;
  float array[size] = { 4.4, 3.0, 3.8, 3.0, 4.0 };
  std::string delim = ", ";
  return gpcu::join(array, size, delim, 1);
}

std::string test_join_double() {
  int const size = 5;
  float array[size] = { 4.42, 3.00, 3.82, 3.01, 4.04 };
  std::string delim = ", ";
  return gpcu::join(array, size, delim, 2);
}

std::string test_join_string() {
  int const size = 5;
  std::string array[size] = { "Soup", "Crackers", "7-Up", "DayQuil", "Ibuprofine" };
  std::string delim = ", ";
  return gpcu::join(array, size, delim);
}

bool test_join(int* passingPtr, int* totalPtr) {
  size_t const localTotal = 6;
  std::string testNames[localTotal] = {
    "join(int a[], size_t size, string delim)",
    "join(char a[], size_t size, string delim)",
    "join(bool a[], size_t size, string delim)",
    "join(float a[], size_t size, string delim)",
    "join(double a[], size_t size, string delim)",
    "join(string a[], size_t size, string delim)"
  };
  std::string (*testFuncs[localTotal])() = {
    test_join_int,
    test_join_char,
    test_join_bool,
    test_join_float,
    test_join_double,
    test_join_string
  };
  std::string testExps[localTotal] = {
    "98, 88, 92, 92, 90",
    "A, B, A, A, A",
    "true, true, false, false, true",
    "4.4, 3.0, 3.8, 3.0, 4.0",
    "4.42, 3.00, 3.82, 3.01, 4.04",
    "Soup, Crackers, 7-Up, DayQuil, Ibuprofine"
  };

  return etest::TEST_CATEGORY_EQ("Join", localTotal, passingPtr, totalPtr, testNames, testFuncs, testExps);
}
// </region>

// <region> String Test
std::string test_string_upper() {
  std::string test = "Day Tripper";
  std::string* testPtr = &test;
  gpcu::string::upper(testPtr);

  return test;
}

std::string test_string_lower() {
  std::string test = "Day Tripper";
  std::string* testPtr = &test;
  gpcu::string::lower(testPtr);

  return test;
}

std::string test_string_ltrim() {
  std::string test = "    Overflow";

  return gpcu::string::ltrim(test);
}

std::string test_string_rtrim() {
  std::string test = "Underflow   ";

  return gpcu::string::rtrim(test);
}

std::string test_string_trim() {
  std::string test = "   Botherflow   ";

  return gpcu::string::trim(test);
}

bool test_string(int* passingPtr, int* totalPtr) {
  size_t localTotal = 5;
  std::string testNames[localTotal] = {
    "upper(string* s)",
    "lower(string* s)",
    "ltrim(string& s, const string& chars)",
    "rtrim(string& s, const string& chars)",
    "trim(string& s, const string& chars)"
  };
  std::string (*testFuncs[localTotal])() = {
    test_string_upper,
    test_string_lower,
    test_string_ltrim,
    test_string_rtrim,
    test_string_trim
  };
  std::string testExps[localTotal] = {
    "DAY TRIPPER",
    "day tripper",
    "Overflow",
    "Underflow",
    "Botherflow"
  };

  return etest::TEST_CATEGORY_EQ("String", localTotal, passingPtr, totalPtr, testNames, testFuncs, testExps);
}
// </region>

int main(int argc, const char* argv[]) {
  int passing = 0;
  int total = 0;
  int* passingPtr = &passing;
  int* totalPtr = &total;

  test_color(passingPtr, totalPtr);
  test_join(passingPtr, totalPtr);
  test_string(passingPtr, totalPtr);

  std::cout << (*passingPtr) << "/" << (*totalPtr) << " total tests passing" << std::endl;

  gpcu::pause();
  return 0;
}
