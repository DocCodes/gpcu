//  etest.hpp
//  gpcu
//
//  Created by Evan Young on 2019-01-13.
//  Copyright 2019 Evan Elias Young. All rights reserved.

#ifndef GPCU_ETEST_HPP_  // include guard
#define GPCU_ETEST_HPP_

#include <iostream>
#include <string>

namespace etest {
  bool EXPECT_EQ(std::string testName, std::string (*func)(), std::string exp) {
    std::string ind = "  ";
    std::string res = func();
    bool passed = res == exp;

    std::cout << ind << (passed ? "+" : "-") << " " << testName << std::endl;
    if (!passed) {
      std::string temp = ind + ind + "- ";
      std::cout << temp << "received \"" << res << "\"" << std::endl;
      std::cout << temp << "expected \"" << exp << "\"" << std::endl;
    }

    return passed;
  }

  bool TEST_CATEGORY_EQ(std::string category, size_t localTotal, int *passing, int *total, std::string testNames[], std::string (*testFuncs[])(), std::string testExps[]) {
    bool passed = true;
    int localPassing = 0;

    std::cout << category << std::endl;
    for (size_t i = 0; i < localTotal; i++) {
      if (EXPECT_EQ(testNames[i], testFuncs[i], testExps[i])) {
        localPassing++;
      }
    }

    std::cout << localPassing << "/" << localTotal << " tests passing" << std::endl << std::endl;
    passing += localPassing;
    total += localTotal;

    return passed;
  }
}  // namespace etest


#endif  // GPCU_ETEST_HPP_
