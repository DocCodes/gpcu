/**
*  @file      colors.cpp
*  @brief     Interface for the tests for the colors section of GPCU.
*
*  @author    Evan Elias Young
*  @date      2019-02-27
*  @date      2019-02-27
*  @copyright Copyright 2019 Evan Elias Young. All rights reserved.
*/

#ifndef TESTS_COLORS_H_
#define TESTS_COLORS_H_

#include "../includes/stdafx.h"
#include "../includes/colors.h"

void test_colors_support();
void test_colors_other();
void test_colors_color();
void test_colors_bright();
void test_colors_bg();
void test_colors_bgbright();
void test_colors_256();
bool test_colors(int *passing, int *total);

#endif // TESTS_COLORS_H_