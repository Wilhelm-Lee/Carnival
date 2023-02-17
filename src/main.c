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

/* Macro __STUDY_Carnival_MinGW__ is an identifier for further development
   which involves in when vraiance of other projects come together. */
#ifdef __STUDY_Carnival_MinGW__
# error Macro "__STUDY_Carnival_MinGW__" should only be defined in main.c
#endif /* __STUDY_Carnival_MinGW__ */

#ifdef __STUDY_Carnival_GNU__
# warning Macro __STUDY_Carnival_GNU__ is defined. Consider to merge them into one.
#endif /* __STUDY_Carnival_GNU__ */

#define __STUDY_Carnival_MinGW__ 1

/*** Welcome to Carnival MinGW, developers! ***/

#include "_var.h"

int
main(int argc, char *argv[]);  /* For ANSI C */

int
main(int argc, char *argv[])
{
         
  var_t _v;
  _var_new(&_v, sizeof(int));
  
  fprintf(stdout, "%p %llu\n", _v._addr, _v._sz);
  
  _var_ren(&_v, sizeof(double));
  
  fprintf(stdout, "%p %llu\n", _v._addr, _v._sz);
  
  _var_del(&_v); /* Mulfunctioning :( */
  
  /* Memory was not freed, no Segmentation Fault */
  fprintf(stdout, "%p %llu\n", _v._addr, _v._sz);
  
  return 0;
}
