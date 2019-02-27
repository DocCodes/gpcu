/**
*  @file      string.cpp
*  @brief     Implementation for the string methods.
*
*  @author    Evan Elias Young
*  @date      2019-02-26
*  @date      2019-02-27
*  @copyright Copyright 2019 Evan Elias Young. All rights reserved.
*/

#include "stdafx.h"
#include "string.h"

namespace gpcu
{
namespace string
{
/**
* @brief Transforms a string to uppercase.
* @since 2.2.0-37 (0x0202000025)
* @param s The string to make uppercase.
*/
void upper(std::string *s)
{
  std::transform((*s).begin(), (*s).end(), (*s).begin(), ::toupper);
}

/**
* @brief Transforms a string to lowercase.
* @since 2.2.0-37 (0x0202000025)
* @param s The string to make lowercase.
*/
void lower(std::string *s)
{
  std::transform((*s).begin(), (*s).end(), (*s).begin(), ::tolower);
}

/**
* @brief  Trims away whitespace from the left edge of a string.
* @since  2.2.0-37 (0x0202000025)
* @param  s     The string to trim.
* @param  chars The characters to trim away.
* @return       The string without the trimmed characters.
*/
void ltrim(std::string *s, const std::string &chars)
{
  (*s).erase(0, (*s).find_first_not_of(chars));
}

/**
* @brief  Trims away whitespace from the right edge of a string.
* @since  2.2.0-37 (0x0202000025)
* @param  s     The string to trim.
* @param  chars The characters to trim away.
* @return       The string without the trimmed characters.
*/
void rtrim(std::string *s, const std::string &chars)
{
  (*s).erase((*s).find_last_not_of(chars) + 1);
}

/**
* @brief  Trims away whitespace from both edges of a string.
* @since  2.2.0-37 (0x0202000025)
* @param  s     The string to trim.
* @param  chars The characters to trim away.
* @return       The string without the trimmed characters.
*/
void trim(std::string *s, const std::string &chars)
{
  rtrim(s, chars);
  ltrim(s, chars);
}

/**
* @brief  Counts the occurrences of a string in a string.
* @since  2.3.0-43 (0x020300002B)
* @param  s The string from which to count occurrences.
* @param  t The string to count.
* @return   The number of occurrences of a string within a string.
*/
std::size_t count(const std::string &s, const std::string &t)
{
  std::unique_ptr<std::string::size_type> ocLast(new std::string::size_type(s.find_last_of(t)));
  std::unique_ptr<std::string::size_type> n(new std::string::size_type(0));
  std::unique_ptr<std::size_t> cnt(new std::size_t(0));

  if ((*ocLast) == std::string::npos)
  {
    return 0;
  }
  while ((*n) < (*ocLast))
  {
    ++(*cnt);
    (*n) = s.find(t, (*n)) + t.length();
  }
  return (*cnt);
}

/**
* @brief  Counts the occurrences of a character in a string.
* @since  2.3.0-43 (0x020300002B)
* @param  s The string from which to count occurrences.
* @param  t The character to count.
* @return   The number of occurrences of a character within a string.
*/
std::size_t count(const std::string &s, const char &t)
{
  std::unique_ptr<std::string::size_type> ocLast(new std::string::size_type(s.find_last_of(t)));
  std::unique_ptr<std::string::size_type> n(new std::string::size_type(0));
  std::unique_ptr<std::size_t> cnt(new std::size_t(0));

  if ((*ocLast) == std::string::npos)
  {
    return 0;
  }
  while ((*n) < (*ocLast))
  {
    ++(*cnt);
    (*n) = s.find(t, (*n)) + 1;
  }
  return (*cnt);
}

/**
* @brief  Splits a string into a collection of smaller parts.
* @since  2.4.0-44 (0x020400002C)
* @param  a     The array of parts.
* @param  s     The string to split.
* @param  delim The characters to split on.
* @param  size  The length of the array.
* @return       Whether or not the split was successful.
*/
bool split(std::string *a, const std::string &s, const std::string &delim, const std::size_t &size)
{
  std::unique_ptr<std::string::size_type> beg(new std::string::size_type(0));
  std::unique_ptr<std::string::size_type> end(new std::string::size_type(s.find(delim, (*beg) + 1)));

  if (gpcu::string::count(s, delim) + 1 != size)
  {
    return false;
  }

  for (std::size_t i = 0; i < size; i++)
  {
    a[i] = s.substr((*beg), (*end) - (*beg));
    (*beg) = s.find(delim, (*end)) + delim.length();
    (*end) = s.find(delim, (*beg));
  }

  return true;
}

/**
* @brief Splits a string into a collection of smaller parts.
* @since  2.4.0-44 (0x020400002C)
* @param  a     The array of parts.
* @param  s     The string to split.
* @param  delim The character to split on.
* @param  size  The length of the array.
* @return       Whether or not the split was successful.
*/
bool split(std::string *a, const std::string &s, const char &delim, const std::size_t &size)
{
  std::unique_ptr<std::string::size_type> beg(new std::string::size_type(0));
  std::unique_ptr<std::string::size_type> end(new std::string::size_type(s.find(delim, (*beg) + 1)));

  if (gpcu::string::count(s, delim) + 1 != size)
  {
    return false;
  }

  for (std::size_t i = 0; i < size; i++)
  {
    a[i] = s.substr((*beg), (*end) - (*beg));
    (*beg) = s.find(delim, (*end)) + 1;
    (*end) = s.find(delim, (*beg));
  }

  return true;
}
} // namespace string
} // namespace gpcu