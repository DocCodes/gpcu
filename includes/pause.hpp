/**
*  @file      pause.hpp
*  @brief     Adds pause and prompts to stdin/stdout.
*
*  @author    Evan Elias Young
*  @date      2019-01-17
*  @date      2019-02-12
*  @copyright Copyright 2019 Evan Elias Young. All rights reserved.
*/

#ifndef GPCU_PAUSE_HPP_
#define GPCU_PAUSE_HPP_

#include <iostream>
#include <string>

namespace gpcu {
  /**
  * @brief Pauses the program until the newline character is received.
  * @since 1.0.0-2 (0x0200000002)
  */
  void pause() {
    std::cout << "Press the enter key to continue . . ." << std::endl;
    std::cin.get();
  }

  /**
  * @brief Pauses the program with a message until the newline character is received.
  * @since 1.0.0-2 (0x0200000002)
  * @param msg The message to prompt.
  */
  void pause(const std::string& msg) {
    std::cout << msg << std::endl;
    std::cin.get();
  }
}  // namespace gpcu
// </region>

#endif  // GPCU_PAUSE_HPP_
