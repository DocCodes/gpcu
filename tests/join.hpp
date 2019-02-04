/**
*  @file      join.cpp
*  @brief     The tests for the join section of GPCU.
*
*  @author    Evan Elias Young
*  @date      2019-02-04
*  @date      2019-02-04
*  @copyright Copyright 2019 Evan Elias Young. All rights reserved.
*/

#ifndef TESTS_JOIN_HPP_  // include guard
#define TESTS_JOIN_HPP_

#include <iostream>
#include <string>

#include "etest.hpp"
#include "../includes/all.hpp"

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
  std::size_t const localTotal = 6;
  std::string testNames[localTotal] = {
    "join(int a[], std::size_t size, string delim)",
    "join(char a[], std::size_t size, string delim)",
    "join(bool a[], std::size_t size, string delim)",
    "join(float a[], std::size_t size, string delim)",
    "join(double a[], std::size_t size, string delim)",
    "join(string a[], std::size_t size, string delim)"
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

#endif  // TESTS_JOIN_HPP_
