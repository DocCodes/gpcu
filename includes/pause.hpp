//  pause.hpp
//  gpcu
//
//  Created by Evan Elias Young on 2019-01-17.
//  Copyright 2019 Evan Elias Young. All rights reserved.

#ifndef GPCU_PAUSE_HPP_  // include guard
#define GPCU_PAUSE_HPP_

#include <iostream>
#include <string>

namespace gpcu {
  /**
   * Pauses the program until the newline character is received.
   */
  void pause() {
    std::cout << "Press the enter key to continue . . ." << std::endl;
    std::cin.get();
  }

  /**
   * Pauses the program with a message until the newline character is received.
   * @param msg The message to prompt.
   */
  void pause(std::string msg) {
    std::cout << msg << std::endl;
    std::cin.get();
  }
}  // namespace gpcu
// </region>

#endif  // GPCU_PAUSE_HPP_
