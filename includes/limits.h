/**
*  @file      limits.h
*  @brief     The limits for numbers.
*
*  @author    Evan Elias Young
*  @date      2019-03-01
*  @date      2019-03-04
*  @copyright Copyright 2019 Evan Elias Young. All rights reserved.
*/

#ifndef INT8_MAX
#define INT8_MAX 0x7F
#endif // INT8_MAX

#ifndef INT8_MIN
#define INT8_MIN -0x80
#endif // INT8_MIN

#ifndef UINT8_MAX
#define UINT8_MAX 0xFF
#endif // UINT8_MAX

#ifndef CHAR_MAX
#define CHAR_MAX INT8_MAX
#endif // CHAR_MAX

#ifndef CHAR_MIN
#define CHAR_MIN INT8_MIN
#endif // CHAR_MIN

#ifndef UCHAR_MAX
#define UCHAR_MAX UINT8_MAX
#endif // UCHAR_MAX

#ifndef INT16_MAX
#define INT16_MAX 0x7FFF
#endif // INT16_MAX

#ifndef INT16_MIN
#define INT16_MIN -0x8000
#endif // INT16_MIN

#ifndef UINT16_MAX
#define UINT16_MAX 0xFFFF
#endif // UINT16_MAX

#ifndef SHORT_MAX
#define SHORT_MAX INT16_MAX
#endif // SHORT_MAX

#ifndef SHORT_MIN
#define SHORT_MIN INT16_MIN
#endif // SHORT_MIN

#ifndef USHORT_MAX
#define USHORT_MAX UINT16_MAX
#endif // USHORT_MAX

#ifndef INT32_MAX
#define INT32_MAX 0x7FFFFFFF
#endif // INT32_MAX

#ifndef INT32_MIN
#define INT32_MIN -0x80000000
#endif // INT32_MIN

#ifndef UINT32_MAX
#define UINT32_MAX 0xFFFFFFFF
#endif // UINT32_MAX

#ifndef INT_MAX
#define INT_MAX INT32_MAX
#endif // INT_MAX

#ifndef INT_MIN
#define INT_MIN INT32_MIN
#endif // INT_MIN

#ifndef UINT_MAX
#define UINT_MAX UINT32_MAX
#endif // UINT_MAX

#ifndef LONG_MAX
#define LONG_MAX INT32_MAX
#endif // LONG_MAX

#ifndef LONG_MIN
#define LONG_MIN INT32_MIN
#endif // LONG_MIN

#ifndef ULONG_MAX
#define ULONG_MAX UINT32_MAX
#endif // ULONG_MAX

#ifndef INT64_MAX
#define INT64_MAX 0x7FFFFFFFFFFFFFFF
#endif // INT64_MAX

#ifndef INT64_MIN
#define INT64_MIN -0x8000000000000000
#endif // INT64_MIN

#ifndef UINT64_MAX
#define UINT64_MAX 0xFFFFFFFFFFFFFFFF
#endif // UINT64_MAX

#ifndef LONGLONG_MAX
#define LONGLONG_MAX INT64_MAX
#endif // LONGLONG_MAX

#ifndef LONGLONG_MIN
#define LONGLONG_MIN INT64_MIN
#endif // LONGLONG_MIN

#ifndef ULONGLONG_MAX
#define ULONGLONG_MAX UINT64_MAX
#endif // ULONGLONG_MAX

