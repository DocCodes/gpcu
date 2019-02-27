/**
*  @file      string.h
*  @brief     Interface for the string methods.
*
*  @author    Evan Elias Young
*  @date      2019-02-26
*  @date      2019-02-26
*  @copyright Copyright 2019 Evan Elias Young. All rights reserved.
*/

#ifndef GPCU_STRING_H_
#define GPCU_STRING_H_

#include "stdafx.h"

namespace gpcu::string
{
void upper(std::string *s);
void lower(std::string *s);
void ltrim(std::string *s, const std::string &chars = "\t\n\v\f\r ");
void rtrim(std::string *s, const std::string &chars = "\t\n\v\f\r ");
void trim(std::string *s, const std::string &chars = "\t\n\v\f\r ");
std::size_t count(const std::string &s, const std::string &t);
std::size_t count(const std::string &s, const char &t);
bool split(std::string *a, const std::string &s, const std::string &delim);
bool split(std::string *a, const std::string &s, const char &delim);
} // namespace gpcu::string

#endif // GPCU_STRING_H_