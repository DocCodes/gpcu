//  pause.hpp
//  gpcu
//
//  Created by Evan Elias Young on 2019-01-17.
//  Copyright 2019 Evan Elias Young. All rights reserved.

#ifndef GPCU_PAUSE_HPP_  // include guard
#define GPCU_PAUSE_HPP_

namespace gpcu {
  void pause() {
    std::cout << "Press the enter key to continue . . ." << std::endl;
    std::cin.get();
  }

  void pause(std::string msg) {
    std::cout << msg << std::endl;
    std::cin.get();
  }
}  // namespace gpcu
// </region>

#endif  // GPCU_PAUSE_HPP_
