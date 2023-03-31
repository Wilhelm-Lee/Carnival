#ifndef COLORS_H
# define COLORS_H

#ifdef __TTY__
# define __COLOR_TTY__
#endif /* __TTY__ */

/* Color table */
typedef enum E_color_e
{

  /*
    0 0 1 1 1 1 1 1
    2 2 6 6 6 6 6 6
   -----------------
  # G H X X Y Y Z Z
    0 0 0 0 0 0 0 0
    1 1 1 1 1 1 1 1
        2 2 2 2 2 2
        3 3 3 3 3 3
        4 4 4 4 4 4
        5 5 5 5 5 5
        6 6 6 6 6 6
        7 7 7 7 7 7
        8 8 8 8 8 8
        9 9 9 9 9 9
        A A A A A A
        B B B B B B
        C C C C C C
        D D D D D D
        E E E E E E
        F F F F F F
  */

  BLACK = 0, /* #000000 */
  MAROON,    /* #770000 */
  GREEN,     /* #007700 */
  OLIVE,     /* #777700 */
  NAVY,      /* #000077 */
  PURPLE,    /* #770077 */
  TEAL,      /* #007777 */
  GREY,      /* #777777 */

  SILVER,    /* #AAAAAA */
  RED,       /* #FF0000 */
  LIME,      /* #00FF00 */
  YELLOW,    /* #FFFF00 */
  BLUE,      /* #0000FF */
  FUCHSIA,   /* #FF00FF */
  AQUA,      /* #00FFFF */
  WHITE      /* #FFFFFF */
} color_e;

#ifdef __CARNIVAL_UNIX__
typedef struct S_color_t
{
  /* In shell, coloring requires certain format to explain.
     For an instance, coloring with a foreground color "Dim blue (Navy)",
     needs a code, which is exactly "34" in Shell */
  int8_t _info[64];
}
#elif defined __CARNIVAL_WIND__ /* __CARNIVAL_UNIX__ */

#endif /* __CARNIVAL_WIND__ */

#endif /* NO COLORS_H */
