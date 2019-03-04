/**
*  @file      random.h
*  @brief     Interface for the random methods.
*
*  @author    Evan Elias Young
*  @date      2019-03-01
*  @date      2019-03-04
*  @copyright Copyright 2019 Evan Elias Young. All rights reserved.
*/

#ifndef GPCU_RANDOM_H_
#define GPCU_RANDOM_H_

#include "stdafx.h"

typedef std::mersenne_twister_engine<std::uint_fast32_t, 32, 624, 397, 31, 0x9908B0DF, 11, 0xFFFFFFFF, 7, 0x9D2C5680, 15, 0xEFC60000, 18, 0x1312FD7> mt32;
typedef std::mersenne_twister_engine<std::uint_fast64_t, 64, 312, 156, 31, 0xB5026F5AA96619E9, 29, 0x5555555555555555, 17, 0x71D67FFFEDA60000, 37, 0xFFF7EEE000000000, 43, 0x1312FD7> mt64;

namespace gpcu
{
namespace random
{
void seed(int32_t s);
std::uint32_t next();
std::uint32_t next(uint32_t max);
std::int32_t next(int32_t min, int32_t max);
double nextdouble();
} // namespace random

namespace random64
{
void seed(int64_t s);
std::uint64_t next();
std::uint64_t next(uint64_t max);
std::int64_t next(int64_t min, int64_t max);
double nextdouble();
} // namespace random64
} // namespace gpcu

#endif // GPCU_RANDOM_H_