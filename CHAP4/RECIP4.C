/* recip4 calcule avec une boucle while l'inverse d'un nombre quelconque.
   La boucle est interrompue par l'instruction break si on entre la valeur 0. */

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
         if (!x)                                               /* si x vaut 0 */
            {
         printf("Division par z‚ro interdite.");
             break;     /* interruption de la boucle afin d'empˆcher la division
                                                                        par 0 */
            }
     printf("\nL'inverse du nombre entr‚ est %f", 1/x);
         printf("\nAutre calcul ? (o/n)");
     reply = getche();           /* r‚initialisation de la variable de boucle */
        }                                                     /* fin du while */

  if (x) /* si x diff,rent de 0 */
     printf("\n\nLe programme a fini normalement.");
  else
     printf("\n\nLe programme a fini … cause d'une erreur de saisie.");
}                                                              /* fin du main */

