/*** cube6 montre comment d‚clarer globalement des fonctions ***/

#include <stdio.h>

double first(void);                                    /* d‚claration globale */
double second(double x);                 /* des fonctions 'first' et 'second' */

main()
  {
     printf("\nVolume = %f", first());        /* appel de la fonction 'first' */
  }

double first(void)                       /* d‚finition de la fonction 'first' */
  {
     double e;
     printf("Arˆte ? ");
     scanf("%lf", &e);
     return (second(e));                     /* appel de la fonction 'second' */
  }
 
double second(double x)                 /* d‚finition de la fonction 'second' */
  {
     return (x * x * x);
  }
