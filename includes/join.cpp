/**
*  @file      join.h
*  @brief     Implementation for the joining set of methods for arrays.
*
*  @author    Evan Elias Young
*  @date      2019-02-26
*  @date      2019-02-26
*  @copyright Copyright 2019 Evan Elias Young. All rights reserved.
*/

#include "stdafx.h"
#include "join.h"

namespace gpcu
{
template <class T>
std::string join(const std::vector<T> &a, const std::string &delim)
{
    std::unique_ptr<std::stringstream> sscanf(new std::stringstream());

    (*ss) << a[0];
    for (std::size_t i = 1; i < a.size(); i++)
    {
        (*ss) << delim << a[i++];
    }

    return (*ss).str();
}
} // namespace gpcu