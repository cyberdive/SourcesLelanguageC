/* recip1 calcule l'inverse d'un nombre. Le programme est interrompu par la
                           fonction exit si c'est la valeur 0 qui est saisie. */

#include <stdio.h>                                      /* pour printf, scanf */
#include <stdlib.h>                                              /* pour exit */
main()
{
  float x;

  printf("\033[2J");
  printf("Calcul de la valeur inverse pour tous les nombres non nuls.\n");
  printf("Votre nombre : ");
  scanf("%f", &x);

  if (!x)                                                    /* si x vaut 0 : */
    exit(1);             /* fin du programme pour ‚viter une division  par 0. */

  printf("\nL'inverse du nombre saisi est %f", 1/x);
}

