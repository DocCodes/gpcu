/**
*  @file      pause.h
*  @brief     Interface for pause and prompts.
*
*  @author    Evan Elias Young
*  @date      2019-02-26
*  @date      2019-02-26
*  @copyright Copyright 2019 Evan Elias Young. All rights reserved.
*/

#ifndef GPCU_PAUSE_H_
#define GPCU_PAUSE_H_

#include "stdafx.h"

namespace gpcu
{
void pause();
void pause(const std::string &msg);
} // namespace gpcu

#endif // GPCU_PAUSE_H_