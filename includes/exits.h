/**
*  @file      exits.h
*  @brief     The exit codes.
*
*  @author    Evan Elias Young
*  @date      2019-02-27
*  @date      2019-02-27
*  @copyright Copyright 2019 Evan Elias Young. All rights reserved.
*/

#define EXIT_OK 0x00          // no error, success
#define EXIT_BASE 0x01        // general error
#define EXIT_USAGE 0x40       // command line usage error
#define EXIT_DATAERR 0x41     // data format error
#define EXIT_NOINPUT 0x42     // cannot open input
#define EXIT_NOUSER 0x43      // addressee unknown
#define EXIT_NOHOST 0x44      // host name unknown
#define EXIT_UNAVAILABLE 0x45 // service unavailable
#define EXIT_SOFTWARE 0x46    // internal software error
#define EXIT_OSERR 0x47       // system error (e.g., can't fork)
#define EXIT_OSFILE 0x48      // critical OS file missing
#define EXIT_CANTCREAT 0x49   // can't create (user) output file
#define EXIT_IOERR 0x4A       // input/output error
#define EXIT_TEMPFAIL 0x4B    // temp failure; user is invited to retry
#define EXIT_PROTOCOL 0x4C    // remote error in protocol
#define EXIT_NOPERM 0x4D      // permission denied
#define EXIT_CONFIG 0x4E      // configuration error
#define EXIT_INVOKE 0x7E      // the command executed cannot be invoked
#define EXIT_NOCOMMAND 0x7F   // command not found
#define EXIT_CTRLC 0x82       // script terminated by control-c