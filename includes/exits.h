/**
*  @file      exits.h
*  @brief     The exit codes.
*
*  @author    Evan Elias Young
*  @date      2019-02-27
*  @date      2019-03-04
*  @copyright Copyright 2019 Evan Elias Young. All rights reserved.
*/

#ifndef EXIT_OK
#define EXIT_OK 0x00          // no error, success
#endif // EXIT_OK

#ifndef EXIT_BASE
#define EXIT_BASE 0x01        // general error
#endif // EXIT_BASE

#ifndef EXIT_USAGE
#define EXIT_USAGE 0x40       // command line usage error
#endif // EXIT_USAGE

#ifndef EXIT_DATAERR
#define EXIT_DATAERR 0x41     // data format error
#endif // EXIT_DATAERR

#ifndef EXIT_NOINPUT
#define EXIT_NOINPUT 0x42     // cannot open input
#endif // EXIT_NOINPUT

#ifndef EXIT_NOUSER
#define EXIT_NOUSER 0x43      // addressee unknown
#endif // EXIT_NOUSER

#ifndef EXIT_NOHOST
#define EXIT_NOHOST 0x44      // host name unknown
#endif // EXIT_NOHOST

#ifndef EXIT_UNAVAILABLE
#define EXIT_UNAVAILABLE 0x45 // service unavailable
#endif // EXIT_UNAVAILABLE

#ifndef EXIT_SOFTWARE
#define EXIT_SOFTWARE 0x46    // internal software error
#endif // EXIT_SOFTWARE

#ifndef EXIT_OSERR
#define EXIT_OSERR 0x47       // system error (e.g., can't fork)
#endif // EXIT_OSERR

#ifndef EXIT_OSFILE
#define EXIT_OSFILE 0x48      // critical OS file missing
#endif // EXIT_OSFILE

#ifndef EXIT_CANTCREAT
#define EXIT_CANTCREAT 0x49   // can't create (user) output file
#endif // EXIT_CANTCREAT

#ifndef EXIT_IOERR
#define EXIT_IOERR 0x4A       // input/output error
#endif // EXIT_IOERR

#ifndef EXIT_TEMPFAIL
#define EXIT_TEMPFAIL 0x4B    // temp failure; user is invited to retry
#endif // EXIT_TEMPFAIL

#ifndef EXIT_PROTOCOL
#define EXIT_PROTOCOL 0x4C    // remote error in protocol
#endif // EXIT_PROTOCOL

#ifndef EXIT_NOPERM
#define EXIT_NOPERM 0x4D      // permission denied
#endif // EXIT_NOPERM

#ifndef EXIT_CONFIG
#define EXIT_CONFIG 0x4E      // configuration error
#endif // EXIT_CONFIG

#ifndef EXIT_INVOKE
#define EXIT_INVOKE 0x7E      // the command executed cannot be invoked
#endif // EXIT_INVOKE

#ifndef EXIT_NOCOMMAND
#define EXIT_NOCOMMAND 0x7F   // command not found
#endif // EXIT_NOCOMMAND

#ifndef EXIT_CTRLC
#define EXIT_CTRLC 0x82       // script terminated by control-c
#endif // EXIT_CTRLC
