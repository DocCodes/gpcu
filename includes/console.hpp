/**
*  @file      console.hpp
*  @brief     Adds methods that mimic the console library from C#.
*
*  @author    Evan Elias Young
*  @date      2019-01-28
*  @date      2019-02-12
*  @copyright Copyright 2019 Evan Elias Young. All rights reserved.
*/

#ifndef GPCU_CONSOLE_HPP_
#define GPCU_CONSOLE_HPP_  0x0100000000

#include <iostream>
#include <string>

namespace gpcu {
  namespace console {
    /**
    * @brief Emits a beep noise through the console.
    */
    void beep() {
      std::cout << '\a';
    }

    /**
    * @brief Clears the console screen.
    */
    void clear() {
      std::cout << std::string(100, '\n');
    }

    /**
    * @brief Gets a line of input from stdin.
    * @return The line of input without the newline character.
    */
    std::string getline() {
      std::string temp;
      std::getline(std::cin, temp);
      return temp;
    }

    /**
    * @brief Gets a line of input from stdin after outputting to the stdout.
    * @param  s The string to send to stdout.
    * @return   The line of input without the newline character.
    */
    std::string getline(const std::string& s) {
      std::string temp;
      std::cout << s;
      std::getline(std::cin, temp);
      return temp;
    }

    /**
    * @brief Writes a line of output to stdout without the newline character.
    * @param s The string to send to stdout.
    */
    void write(const std::string& s) {
      std::cout << s;
    }

    /**
    * @brief Writes a line of output to stdout with the newline character.
    * @param s The string to send to stdout.
    */
    void writeline(const std::string& s) {
      std::cout << s << std::endl;
    }
  }  // namespace console
}  // namespace gpcu

#endif  // GPCU_CONSOLE_HPP_
