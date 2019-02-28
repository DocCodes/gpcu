/**
*  @file      string.h
*  @brief     Interface for the string methods.
*
*  @author    Evan Elias Young
*  @date      2019-02-26
*  @date      2019-02-28
*  @copyright Copyright 2019 Evan Elias Young. All rights reserved.
*/

#ifndef GPCU_STRING_H_
#define GPCU_STRING_H_

#include "stdafx.h"

namespace gpcu
{
namespace string
{
void upper(std::string *s);
std::string upper_copy(std::string s);
void lower(std::string *s);
std::string lower_copy(std::string s);
void ltrim(std::string *s, const std::string &chars = "\t\n\v\f\r ");
std::string ltrim_copy(std::string s, const std::string &chars = "\t\n\v\f\r ");
void rtrim(std::string *s, const std::string &chars = "\t\n\v\f\r ");
std::string rtrim_copy(std::string s, const std::string &chars = "\t\n\v\f\r ");
void trim(std::string *s, const std::string &chars = "\t\n\v\f\r ");
std::string trim_copy(std::string s, const std::string &chars = "\t\n\v\f\r ");
std::size_t count(const std::string &s, const std::string &t);
std::size_t count(const std::string &s, const char &t);
bool split(std::string *a, const std::string &s, const std::string &delim);
bool split(std::string *a, const std::string &s, const char &delim);
bool startswith(const std::string& a, const std::string& b);
bool endswith(const std::string &a, const std::string &b);
} // namespace string
} // namespace gpcu

#endif // GPCU_STRING_H_