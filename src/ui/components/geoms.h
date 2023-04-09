#ifndef GEOMS_H
# define GEOMS_H

#include "../../defs.h"
#include "deco.h"

/* "GAREA" is stands for "Geometry Area";
  This is used for final representation only,
  not directly related with real geometry's size.
  GAREA is possible to change if geometry rotates. */
typedef struct S_garea
{
  int _height;
  int _width;
} geom_garea_t;

typedef struct S_coordinate
{
  int _x;
  int _y;
} geom_coordinate_t;

typedef geom_coordinate_t _init_point;
/* To have objects movement recorded, we use _PATH to contain
   its movement for x and y */
typedef geom_coordinate_t path_t;

typedef struct S_geom_meta
{
  _init_point *_coor_init;
  geom_garea_t *_garea;
} geom_meta_t;

typedef struct _S_geom_quadrate
{
  geom_meta_t *_meta;
  int         _len_a;
  int         _len_b;
} geom_quadrate_t;

int
geom_quadrate_init(geom_quadrate_t quadrate);

#endif /* NO GEOMS_H */

