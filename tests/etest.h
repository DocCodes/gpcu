/**
*  @file      etest.h
*  @brief     Interface of testing and asserting.
*
*  @author    Evan Elias Young
*  @date      2019-02-27
*  @date      2019-02-27
*  @copyright Copyright 2019 Evan Elias Young. All rights reserved.
*/

#ifndef TESTS_ETEST_H_
#define TESTS_ETEST_H_

#include "../includes/stdafx.h"
#include "../includes/colors.h"

namespace etest
{
bool EXPECT_EQ(const std::string &testName, std::string (*func)(), const std::string &exp);
bool TEST_CATEGORY_EQ(const std::string &category, const std::size_t &localTotal, int *passing, int *total, std::string testNames[], std::string (*testFuncs[])(), std::string testExps[]);
} // namespace etest

#endif // TESTS_ETEST_H_