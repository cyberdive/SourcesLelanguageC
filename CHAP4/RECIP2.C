/* Recip2 calcule l'inverse d'un nombre.
             La division par 0 est empˆch‚e via une construction if ad‚quate. */
                                          
#include <stdio.h>                                      /* pour printf, scanf */

main()
{
   float x;

   printf("\033[2J");
   printf("Calcul de l'inverse d'un nombre non nul.\n");
   printf("Votre nombre : ");
   scanf("%f", &x);
   if (x)                                          /* si x est diff‚rent de 0 */
     printf("\nL'inverse du nombre est %f", 1/x);
}

