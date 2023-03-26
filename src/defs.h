#ifndef DEFS_H
# define DEFS_H

#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/ioctl.h>

/* Pre-defined macros for operating system */
/* GNU/Linux */
#if defined __gnu_linux__ || defined __linux__ \
            || defined __OpenBSD__ || defined __FreeBSD__ || __GNUC__
# define __CARNIVAL_UNIX__
#elif defined __MINGW32__ || __MINGW64__ /* __gnu_linux__ || __linux__
                                            || __OpenBSD__ ||  __FreeBSD__
                                            || __GNUC__ */
# define __CARNIVAL_WIND__
#endif /* __MINGW32__ || __MINGW64__ */

#endif /* NO DEFS_H */
