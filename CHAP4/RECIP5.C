/* recip5 calcule par une boucle while l'inverse d'un nombre quelconque.
   Le passage actuel dans la boucle est interrompu par une instruction
   " continue " si on entre la valeur 0. Ensuite, on peut saisir une nouvelle
                                                                      valeur. */

#include <stdio.h>                                      /* pour printf, scanf */
#include <conio.h>                                             /* pour getche */

main()
{
  float x;                                                   /* valeur saisie */
  char reply = 'o';                         /* variable de boucle initialis‚e */

  while (reply == 'o')
    {
     printf("\033[2J");
     printf("Calcul de l'inverse des nombres non nuls.\n");
     printf("Votre nombre : ");
     scanf("%f", &x);
     if (!x)                                                  /* si x vaut 0  */
         continue;                   /* stoppe le passage en cours pour empˆcher
                                                           une division par 0 */
     printf("\nL'inverse du nombre saisi est %f", 1/x);
     printf("\nAutre calcul ? (o/n)");
     reply = getche();                  /* variable de contr“le r‚initialis‚e */
  }                                                           /* fin du while */
}                                                              /* fin du main */

