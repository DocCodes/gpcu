/**
*  @file      limits.h
*  @brief     The limits for numbers.
*
*  @author    Evan Elias Young
*  @date      2019-03-01
*  @date      2019-03-01
*  @copyright Copyright 2019 Evan Elias Young. All rights reserved.
*/

#ifndef INT8_MAX
#define INT8_MAX 0x7F
#endif

#ifndef INT8_MIN
#define INT8_MIN -0x80
#endif

#ifndef UINT8_MAX
#define UINT8_MAX 0xFF
#endif

#ifndef CHAR_MAX
#define CHAR_MAX INT8_MAX
#endif

#ifndef CHAR_MIN
#define CHAR_MIN INT8_MIN
#endif

#ifndef UCHAR_MAX
#define UCHAR_MAX UINT8_MAX
#endif

#ifndef INT16_MAX
#define INT16_MAX 0x7FFF
#endif

#ifndef INT16_MIN
#define INT16_MIN -0x8000
#endif

#ifndef UINT16_MAX
#define UINT16_MAX 0xFFFF
#endif

#ifndef SHORT_MAX
#define SHORT_MAX INT16_MAX
#endif

#ifndef SHORT_MIN
#define SHORT_MIN INT16_MIN
#endif

#ifndef USHORT_MAX
#define USHORT_MAX UINT16_MAX
#endif

#ifndef INT32_MAX
#define INT32_MAX 0x7FFFFFFF
#endif

#ifndef INT32_MIN
#define INT32_MIN -0x80000000
#endif

#ifndef UINT32_MAX
#define UINT32_MAX 0xFFFFFFFF
#endif

#ifndef INT_MAX
#define INT_MAX INT32_MAX
#endif

#ifndef INT_MIN
#define INT_MIN INT32_MIN
#endif

#ifndef UINT_MAX
#define UINT_MAX UINT32_MAX
#endif

#ifndef LONG_MAX
#define LONG_MAX INT32_MAX
#endif

#ifndef LONG_MIN
#define LONG_MIN INT32_MIN
#endif

#ifndef ULONG_MAX
#define ULONG_MAX UINT32_MAX
#endif

#ifndef INT64_MAX
#define INT64_MAX 0x7FFFFFFFFFFFFFFF
#endif

#ifndef INT64_MIN
#define INT64_MIN -0x8000000000000000
#endif

#ifndef UINT64_MAX
#define UINT64_MAX 0xFFFFFFFFFFFFFFFF
#endif

#ifndef LONGLONG_MAX
#define LONGLONG_MAX INT64_MAX
#endif

#ifndef LONGLONG_MIN
#define LONGLONG_MIN INT64_MIN
#endif

#ifndef ULONGLONG_MAX
#define ULONGLONG_MAX UINT64_MAX
#endif
