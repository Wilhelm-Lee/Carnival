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

#include "_var.h"

void
_var_new(var_t *_v, size_t _sz)
{
  _v->_addr = (varp)malloc(_sz);
  _v->_sz = _sz;
  
  /* Null pointer check */
  if (_v->_addr == NULL)
    THROW(InstanceFailureException, __FILE__, __LINE__, __FUNCTION__,
          "Cannot properly malloc in function _var_new");
}

void
_var_del(var_t *_v)
{
  free(_v->_addr);
}

void
_var_ren(var_t *_v, size_t _sz)
{
  /* Detect _v had not been allocated */
  if (_v->_addr == NULL && _v->_sz == *(size_t*)NULL)
    THROW(IllegalArgumentException, __FILE__, __LINE__, __FUNCTION__,
          "Cannot reallocate before any initial allocations being done first.");
  
  _var_del(_v);
  _var_new(_v, _sz);
}

int
__var_szcmp(var_t *a, var_t *b)
{
  return (a->_sz - b->_sz);
}

int
_var_cmp(var_t *a, var_t *b)
{
  /* Not identical sizes */
  if (__var_szcmp(a, b))
    return 2;
    
  return (memcmp(a->_addr, b->_addr, a->_sz));
}

int
_var_cpy(var_t *dst, const var_t *src);

void
_var_swp(var_t *a, var_t *b)
{
  var_t c;
  _var_new(&c, a->_sz);
  
  _var_ren(a, b->_sz);
  _var_ren(b, c._sz);
  
  _var_del(&c);
}
