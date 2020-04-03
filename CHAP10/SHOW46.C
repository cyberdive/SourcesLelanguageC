/*** show46 prouve qu'en cas de passage de paramŠtres par valeur, ***/
/**  ce sont les copies et non les originaux qui sont transmis.   ***/

#include <stdio.h>

main()
  {
     void show(int x, int y);                          /* d‚claration de show */
     int a = 3, b = 5;                            /* variables locales … main */

     printf("Valeurs des variables dans 'main' : %d\t%d\n", a, b);

     show(a, b);                         /* appelle show : passage par valeur */

     printf("Valeurs des variables dans 'main' : %d\t%d", a, b);
  }

void show(int x, int y)                                 /* d‚finition de show */
  {
     x++;
     y++;
     printf("Valeurs des variables dans 'show' : %d\t%d\n", x, y);
  }
