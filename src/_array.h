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

#ifndef _ARRAY_H
# define _ARRAY_H

# include <stdio.h>
# include "_var.h"
# include "_rtn.h"

/* Extern from _exception.h */
extern inline void
THROW(excep_e e, const char *__restrict__ _file, long int _line,
      const char *__restrict__ _func, const char *__restrict__ _FMT, ...);

typedef struct _array_t
{
  var_t *_arr;
  length_t _len;
} array_t;

/* By calculating relative element size, then times _IDX to get the
   absolute position in array _SRC */
void
__array_pgoto(var_t *_p, array_t *_src, index_t _idx);

/* Throws IllegalArgumentException */
var_t*
_array_getelem(array_t *_tar, index_t _idx);

/* Throws IllegalArgumentException */
void
_array_setelem(array_t *_tar, index_t _idx, var_t *_var);

/* Throws InstanceFailureException */
void
_array_newarr(array_t *_tar, size_t _sz, length_t _len);

/* Throws IllegalNulledException */
void
_array_delarr(array_t *_tar);

/* TipsForDevls: Reallocate _DST's size when the size of _SRC & _DST
   does not match */
_rtn_t
_array_mirror(array_t *_dst, const array_t *_src);

/* Returns subarray extracted from _src
   start from index (_off - 1) till index (_off + _len - 1)
   Throws OutOfBoundException */
array_t *
_array_subarr(index_t _off, length_t _len, array_t *_tar);

/* Throws OutOfBoundException,
          IllegalArgumentException */
_rtn_t
_array_insert(index_t _off, const array_t *_src);

/* Throws OutOfBoundException */
_rtn_t
_array_cutoff(index_t _off, length_t _len, array_t *_tar);

/* Returns true if identical */
bool
_array_cmparr(array_t *_dst, const array_t *_src);

#endif /* NO _ARRAY_H */
