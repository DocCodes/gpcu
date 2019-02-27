/**
*  @file      etest.cpp
*  @brief     Implementation of testing and asserting.
*
*  @author    Evan Elias Young
*  @date      2019-02-27
*  @date      2019-02-27
*  @copyright Copyright 2019 Evan Elias Young. All rights reserved.
*/

#include "../includes/stdafx.h"
#include "../includes/colors.h"
#include "etest.h"

namespace etest
{
bool EXPECT_EQ(const std::string &testName, std::string (*func)(), const std::string &exp)
{
  std::unique_ptr<std::string> ind(new std::string("  "));
  std::unique_ptr<std::string> res(new std::string(func()));
  std::unique_ptr<bool> passed(new bool((*res) == exp));

  std::cout << (*ind) << ((*passed) ? gpcu::colors::wrap::green("+") : gpcu::colors::wrap::red("-")) << " " << gpcu::colors::wrap::dim(testName) << std::endl;
  if (!(*passed))
  {
    std::unique_ptr<std::string> temp(new std::string((*ind) + (*ind) + "- "));
    std::cout << (*temp) << "received \"" << (*res) << "\"" << std::endl;
    std::cout << (*temp) << "expected \"" << exp << "\"" << std::endl;
  }

  return (*passed);
}

bool TEST_CATEGORY_EQ(const std::string &category, const std::size_t &localTotal, int *passing, int *total, std::string testNames[], std::string (*testFuncs[])(), std::string testExps[])
{
  std::unique_ptr<bool> passed(new bool(true));
  std::unique_ptr<int> localPassing(new int(0));

  std::cout << category << std::endl;
  for (std::size_t i = 0; i < localTotal; i++)
  {
    if (EXPECT_EQ(testNames[i], testFuncs[i], testExps[i]))
    {
      (*localPassing)++;
    }
  }

  std::cout << (*localPassing) << "/" << localTotal << " tests passing" << std::endl
            << std::endl;
  (*passing) += (*localPassing);
  (*total) += localTotal;

  return (*passed);
}
} // namespace etest