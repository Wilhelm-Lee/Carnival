#ifndef PAINTER_H
# define PAINTER_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include "../components/geoms.h"
# include "../environments/colors.h"
# include "cursors.h"

/* Returns the coordination of given cursor;
   Throws IllegalArgumentException */
geom_coordinate_t*
painter_curposid(cursor_t *cur);

/* Returns the coordination of the ONLY IDENTIFIABLE CURSOR;
   Throws CursorNotFoundException */
geom_coordinate_t*
painter_curpos(cursor_t *cur);

/* Returns path that cursor really moved
   Throws InvalidCoordinationException */
path_t
painter_movcur(cursor_t *cur, geom_coordinate_t *coor);

/* For majority of unix-like terminal (built-in colors)
   Returns "prc_t (A.K.A. painting return code type)"
   Throws InvalidArgumentException */
int
painter_draw16(cursor_t *cur, color16_t color16);

/* This function along with "colorhex_t" is based on
   a hypnosis of having a terminal with 256 colors supports.
   Throws InvalidArgumentException */
int
painter_drawhex(cursor_t *cur, colorhex_t colorhex);

#endif /* NO PAINTER_H */
