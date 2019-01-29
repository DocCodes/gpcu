//  string.hpp
//  gpcu
//
//  Created by Evan Elias Young on 2019-01-17.
//  Copyright 2019 Evan Elias Young. All rights reserved.

#ifndef GPCU_STRING_HPP_  // include guard
#define GPCU_STRING_HPP_

#include <ctype.h>

#include <algorithm>
#include <string>

namespace gpcu {
  namespace string {
    /**
     * Transforms a string to uppercase.
     * @param s The string to make uppercase.
     */
    void upper(std::string* s) {
      std::transform((*s).begin(), (*s).end(), (*s).begin(), ::toupper);
    }

    /**
     * Transforms a string to lowercase.
     * @param s The string to make lowercase.
     */
    void lower(std::string* s) {
      std::transform((*s).begin(), (*s).end(), (*s).begin(), ::tolower);
    }

    /**
     * Trims away whitespace from the left edge of a string.
     * @param  s     The string to trim.
     * @param  chars The characters to trim away.
     * @return       The string without the trimmed characters.
     */
    std::string ltrim(std::string s, const std::string chars = "\t\n\v\f\r ") {
      s.erase(0, s.find_first_not_of(chars));
      return s;
    }

    /**
     * Trims away whitespace from the right edge of a string.
     * @param  s     The string to trim.
     * @param  chars The characters to trim away.
     * @return       The string without the trimmed characters.
     */
    std::string rtrim(std::string s, const std::string chars = "\t\n\v\f\r ") {
      s.erase(s.find_last_not_of(chars) + 1);
      return s;
    }

    /**
     * Trims away whitespace from both edges of a string.
     * @param  s     The string to trim.
     * @param  chars The characters to trim away.
     * @return       The string without the trimmed characters.
     */
    std::string trim(std::string s, const std::string chars = "\t\n\v\f\r ") {
      return ltrim(rtrim(s, chars), chars);
    }
  }  // namespace string
}  // namespace gpcu

#endif  // GPCU_STRING_HPP_
