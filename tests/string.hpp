/**
*  @file      string.cpp
*  @brief     The tests for the string section of GPCU.
*
*  @author    Evan Elias Young
*  @date      2019-02-04
*  @date      2019-02-04
*  @copyright Copyright 2019 Evan Elias Young. All rights reserved.
*/

#ifndef TESTS_STRING_HPP_
#define TESTS_STRING_HPP_

#include <iostream>
#include <string>

#include "etest.hpp"
#include "../includes/all.hpp"

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

std::string test_string_count_string() {
  return std::to_string(gpcu::string::count("Kansas City/Hey-Hey-Hey-Hey!", "Hey"));
}

std::string test_string_count_char() {
  return std::to_string(gpcu::string::count("Evan Elias Young", 'E'));
}

bool test_string(int* passingPtr, int* totalPtr) {
  std::size_t const localTotal = 7;
  std::string testNames[localTotal] = {
    "upper(string* s)",
    "lower(string* s)",
    "ltrim(string& s, const string& chars)",
    "rtrim(string& s, const string& chars)",
    "trim(string& s, const string& chars)",
    "count(string s, string delim)",
    "count(string s, char delim)"
  };
  std::string (*testFuncs[localTotal])() = {
    test_string_upper,
    test_string_lower,
    test_string_ltrim,
    test_string_rtrim,
    test_string_trim,
    test_string_count_string,
    test_string_count_char
  };
  std::string testExps[localTotal] = {
    "DAY TRIPPER",
    "day tripper",
    "Overflow",
    "Underflow",
    "Botherflow",
    "4",
    "2"
  };

  return etest::TEST_CATEGORY_EQ("String", localTotal, passingPtr, totalPtr, testNames, testFuncs, testExps);
}

#endif  // TESTS_STRING_HPP_
