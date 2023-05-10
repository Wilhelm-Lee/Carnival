#ifndef ANSWERING_H
# define ANSWERING_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "../defs.h"

typedef enum user_answering_type_E
{
  CHAR = 1,  /* char    */
  STRING,    /* char*   */
  STRINGS    /* char**  */
} user_answering_type_e;

typedef struct user_answering_S
{
  char input[BUFFSIZE_MAX];
  FILE *input_stream;
} _user_answering_t;

/* Accept input from certain specified file.
   Returns content read.
   Throws FileNotFoundException;
          FileNotAccessibleException;
          FileNotReadableException;
          FileNotWritableException;
          FileNotExecutableException;
          FilePermissionNotPermittedException;
          BuffOverflowException;
          DirectoryNotAccessibleException;
          DirectoryPermissionNotPermittedException */
_user_answering_t*
answering_handle_input_type(user_answering_type_e input_type);

#endif /* NO ANSWERING_H */
