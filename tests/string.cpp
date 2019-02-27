/**
*  @file      string.cpp
*  @brief     Implementation for the tests for the string section of GPCU.
*
*  @author    Evan Elias Young
*  @date      2019-02-27
*  @date      2019-02-27
*  @copyright Copyright 2019 Evan Elias Young. All rights reserved.
*/

#ifndef TESTS_STRING_HPP_
#define TESTS_STRING_HPP_

#include "../includes/stdafx.h"
#include "../includes/string.h"
#include "string.h"
#include "etest.h"

std::string test_string_upper()
{
  std::unique_ptr<std::string> test(new std::string("Day Tripper"));
  gpcu::string::upper(test.get());

  return (*test);
}

std::string test_string_lower()
{
  std::unique_ptr<std::string> test(new std::string("Day Tripper"));
  gpcu::string::lower(test.get());

  return (*test);
}

std::string test_string_ltrim()
{
  std::unique_ptr<std::string> test(new std::string("    Overflow"));
  gpcu::string::ltrim(test.get());

  return (*test);
}

std::string test_string_rtrim()
{
  std::unique_ptr<std::string> test(new std::string("Underflow   "));
  gpcu::string::rtrim(test.get());

  return (*test);
}

std::string test_string_trim()
{
  std::unique_ptr<std::string> test(new std::string("   Botherflow   "));
  gpcu::string::trim(test.get());

  return (*test);
}

std::string test_string_count_string()
{
  return std::to_string(gpcu::string::count("Kansas City/Hey-Hey-Hey-Hey!", "Hey"));
}

std::string test_string_count_char()
{
  return std::to_string(gpcu::string::count("Evan Elias Young", 'E'));
}

bool test_string(int *passing, int *total)
{
  std::size_t const localTotal = 7;
  std::string testNames[localTotal] = {
      "upper(string* s)",
      "lower(string* s)",
      "ltrim(string& s, const string& chars)",
      "rtrim(string& s, const string& chars)",
      "trim(string& s, const string& chars)",
      "count(string s, string delim)",
      "count(string s, char delim)"};
  std::string (*testFuncs[localTotal])() = {
      test_string_upper,
      test_string_lower,
      test_string_ltrim,
      test_string_rtrim,
      test_string_trim,
      test_string_count_string,
      test_string_count_char};
  std::string testExps[localTotal] = {
      "DAY TRIPPER",
      "day tripper",
      "Overflow",
      "Underflow",
      "Botherflow",
      "4",
      "2"};

  return etest::TEST_CATEGORY_EQ("String", localTotal, passing, total, testNames, testFuncs, testExps);
}

#endif // TESTS_STRING_HPP_