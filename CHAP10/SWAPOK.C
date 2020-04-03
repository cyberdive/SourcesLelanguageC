/*** SWAPOK permute les valeurs de deux variables au moyen d'une fonction ***/ 
/*** ad hoc. Les paramŠtres sont pass‚s par adresses.                     ***/

#include <stdio.h>

main()
  {
     void swap(int *x, int *y);     /* d‚claration de la fonction d'‚change */
                                    /* 'swap' : les paramŠtres formels sont */
                                                     /* des pointeurs 'int' */

     int a = 3, b = 5;

     printf("Valeur de a : %d\tValeur de b : %d", a, b);

     swap(&a, &b);                              /* swap : call by reference */

     printf("\nValeur de a : %d\tValeur de b : %d", a, b);
  }

void swap(int *x, int *y)          /* ‚change les valeurs de deux variables */
  {
     int buffer;
     buffer = *x;            /* accŠs aux valeurs des variables … manipuler */
     *x = *y;                                     /* par l'interm‚diaire de */
     *y = buffer;                                 /* pointeurs d‚r‚f‚renc‚s */
  }
