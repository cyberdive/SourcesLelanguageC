/*  RECIP6 calcule, via une boucle while, l'inverse de nombres quelconques.
    La boucle est interrompue par une routine d'erreur, ‚crite sous forme de
    macro, lorsqu'on entre la valeur 0. On peut ensuite saisir une nouvelle
							       valeur.     */

#include <stdio.h>                                /*     printf, scanf     */
#include <conio.h>                                       /*     getche     */


/***     Macro de gestion d'erreur     ****/

#define ERRORHANDLER  { printf("\n\nDivision par 0 interdite.\
<Entr‚e> pour continuer."); getch(); continue; }

main()
{
     float x;                                     /*     valeur saisie     */
     char reply = 'o';                           /*     variable de boucle */
     while (reply == 'o')
     {
      printf("\033[2J");
      printf("Calcul de l'inverse d'un nombre non nul 0.\n");
      printf("Votre nombre : ");
      scanf("%f", &x);
      if (!x)                                  /*     si x est ‚gal … 0     */
       ERRORHANDLER           /* Macro : interrompt la boucle pour ‚viter une
							division par 0     */
       printf("\nL'inverse de la valeur saisie est %f", 1/x);
       printf("\nAutre calcul ? (o/n)");
       reply = getche();
     }                                                /*     fin while     */
}                                                      /*     fin main     */

