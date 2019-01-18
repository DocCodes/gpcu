//  main.cpp
//  gpcu
//
//  Created by Evan Young on 2019-01-13.
//  Copyright 2019 Evan Elias Young. All rights reserved.

#include <stdlib.h>

#include <iostream>

#include "etest.hpp"
#include "gpcu.hpp"

// <region> Color Tests
void test_color_support() {
  std::cout << "  + Colors Supported: " << gpcu::colors::getSupport() << std::endl;
}

void test_color_other() {
  std::cout << "  + ";
  std::cout << gpcu::colors::wrap::bold("BBBBB") << "   ";
  std::cout << gpcu::colors::wrap::dim("DDDDD") << "   ";
  std::cout << gpcu::colors::wrap::italic("IIIII") << "   ";
  std::cout << gpcu::colors::wrap::underline("UUUUU") << "   ";
  std::cout << gpcu::colors::wrap::inverse("IIIII") << "   ";
  std::cout << gpcu::colors::wrap::hidden("HHHHH") << "   ";
  std::cout << gpcu::colors::wrap::strikethrough("SSSSS") << "   ";
  std::cout << std::endl;
}

void test_color_color() {
  std::cout << "  + ";
  std::cout << gpcu::colors::wrap::black("BBBBB") << "   ";
  std::cout << gpcu::colors::wrap::red("RRRRR") << "   ";
  std::cout << gpcu::colors::wrap::green("GGGGG") << "   ";
  std::cout << gpcu::colors::wrap::yellow("YYYYY") << "   ";
  std::cout << gpcu::colors::wrap::blue("BBBBB") << "   ";
  std::cout << gpcu::colors::wrap::magenta("MMMMM") << "   ";
  std::cout << gpcu::colors::wrap::cyan("CCCCC") << "   ";
  std::cout << gpcu::colors::wrap::white("WWWWW") << "   ";
  std::cout << std::endl;
}

void test_color_bright() {
  std::cout << "  + ";
  std::cout << gpcu::colors::wrap::blackBright("BBBBB") << "   ";
  std::cout << gpcu::colors::wrap::redBright("RRRRR") << "   ";
  std::cout << gpcu::colors::wrap::greenBright("GGGGG") << "   ";
  std::cout << gpcu::colors::wrap::yellowBright("YYYYY") << "   ";
  std::cout << gpcu::colors::wrap::blueBright("BBBBB") << "   ";
  std::cout << gpcu::colors::wrap::magentaBright("MMMMM") << "   ";
  std::cout << gpcu::colors::wrap::cyanBright("CCCCC") << "   ";
  std::cout << gpcu::colors::wrap::whiteBright("WWWWW") << "   ";
  std::cout << std::endl;
}

void test_color_bg() {
  std::cout << "  + ";
  std::cout << gpcu::colors::wrap::bgBlack("BBBBB") << "   ";
  std::cout << gpcu::colors::wrap::bgRed("RRRRR") << "   ";
  std::cout << gpcu::colors::wrap::bgGreen("GGGGG") << "   ";
  std::cout << gpcu::colors::wrap::bgYellow("YYYYY") << "   ";
  std::cout << gpcu::colors::wrap::bgBlue("BBBBB") << "   ";
  std::cout << gpcu::colors::wrap::bgMagenta("MMMMM") << "   ";
  std::cout << gpcu::colors::wrap::bgCyan("CCCCC") << "   ";
  std::cout << gpcu::colors::wrap::bgWhite("WWWWW") << "   ";
  std::cout << std::endl;
}

void test_color_bgbright() {
  std::cout << "  + ";
  std::cout << gpcu::colors::wrap::bgBlackBright("BBBBB") << "   ";
  std::cout << gpcu::colors::wrap::bgRedBright("RRRRR") << "   ";
  std::cout << gpcu::colors::wrap::bgGreenBright("GGGGG") << "   ";
  std::cout << gpcu::colors::wrap::bgYellowBright("YYYYY") << "   ";
  std::cout << gpcu::colors::wrap::bgBlueBright("BBBBB") << "   ";
  std::cout << gpcu::colors::wrap::bgMagentaBright("MMMMM") << "   ";
  std::cout << gpcu::colors::wrap::bgCyanBright("CCCCC") << "   ";
  std::cout << gpcu::colors::wrap::bgWhiteBright("WWWWW") << "   ";
  std::cout << std::endl;
}

bool test_color(int* passingPtr, int* totalPtr) {
  bool passing = true;
  int localPassing = 6;
  int localTotal = 6;
  std::cout << "Color" << std::endl;

  test_color_support();
  test_color_other();
  test_color_color();
  test_color_bright();
  test_color_bg();
  test_color_bgbright();

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

// <region> Average Tests
// </region>

int main(int argc, const char* argv[]) {
  int passing = 0;
  int total = 0;
  int* passingPtr = &passing;
  int* totalPtr = &total;

  test_color(passingPtr, totalPtr);
  test_join(passingPtr, totalPtr);

  std::cout << (*passingPtr) << "/" << (*totalPtr) << " total tests passing" << std::endl;

  gpcu::pause();
  return 0;
}
