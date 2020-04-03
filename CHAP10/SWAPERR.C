/*** SWAPERR donne un exemple d'essai infructueux de permutation de ***/
/*** deux variables, r‚alis‚e … l'aide d'une fonction sp‚cifique    ***/

#include <stdio.h>

main()
  {
     void swap(int x, int y);                   /* d‚claration de la fonction */
                                                                                                    lis‚e … l'aide d'une fonction /* de permutation 'swap' */
     int a = 3, b = 5;
     
     printf("Valeur de a : %d\tValeur de b : %d", a, b);
     swap(a, b);   /* swap : appel par valeur */
     printf("Valeur de a : %d\tValeur de b : %d", a, b);
    }

void swap(int x, int y)                 /* est cens‚e permuter les valeurs de */
                                   /* deux variables de la fonction appelante */
    {
          int buffer;
          buffer = x;   /* */
          x = y;                                                    /* permutation */
     y = buffer;   /* */
  }
