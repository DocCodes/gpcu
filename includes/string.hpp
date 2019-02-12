/**
*  @file      string.hpp
*  @brief     Adds string methods to include the strings in the default header.
*
*  @author    Evan Elias Young
*  @date      2019-01-17
*  @date      2019-02-12
*  @copyright Copyright 2019 Evan Elias Young. All rights reserved.
*/

#ifndef GPCU_STRING_HPP_
#define GPCU_STRING_HPP_  0x0100000000

#include <ctype.h>

#include <algorithm>
#include <string>

namespace gpcu {
  namespace string {
    /**
    * @brief Transforms a string to uppercase.
    * @param s The string to make uppercase.
    */
    void upper(std::string* s) {
      std::transform((*s).begin(), (*s).end(), (*s).begin(), ::toupper);
    }

    /**
    * @brief Transforms a string to lowercase.
    * @param s The string to make lowercase.
    */
    void lower(std::string* s) {
      std::transform((*s).begin(), (*s).end(), (*s).begin(), ::tolower);
    }

    /**
    * @brief Trims away whitespace from the left edge of a string.
    * @param  s     The string to trim.
    * @param  chars The characters to trim away.
    * @return       The string without the trimmed characters.
    */
    std::string ltrim(std::string s, const std::string chars = "\t\n\v\f\r ") {
      s.erase(0, s.find_first_not_of(chars));
      return s;
    }

    /**
    * @brief Trims away whitespace from the right edge of a string.
    * @param  s     The string to trim.
    * @param  chars The characters to trim away.
    * @return       The string without the trimmed characters.
    */
    std::string rtrim(std::string s, const std::string chars = "\t\n\v\f\r ") {
      s.erase(s.find_last_not_of(chars) + 1);
      return s;
    }

    /**
    * @brief Trims away whitespace from both edges of a string.
    * @param  s     The string to trim.
    * @param  chars The characters to trim away.
    * @return       The string without the trimmed characters.
    */
    std::string trim(std::string s, const std::string chars = "\t\n\v\f\r ") {
      return ltrim(rtrim(s, chars), chars);
    }

    /**
    * @brief Counts the occurrences of a string in a string.
    * @param  s     The string from which to count occurrences.
    * @param  delim The string to count.
    * @return       The number of occurrences of a string within a string.
    */
    std::size_t count(const std::string& s, const std::string& delim) {
      std::string::size_type ocLast = s.find_last_of(delim);
      std::string::size_type n = 0;
      std::size_t cnt = 0;

      if (ocLast == std::string::npos) { return 0; }
      while (n < ocLast) {
        ++cnt;
        n = s.find(delim, n) + delim.length();
      }
      return cnt;
    }

    /**
    * @brief Counts the occurrences of a character in a string.
    * @param  s     The string from which to count occurrences.
    * @param  delim The character to count.
    * @return       The number of occurrences of a character within a string.
    */
    std::size_t count(const std::string& s, const char& delim) {
      std::string::size_type ocLast = s.find_last_of(delim);
      std::string::size_type n = 0;
      std::size_t cnt = 0;

      if (ocLast == std::string::npos) { return 0; }
      while (n < ocLast) {
        ++cnt;
        n = s.find(delim, n) + 1;
      }
      return cnt;
    }

    /**
    * Splits a string into a collection of smaller parts.
    * @param  a     The array of parts.
    * @param  s     The string to split.
    * @param  delim The characters to split on.
    * @param  size  The length of the array.
    * @return       Whether or not the split was successful.
    */
    bool split(std::string* a, const std::string& s, const std::string& delim, const std::size_t& size) {
      std::string::size_type beg = 0;
      std::string::size_type end = s.find(delim, beg + 1);
      if (gpcu::string::count(s, delim) + 1 != size) { return false; }

      for (size_t i = 0; i < size; i++) {
        a[i] = s.substr(beg, end - beg);
        beg = s.find(delim, end) + delim.length();
        end = s.find(delim, beg);
      }

      return true;
    }

    /**
    * Splits a string into a collection of smaller parts.
    * @param  a     The array of parts.
    * @param  s     The string to split.
    * @param  delim The character to split on.
    * @param  size  The length of the array.
    * @return       Whether or not the split was successful.
    */
    bool split(std::string* a, const std::string& s, const char& delim, const std::size_t& size) {
      std::string::size_type beg = 0;
      std::string::size_type end = s.find(delim, beg + 1);
      if (gpcu::string::count(s, delim) + 1 != size) { return false; }

      for (size_t i = 0; i < size; i++) {
        a[i] = s.substr(beg, end - beg);
        beg = s.find(delim, end) + 1;
        end = s.find(delim, beg);
      }

      return true;
    }
  }  // namespace string
}  // namespace gpcu

#endif  // GPCU_STRING_HPP_
