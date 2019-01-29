/**
*  @file      etest.hpp
*  @brief     Adds testing and assert functions to the test process.
*
*  @author    Evan Elias Young
*  @date      2019-01-13
*  @date      2019-01-29
*  @copyright Copyright 2019 Evan Elias Young. All rights reserved.
*/

#ifndef ETEST_HPP_  // include guard
#define ETEST_HPP_

#include <iostream>
#include <string>

#include "includes/all.hpp"

namespace etest {
  bool EXPECT_EQ(std::string testName, std::string (*func)(), std::string exp) {
    std::string ind = "  ";
    std::string res = func();
    bool passed = res == exp;

    std::cout << ind << (passed ? gpcu::colors::wrap::green("+") : gpcu::colors::wrap::red("-")) << " " << gpcu::colors::wrap::dim(testName) << std::endl;
    if (!passed) {
      std::string temp = ind + ind + "- ";
      std::cout << temp << "received \"" << res << "\"" << std::endl;
      std::cout << temp << "expected \"" << exp << "\"" << std::endl;
    }

    return passed;
  }

  bool TEST_CATEGORY_EQ(std::string category, size_t localTotal, int* passingPtr, int* totalPtr, std::string testNames[], std::string (*testFuncs[])(), std::string testExps[]) {
    bool passed = true;
    int localPassing = 0;

    std::cout << category << std::endl;
    for (size_t i = 0; i < localTotal; i++) {
      if (EXPECT_EQ(testNames[i], testFuncs[i], testExps[i])) {
        localPassing++;
      }
    }

    std::cout << localPassing << "/" << localTotal << " tests passing" << std::endl << std::endl;
    (*passingPtr) += localPassing;
    (*totalPtr) += localTotal;

    return passed;
  }
}  // namespace etest


#endif  // ETEST_HPP_
