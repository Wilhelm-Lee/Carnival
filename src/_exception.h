/*
 *     This file is part of project https://github.com/WilliamPascal/Carnival
 *     Copyright (C) 2023  William Pascal
 *
 *     This program is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU General Public License as published by
 *     the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version.
 *
 *     This program is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU General Public License for more details.
 *
 *     You should have received a copy of the GNU General Public License
 *     along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef _EXCEPTION_H
# define _EXCEPTION_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>

/* par1="Exception"=_excep_e;
   par2="File"=__FILE__;
   par3="Line"=__LINE__;
   par4="Function"=__FUNCTION__ */
static const char *__restrict__ _EXCEP_FMT = "Throwed %s:\n\
                                                  \tat %s:%ld, func %s\n\
                                              ";
static const char *__restrict__ _DEF_EXCEP_FMT = "Throwed the %s\n\
                                                 ";

typedef enum _excep_e
{
  InstanceFailureException = 500,
  IllegalMemoryAccessException,
  IllegalArgumentException,
  OutOfBoundException,
  IllegalNulledException
} excep_e;

/* These exceptions would become a super class which is so-called
   "Abstract Class". */
static inline const char *
__excep_etos(excep_e _e)
{
  switch(_e)
    {
      /* Once malloc returns NULL, this exception could stop the programme
      for good. */
      case InstanceFailureException:
        return "InstanceFailureException";
      /* When in "_var.h" and "_array.h" ..., it is common to have problemss
         related to bounding restrictions. Therefor, to protect a programme
         by throwing this exception would be a better solution than just
         having a "Segmentation Fault (Core dumped)" in the end of the day. */
      case IllegalMemoryAccessException:
        return "IllegalMemoryAccessException";
      /* When passing through a function with given parameters, it is critical
         to check whether they are qualified for the function to take in.
         For example, if fucntion "void f(int a)" requires parameter "a"
         NOT to be negative, then we need to throw this exception for safety.
      */
      case IllegalArgumentException:
        return "IllegalArgumentException";
      /* When in an array, a pointer must NOT go out of the scheduled
         bound that limits the actual physical sizes on the memory.
         This exception is kind of similarity of IlligalMemoryAccessException.
         However, when using "_var.h" and "_array.h", there would be more
         complex situations that puts variables into a conception of
         generalisation for different size for one single variable.
         This requires non-system-builtin but systematic check mechanics to
         kick in. */
      case OutOfBoundException:
        return "OutOfBoundException";
      /* In some particular cases, you would meet on some scenarios
         that restricts the target to NOT be nulled. */
      case IllegalNulledException:
        return "IllegalNulledException";
      /* To be able to throw this exception, you must have typo in
         the name of targeting exception, or simply you just passed an
         unknown exception into this function. Therefor, it is no longer
         the responsibility for this function to "guess" which exception
         you were meant to throw. And UnknownException it is to be thrown. */
      default:
        return "UnknownException";
    }
}

/* Example:
      Required Macros:                ___M1___  ___M2___  _____M3_____

      THROW(InstanceFailureException, __FILE__, __LINE__, __FUNCTION__,
                                      ~~~~~~~~  ~~~~~~~~  ~~~~~~~~~~~~
           "Errored when instanting %s.\nGiven options is illegal:\n\
           %d, %lf", opt1, opt2); */
static inline void
THROW(excep_e e, const char *__restrict__ _file, long int _line,
      const char *__restrict__ _func, const char *__restrict__ _FMT, ...)
{
  if (_FMT == NULL)
    {
      fprintf(stderr, _DEF_EXCEP_FMT, __excep_etos(e));
      exit(EXIT_FAILURE);
    }

  /* Output secondary description about the thrown exception. */
  va_list _vlist;
  va_start(_vlist, _FMT);
  fprintf(stderr, ((_file == NULL && _line == -1 && _func == NULL)
                   ? _DEF_EXCEP_FMT
                   /* Ignore _FMT when outputting the exception title,
                      use _EXCEP_FMT instead. */
                   : _EXCEP_FMT), __excep_etos(e), _file, _line, _func);
  vfprintf(stderr, _FMT, _vlist);
  va_end(_vlist);

  exit(EXIT_FAILURE);
}

#endif /* NO _EXCEPTION_H */
