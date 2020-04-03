/*** show35 donne un exemple de passage de paramŠtres par valeur ***/

#include <stdio.h>

main()
  {
     void show(int x, int y);                          /* d‚claration de show */
     int a = 3, b = 5;                            /* variables locales … main */
     show(a, b);                          /* appelle show: passage par valeur */
  }

void show(int x, int y)                                 /* d‚finition de show */
  {
     printf("Valeur 1 : %d\tValeur 2 : %d", x, y);
  }
