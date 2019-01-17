  //  main.cpp
  //  gpcu
  //
  //  Created by Evan Young on 2019-01-13.
  //  Copyright 2019 Evan Elias Young. All rights reserved.

#include <iostream>
#include <cstdlib>
#include "gpcu.hpp"
#include "etest.hpp"

using std::cout;
using std::string;
using std::endl;

  // <region> Join Tests
string test_join_int() {
  int const size = 5;
  int array[size] = { 98, 88, 92, 92, 90 };
  string delim = ", ";
  return gpcu::join(array, size, delim);
}

string test_join_char() {
  int const size = 5;
  char array[size] = { 'A', 'B', 'A', 'A', 'A' };
  string delim = ", ";
  return gpcu::join(array, size, delim);
}

string test_join_bool() {
  int const size = 5;
  bool array[size] = { true, true, false, false, true };
  string delim = ", ";
  return gpcu::join(array, size, delim);
}

string test_join_float() {
  int const size = 5;
  float array[size] = { 4.4, 3.0, 3.8, 3.0, 4.0 };
  string delim = ", ";
  return gpcu::join(array, size, delim, 1);
}

string test_join_double() {
  int const size = 5;
  float array[size] = { 4.42, 3.00, 3.82, 3.01, 4.04 };
  string delim = ", ";
  return gpcu::join(array, size, delim, 2);
}

string test_join_string() {
  int const size = 5;
  string array[size] = { "Soup", "Crackers", "7-Up", "DayQuil", "Ibuprofine" };
  string delim = ", ";
  return gpcu::join(array, size, delim);
}

bool test_join(int *passing, int *total) {
  size_t const localTotal = 6;
  string testNames[localTotal] = {
    "join(int *a, size_t size, string delim)",
    "join(char *a, size_t size, string delim)",
    "join(bool *a, size_t size, string delim)",
    "join(float *a, size_t size, string delim)",
    "join(double *a, size_t size, string delim)",
    "join(string *a, size_t size, string delim)"
  };
  string (*testFuncs[localTotal])() = {
    test_join_int,
    test_join_char,
    test_join_bool,
    test_join_float,
    test_join_double,
    test_join_string
  };
  string testExps[localTotal] = {
    "98, 88, 92, 92, 90",
    "A, B, A, A, A",
    "true, true, false, false, true",
    "4.4, 3.0, 3.8, 3.0, 4.0",
    "4.42, 3.00, 3.82, 3.01, 4.04",
    "Soup, Crackers, 7-Up, DayQuil, Ibuprofine"
  };

  return etest::TEST_CATEGORY_EQ("Join", localTotal, passing, total, testNames, testFuncs, testExps);
}
  // </region>

  // <region> Average Tests
  // </region>

int main(int argc, const char* argv[]) {
  int *passing;
  int *total;
  passing = 0;
  total = 0;
  gpcu::ColorSupport colorSupport = gpcu::getColorSupport();

  cout << colorSupport;

  test_join(passing, total);

  cout << passing << "/" << total << " total tests passing" << endl;

  gpcu::pause();
  return 0;
}
