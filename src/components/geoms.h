#ifndef GEOMS_H
# define GEOMS_H

#include "../defs.h"
#include "deco.h"

/* "GAREA" is stands for "Geometry Area";
  This is used for final representation only,
  not directly related with real geometry's size.
  GAREA is possible to change if geometry rotates. */
typedef struct S_garea
{
  int _height;
  int _width;
} garea;

typedef struct S_coordinate
{
  int _x;
  int _y;
} coordinate;

typedef coordinate _init_point;
/* To have objects movement recorded, we use _PATH to contain
   its movement for x and y */
typedef coordinate path;

typedef struct S_geom_meta
{
  _init_point *_cooip;
  garea       *_garea;
} _geom_meta;

typedef struct _S_geom_quadrate
{
  _geom_meta *_meta;
  int         _len_a;
  int         _len_b;
} _geom_quadrate;

int
geom_quadrate_init(_geom_quadrate quadrate);

#endif /* NO GEOMS_H */
