/**
*  @file      all.h
*  @brief     Includes all other headers in the project.
*
*  @author    Evan Elias Young
*  @date      2019-01-17
*  @date      2019-03-04
*  @copyright Copyright 2019 Evan Elias Young. All rights reserved.
*/

#ifndef GPCU_H_
#define GPCU_H_

/**
* @brief Contains the major, minor, patch, and revision versions of GPCU.
* @since 2.2.0-37 (0x0202000025)
*
* The first four bytes contain the major number,
* the next four contain the minor number,
* the next four contain the patch number,
* and the last eight contain the revision number.
*/
#define GPCU_VERSION_ 0x0208000048

#include "stdafx.h"

#include "color.h"
#include "colors.h"
#include "console.h"
#include "exits.h"
#include "join.h"
#include "limits.h"
#include "list.h"
#include "os.h"
#include "pause.h"
#include "random.h"
#include "string.h"

#endif // GPCU_H_
