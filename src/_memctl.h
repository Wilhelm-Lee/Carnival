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

/* Semi-Auto release malloc-ed memory spaces by using _stack.h */

#ifndef _MEMCTL_H
# define _MEMCTL_H

# include "_rtn.h"
# include "_var.h"

/* Extern from _exception.h */
extern inline void
THROW(excep_e e, const char *__restrict__ _file, long int _line,
      const char *__restrict__ _func, const char *__restrict__ _FMT, ...);

stack_t *__restrict __memstk;
/* TODO */

/**
 * Free all addresses >= IDX in __memstk
 * Throws OutOfBoundException
 */
void
_memctl_stkfree(size_t idx);

#endif /* NO _MEMCTL_H */
