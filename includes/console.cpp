/**
*  @file      console.cpp
*  @brief     Implementation for the methods that mimic the console library from C#.
*
*  @author    Evan Elias Young
*  @date      2019-02-26
*  @date      2019-02-26
*  @copyright Copyright 2019 Evan Elias Young. All rights reserved.
*/

#include "stdafx.h"
#include "console.h"

namespace gpcu::console
{
/**
* @brief Emits a beep noise through the console.
* @since 2.2.0-37 (0x0202000025)
*/
void beep()
{
  std::cout << '\a';
}

/**
* @brief Clears the console screen.
* @since 2.2.0-37 (0x0202000025)
*/
void clear()
{
  std::cout << std::string(100, '\n');
}

/**
* @brief  Gets a line of input from stdin.
* @since  2.2.0-37 (0x0202000025)
* @return The line of input without the newline character.
*/
std::string getline()
{
  std::unique_ptr<std::string> temp(new std::string());
  std::getline(std::cin, (*temp));
  return (*temp);
}

/**
* @brief  Gets a line of input from stdin after outputting to the stdout.
* @since  2.2.0-37 (0x0202000025)
* @param  s The string to send to stdout.
* @return   The line of input without the newline character.
*/
std::string getline(const std::string &s)
{
  std::unique_ptr<std::string> temp(new std::string());
  std::cout << s;
  std::getline(std::cin, (*temp));
  return (*temp);
}

/**
* @brief Writes a line of output to stdout without the newline character.
* @since 2.2.0-37 (0x0202000025)
* @param s The string to send to stdout.
*/
void write(const std::string &s)
{
  std::cout << s;
}

/**
* @brief Writes a line of output to stdout with the newline character.
* @since 2.2.0-37 (0x0202000025)
* @param s The string to send to stdout.
*/
void writeline(const std::string &s)
{
  std::cout << s << std::endl;
}
} // namespace gpcu::console
