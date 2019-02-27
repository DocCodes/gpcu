/**
*  @file      join.h
*  @brief     Interface for the joining set of methods for arrays.
*
*  @author    Evan Elias Young
*  @date      2019-02-26
*  @date      2019-02-26
*  @copyright Copyright 2019 Evan Elias Young. All rights reserved.
*/

#ifndef GPCU_JOIN_H_
#define GPCU_JOIN_H_

#include "stdafx.h"

namespace gpcu
{
template <class T>
std::string join(const std::vector<T> &a, const std::string &delim);
} // namespace gpcu

#endif // GPCU_JOIN_H_