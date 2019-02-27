/**
*  @file      console.h
*  @brief     Interface for the methods that mimic the console library from C#.
*
*  @author    Evan Elias Young
*  @date      2019-02-26
*  @date      2019-02-26
*  @copyright Copyright 2019 Evan Elias Young. All rights reserved.
*/

#ifndef GPCU_CONSOLE_H_
#define GPCU_CONSOLE_H_

#include "stdafx.h"

namespace gpcu::console
{
void beep();
void clear();
void write(const std::string &s);
void writeline(const std::string &s);
std::string getline();
std::string getline(const std::string &s);
} // namespace gpcu::console

#endif // GPCU_CONSOLE_H_
