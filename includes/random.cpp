/**
*  @file      random.cpp
*  @brief     Implementation for the random methods.
*
*  @author    Evan Elias Young
*  @date      2019-03-01
*  @date      2019-03-01
*  @copyright Copyright 2019 Evan Elias Young. All rights reserved.
*/

#include "stdafx.h"
#include "random.h"

namespace gpcu
{
namespace random
{
mt32 randGen = mt32();

/**
* @brief  Returns a non-negative random integer.
* @since  2.8.0-66 (0x0208000042)
* @return A non-negative random integer.
*/
std::uint32_t next()
{
  return next(std::pow(2, 32) - 1);
}

/**
* @brief  Returns a non-negative random integer that is less than the specified maximum.
* @since  2.8.0-66 (0x0208000042)
* @param  max The exclusive upper bound of the random number to be generated.
* @return A non-negative random integer.
*/
std::uint32_t next(uint32_t max)
{
  if (max == 0)
  {
    return 0;
  }
  return std::round(max * nextdouble());
}

/**
* @brief  Returns a random integer that is within a specified range.
* @since  2.8.0-66 (0x0208000042)
* @param  min The inclusive lower bound of the random number returned.
* @param  max The exclusive upper bound of the random number to be generated.
* @return A non-negative random integer.
*/
std::int32_t next(int32_t min, int32_t max)
{
  if (min > max)
  {
    std::range_error("min is greater than max");
  }
  return std::round(nextdouble() * (max - min)) + min;
}

/**
* @brief  Returns a random floating-point number that is greater than or equal to 0.0, and less than 1.0.
* @since  2.8.0-66 (0x0208000042)
* @return A double-precision floating point number that is greater than or equal to 0.0, and less than 1.0.
*/
double nextdouble()
{
  return randGen() / (std::pow(2, 32) - 1);
}
} // namespace random
namespace random64
{
mt64 randGen = mt64();

/**
* @brief  Returns a non-negative random 64-bit integer.
* @since  2.8.0-66 (0x0208000042)
* @return A non-negative random 64-bit integer.
*/
std::uint64_t next()
{
  return next(std::pow(2, 64) - 1);
}

/**
* @brief  Returns a non-negative random 64-bit integer that is less than the specified maximum.
* @since  2.8.0-66 (0x0208000042)
* @param  max The exclusive upper bound of the random number to be generated.
* @return A non-negative random 64-bit integer.
*/
std::uint64_t next(uint64_t max)
{
  if (max == 0)
  {
    return 0;
  }

  return std::round(max * nextdouble());
}

/**
* @brief  Returns a random 64-bit integer that is within a specified range.
* @since  2.8.0-66 (0x0208000042)
* @param  min The inclusive lower bound of the random number returned.
* @param  max The exclusive upper bound of the random number to be generated.
* @return A non-negative random 64-bit integer.
*/
std::int64_t next(int64_t min, int64_t max)
{
  if (min > max)
  {
    std::range_error("min is greater than max");
  }
  return std::round(nextdouble() * (max - min)) + min;
}

/**
* @brief  Returns a random floating-point number that is greater than or equal to 0.0, and less than 1.0.
* @since  2.8.0-66 (0x0208000042)
* @return A double-precision floating point number that is greater than or equal to 0.0, and less than 1.0.
*/
double nextdouble()
{
  return randGen() / (std::pow(2, 64) - 1);
}
} // namespace random64
} // namespace gpcu