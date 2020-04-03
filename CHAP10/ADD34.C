/*** add34 additionne les constantes 3 et 4 ***/

#include <stdio.h>

void add(short a, short b);                             /* d‚claration de add */
void showsum(long sum);                             /* d‚claration de showsum */

main()
  {
     short x = 3, y = 4;
     add(x,y);                                                 /* appelle add */
  }

void add(short a, short b)                               /* d‚finition de add */
  {
     showsum(a+b);                                         /* appelle showsum */
  }

void showsum(long sum)                               /* d‚finition de showsum */
  {
     printf("%ld", sum);                                    /* appelle printf */
  }
