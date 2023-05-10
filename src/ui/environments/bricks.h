#ifndef BRICKS_H
# define BRICKS_H

# include "colors.h"

typedef struct bricks_S
{
  colorhex_t *_color;
  bool _is_cursor_on;
} bricks_t;

#endif /* NO BRICKS_H */
