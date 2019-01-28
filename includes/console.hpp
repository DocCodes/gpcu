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
    /**
     * Emits a beep noise through the console.
     */
    void beep() {
      std::cout << '\a';
    }

    /**
     * Clears the console screen.
     */
    void clear() {
      std::cout << std::string(100, '\n');
    }

    /**
     * Gets a line of input from stdin.
     * @return [std:string] The line of input without the newline character.
     */
    std::string getline() {
      std::string temp;
      std::getline(std::cin, temp);
      return temp;
    }

    /**
     * Gets a line of input from stdin after outputting to the stdout.
     * @param  [std:string] s The string to send to stdout.
     * @return [std:string]   The line of input without the newline character.
     */
    std::string getline(std::string s) {
      std::string temp;
      std::cout << s;
      std::getline(std::cin, temp);
      return temp;
    }

    /**
     * Writes a line of output to stdout without the newline character.
     * @param [std:string] s The string to send to stdout.
     */
    void write(std::string s) {
      std::cout << s;
    }

    /**
     * Writes a line of output to stdout with the newline character.
     * @param [std:string] s The string to send to stdout.
     */
    void writeline(std::string s) {
      std::cout << s << std::endl;
    }
  }  // namespace console
}  // namespace gpcu

#endif  // GPCU_CONSOLE_HPP_
