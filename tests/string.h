/**
*  @file      string.cpp
*  @brief     Implementation for the tests for the string section of GPCU.
*
*  @author    Evan Elias Young
*  @date      2019-02-27
*  @date      2019-02-28
*  @copyright Copyright 2019 Evan Elias Young. All rights reserved.
*/

#ifndef TESTS_STRING_H_
#define TESTS_STRING_H_

#include "../includes/stdafx.h"
#include "../includes/string.h"

std::string test_string_upper();
std::string test_string_lower();
std::string test_string_ltrim();
std::string test_string_rtrim();
std::string test_string_trim();
std::string test_string_count_string();
std::string test_string_count_char();
std::string test_string_startswith();
std::string test_string_endswith();

bool test_string(int *passing, int *total);

#endif // TESTS_STRING_H_