//  console.hpp
//  gpcu
//
//  Created by Evan Elias Young on 2019-01-28.
//  Copyright 2019 Evan Elias Young. All rights reserved.

#ifndef GPCU_CONSOLE_HPP_  // include guard
#define GPCU_CONSOLE_HPP_

#include <iostream>
#include <string>


namespace gpcu {
  namespace console {
    void beep() {
      std::cout << '\a';
    }

    void clear() {
      std::cout << std::string(100, '\n');
    }

    std::string getline() {
      std::string temp;
      std::getline(std::cin, temp);
      return temp;
    }

    std::string getline(std::string s) {
      std::string temp;
      std::cout << s;
      std::getline(std::cin, temp);
      return temp;
    }

    void write(std::string s) {
      std::cout << s;
    }

    void writeline(std::string s) {
      std::cout << s << std::endl;
    }
  }  // namespace console
}  // namespace gpcu

#endif  // GPCU_CONSOLE_HPP_
