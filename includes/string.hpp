//  string.hpp
//  gpcu
//
//  Created by Evan Young on 2019-01-17.
//  Copyright 2019 Evan Elias Young. All rights reserved.

#ifndef GPCU_STRING_HPP_  // include guard
#define GPCU_STRING_HPP_

namespace gpcu {
  namespace string {
    void upper(std::string* s) {
      std::transform((*s).begin(), (*s).end(), (*s).begin(), ::toupper);
    }
    void lower(std::string* s) {
      std::transform((*s).begin(), (*s).end(), (*s).begin(), ::tolower);
    }
  }  // namespace string
}  // namespace gpcu

#endif  // GPCU_STRING_HPP_
