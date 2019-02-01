/**
*  @file      all.hpp
*  @brief     Includes all other headers in the project.
*
*  @author    Evan Elias Young
*  @date      2019-01-17
*  @date      2019-01-31
*  @copyright Copyright 2019 Evan Elias Young. All rights reserved.
*/

#ifndef GPCU_HPP_  // include guard
#define GPCU_HPP_

/**
* @brief Contains the major, minor, patch, and revision versions of GPCU.
*
* The first four bytes contain the major number,
* the next four contain the minor number,
* the next four contain the patch number,
* and the last eight contain the revision number.
*/
#define GPCU_VERSION_ 0x020400002C

#include "color.hpp"
#include "colors.hpp"
#include "console.hpp"
#include "join.hpp"
#include "os.hpp"
#include "pause.hpp"
#include "string.hpp"

#endif  // GPCU_HPP_
