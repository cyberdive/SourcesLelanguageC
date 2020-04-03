/* Swtchcal montre comment r‚aliser une alternative … 5 branches via un switch*/

#include <stdio.h>                                      /* pour printf, scanf */
#include <stdlib.h>                                              /* pour exit */
#include <conio.h>                                             /* pour getche */

main()
{
  float x, y;                                              /* valeurs saisies */
  char selection;                                     /* choix de l'op‚ration */
  printf("\033[2J");
  printf("Le programme calcule au choix la somme, la diff‚rence, le produit\n");
  printf("ou le quotient de deux nombres. Entrez les deux nombres :\n");
  scanf("%f %f", &x, &y);
  printf("\nQuelle op‚ration d‚sirez-vous ?\n\n");
  printf("\t\ta\tpour\tAddition\n");
  printf("\t\ts\tpour\tSoustraction\n");
  printf("\t\tm\tpour\tMultiplication\n");
  printf("\t\td\tpour\tDivision\n\n");
  printf("Votre choix : ");
  selection = getche();        /* getche et non getchar ou scanf, pour sauter le
                          <<Entr‚e>> r‚sultant du " scanf " qui se trouve encore
                                                    dans le tampon de lecture */

  /*          V‚rification de la saisie et affichage du r‚sultat :            */
  switch (selection)                                    /* quelle op‚ration ? */
{
  case 'a':
  case 'A':     printf("\n\nLa somme des nombres est : %f", x+y);
     break;

  case 's':     
  case 'S':     printf("\n\nLa diff‚rence des nombres est : %f", x-y);
     break;
  case 'm':
  case 'M':     printf("\n\nLe produit des nombres est : %f", x*y);
     break;
  case 'd':
  case 'D':     if (y == 0)
                   {
                   printf("\n\nDivision par z‚ro. Sortie du programme.");
                   exit(1);
                   }
                else
                    printf("\n\nLe quotient des nombres est : %f", x/y);
                break;
  default:     printf("\n\nSaisie erron‚e.");
}
}

