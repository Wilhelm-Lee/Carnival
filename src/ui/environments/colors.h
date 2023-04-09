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
} color16_t;

typedef struct S_colorhex
{
  /*
    0 1 1 1 1 1 1
    2 6 6 6 6 6 6
   ---------------
  # G X X Y Y Z Z
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
