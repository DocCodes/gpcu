//  os.hpp
//  gpcu
//
//  Created by Evan Elias Young on 2019-01-18.
//  Copyright 2019 Evan Elias Young. All rights reserved.

#ifndef GPCU_OS_HPP_  // include guard
#define GPCU_OS_HPP_

namespace gpcu {
  enum OperatingSystem {
    DOS,
    linux,
    macOS9,
    macOSX,
    solaris,
    sunOS,
    win16,
    win32,
    win64
  };

  OperatingSystem os() {
    #if defined(MSDOS)
    return DOS;
    #elif defined(__MSDOS__)
    return DOS;
    #elif defined(_MSDOS)
    return DOS;
    #elif defined(__DOS__)
    return DOS;
    #elif defined(__linux__)
    return linux;
    #elif defined(macintosh)
    return macOS9;
    #elif defined(Macintosh)
    return macOS9;
    #elif defined(__APPLE__)
    return macOSX;
    #if defined(sun) || defined(__sun)
    #if defined(__SVR4) || defined(__svr4__)
    return solaris;
    #else
    return sunOS;
    #endif
    #elif defined(_WIN16)
    return win16;
    #elif defined(_WIN32)
    return win32;
    #elif defined(_WIN64)
    return win64;
    #elif defined(__WIN32__)
    return win32;
    #elif defined(__TOS_WIN__)
    return win16;
    #elif defined(__WINDOWS__)
    return win32;
    #endif
  }
}  // namespace gpcu

#endif  // GPCU_OS_HPP_
