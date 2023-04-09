#ifndef CURSORS_H
# define CURSORS_H

#include "../components/geoms.h"

typedef struct S_cursor
{
  S_coordinate *_pos;
  char *_selection;
} cursor_t;

#endif /* NO CURSORS_H */
