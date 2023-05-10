#ifndef COLORS_H
# define COLORS_H

#ifdef __TTY__
# define __COLORS_TTY__
#endif /* __TTY__ */

#include <stdbool.h>
#include <stdint.h>

/* Color table */
typedef enum E_color16
{
  BLACK = 0, /* 0 #000000 */
  MAROON,    /* 1 #770000 */
  GREEN,     /* 2 #007700 */
  OLIVE,     /* 3 #777700 */
  NAVY,      /* 4 #000077 */
  PURPLE,    /* 5 #770077 */
  TEAL,      /* 6 #007777 */
  GREY,      /* 7 #777777 */
  SILVER,    /* 8 #AAAAAA */

  RED,       /* 9 #FF0000 */
  LIME,      /* A #00FF00 */
  YELLOW,    /* B #FFFF00 */
  BLUE,      /* C #0000FF */
  FUCHSIA,   /* D #FF00FF */
  AQUA,      /* E #00FFFF */
  WHITE      /* F #FFFFFF */
} color16_t;

typedef struct S_colorhex
{
  /*
    Possibility enumeration
    0 1 1 1 1 1 1  // x10
    2 6 6 6 6 6 6  // x1
   ---------------
  # G X X Y Y Z Z  // PATTERN
    0 0 0 0 0 0 0
    1 1 1 1 1 1 1
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

    Example:
      #1FF0332
      Means, a object which will be rendered on foreground,
      in colour represented by a hexadecimal value "FF0332".
  */

  bool _G;    /* TRUE for foreground; FALSE for background. */
  uint8_t _X1;  /* Hexadecimal value for R in RGB.
                -> Represented to the 17th bit in Hexadecimal */

  uint8_t _X2;  /* Hexadecimal value for R in RGB.
                -> Represented to the 1st  bit in Hexadecimal */

  uint8_t _Y1;  /* Hexadecimal value for G in RGB.
                -> Represented to the 17th bit in Hexadecimal */

  uint8_t _Y2;  /* Hexadecimal value for G in RGB.
                -> Represented to the 1st  bit in Hexadecimal */

  uint8_t _Z1;  /* Hexadecimal value for B in RGB.
                -> Represented to the 17th bit in Hexadecimal */

  uint8_t _Z2;  /* Hexadecimal value for B in RGB.
                -> Represented to the 1st  bit in Hexadecimal */

} colorhex_t;

#ifdef __CARNIVAL_UNIX__
typedef struct S_color_t
{
  /* In shell, coloring requires certain format to explain.
     For an instance, coloring with a foreground color "Dim blue (Navy)",
     needs a code, which is exactly "34" in Shell */
  int8_t _info[64];
  colorhex_t *_hex;
};
# define __CARNIVAL_COLORS_UNIX__
#elif defined __CARNIVAL_WIND__ /* __CARNIVAL_UNIX__ */

# error FIXME Finish __CARNIVAL_WIND__ fork.
# define __CARNIVAL_COLORS_WIND__

#endif /* __CARNIVAL_WIND__ */

#endif /* NO COLORS_H */
