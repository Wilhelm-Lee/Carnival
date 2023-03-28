#ifndef PAINTER_H
# define PAINTER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../components/geoms.h"
#include "cursors.h"
#include "../environments/colors.h"

/* Returns the coordination of given cursor;
   Throws IllegalArgumentException */
coordinate*
painter_curposid(cursor *cur);

/* Returns the coordination of the ONLY IDENTIFIABLE CURSOR;
   Throws CursorNotFoundException */
coordinate*
painter_curpos(cursor *cur);

/* Returns path that cursor really moved */
path
painter_movcur(cursor *cur, coordinate *coor);

int
painter_draw(cursor *cur, color_e color);

#endif /* NO PAINTER_H */
