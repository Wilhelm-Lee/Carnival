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

#ifndef _VAR_H
# define _VAR_H

# include <stdbool.h>
# include "_exception.h"

/* Extern from _exception.h */
extern inline void
THROW(excep_e e, const char *__restrict__ _file, long int _line,
      const char *__restrict__ _func, const char *__restrict__ _FMT, ...);

# ifndef LENGTH_T
typedef unsigned long length_t;
#  define LENGTH_T
# endif /* NO LENGTH_T */

/* When converting void into ptr with 8 Bytes size as char* is, we call it varp.
   It stands for "variable pointer" */
# ifndef VARP
typedef char* varp;
#  define VARP
# endif /* NO VARP */

/* When converting void into ptr with 1 Byte size as char is, we call it vars.
   It stands for "variable size" */
# ifndef VARS
typedef char vars;
#  define VARS
# endif /* NO VARS */

# ifndef INDEX_T
typedef unsigned long index_t;
#  define INDEX_T
# endif /* NO INDEX_T */

typedef struct _var_t
{
  void *_addr;
  size_t _sz;
} var_t;

void
_var_new(var_t *_v, size_t _sz);

void
_var_del(var_t *_v);

/* "ren" stands for "Renew" */
void
_var_ren(var_t *_v, size_t _sz);

/* Return delta of a->_sz and b->_sz
   If <0, then a<b;
   If =0, then a=b;
   If >0, then a>b; */
int
__var_szcmp(var_t *a, var_t *b);

/* Return 1 for a>b; 0 for a==b; -1 for a<b; 2 for incompatible */
int
_var_cmp(var_t *a, var_t *b);

/* Returns size of copied buff. -1 for error */
int
_var_cpy(var_t *dst, const var_t *src);

void
_var_swp(var_t *a, var_t *b);

#endif /* NO _VAR_H */
