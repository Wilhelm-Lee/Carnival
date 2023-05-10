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
/* Microsoft(TM) Windows(R) */
#elif defined __MINGW32__ || __MINGW64__ /* __gnu_linux__ || __linux__
                                            || __OpenBSD__ ||  __FreeBSD__
                                            || __GNUC__ */
# define __CARNIVAL_WIND__
#endif /* __MINGW32__ || __MINGW64__ */

#ifndef BUFFSIZE_MAX
# define BUFFSIZE_MAX 4096
#endif /* NO BUFFSIZE_MAX */

#ifndef WIDE_BUFFSIZE_MAX
# define WIDE_BUFFSIZE_MAX (BUFFSIZE_MAX * 2)
#endif /* NO WIDE_BUFFSIZE_MAX */

#endif /* NO DEFS_H */
