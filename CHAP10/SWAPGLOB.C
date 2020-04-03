/*** swapglob permute les valeurs de deux variables globales ***/

#include <stdio.h>

   int a = 3, b = 5;                                    /* variables globales */

main()
  {
     void swap(void);            /* d‚claration de la fonction d'‚change swap */

     printf("valeur de a : %d\tValeur de b : %d", a, b);

     swap();                        /* appelle swap : fonction sans paramŠtre */

     printf("\nValeur de a : %d\tValeur de b : %d", a, b);
  }

void swap(void)                /* ‚change les valeurs de 2 variables globales */
  {
     int buffer;

     buffer = a;                                       /* permute les valeurs */
     a = b;                                                  /* des variables */
     b = buffer;                                                  /* globales */
  }
